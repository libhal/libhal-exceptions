#include <unwind.h>

#include <algorithm>
#include <bit>
#include <cstdint>
#include <cstdlib>
#include <span>

/* Misc constants.  */
#define R_IP 12
#define R_SP 13
#define R_LR 14
#define R_PC 15

struct core_regs
{
  std::uint32_t r[16];
};

/* We use normal integer types here to avoid the compiler generating
   coprocessor instructions.  */
struct vfp_regs
{
  std::uint64_t d[16];
  std::uint32_t pad;
};

struct vfpv3_regs
{
  /* Always populated via VSTM, so no need for the "pad" field from
     vfp_regs (which is used to store the format word for FSTMX).  */
  std::uint64_t d[16];
};

struct wmmxd_regs
{
  std::uint64_t wd[16];
};

struct wmmxc_regs
{
  std::uint32_t wc[4];
};

/* The ABI specifies that the unwind routines may only use core registers,
   except when actually manipulating coprocessor state.  This allows
   us to write one implementation that works on all platforms by
   demand-saving coprocessor registers.

   During unwinding we hold the coprocessor state in the actual hardware
   registers and allocate demand-save areas for use during phase1
   unwinding.  */

struct phase1_vrs
{
  /* The first fields must be the same as a phase2_vrs.  */
  std::uint32_t demand_save_flags;
  struct core_regs core;
  std::uint32_t prev_sp; /* Only valid during forced unwinding.  */
  struct vfp_regs vfp;
  struct vfpv3_regs vfp_regs_16_to_31;
  struct wmmxd_regs wmmxd;
  struct wmmxc_regs wmmxc;
};

/* This must match the structure created by the assembly wrappers.  */
struct phase2_vrs
{
  std::uint32_t demand_save_flags;
  struct core_regs core;
};

typedef struct __EIT_entry
{
  std::uint32_t fnoffset;
  std::uint32_t content;
} __EIT_entry;

std::uint32_t selfrel_offset31(std::uint32_t const* p)
{
  std::uint32_t offset;

  offset = *p;
  /* Sign extend to 32 bits.  */
  if (offset & (1 << 30))
    offset |= 1u << 31;
  else
    offset &= ~(1u << 31);

  return offset + (std::uint32_t)p;
}

struct eit_entry_less_than
{
  [[gnu::always_inline]] static std::uint32_t to_absolute(
    __EIT_entry const& entry)
  {
    auto entry_addr = reinterpret_cast<std::uint32_t>(&entry.content);
    // Sign extend :D
    entry_addr <<= 1;
    entry_addr >>= 1;
    return entry_addr;
  }

  bool operator()(__EIT_entry const& left, __EIT_entry const& right)
  {
    return left.fnoffset < right.fnoffset;
  }
  bool operator()(__EIT_entry const& left, std::uint32_t right)
  {
    std::uint32_t absolute_left = to_absolute(left);
    return absolute_left < right;
  }
  bool operator()(std::uint32_t left, __EIT_entry const& right)
  {
    std::uint32_t absolute_right = to_absolute(right);
    return left < absolute_right;
  }
};

/* Return the next byte of unwinding information, or CODE_FINISH if there is
   no data remaining.  */
[[gnu::always_inline]] _uw8 next_unwind_byte(__gnu_unwind_state* uws)
{
  _uw8 b;

  if (uws->bytes_left == 0) {
    /* Load another word */
    if (uws->words_left == 0)
      return 0xB0; /* Nothing left.  */
    uws->words_left--;
    uws->data = *(uws->next++);
    uws->bytes_left = 3;
  } else
    uws->bytes_left--;

  /* Extract the most significant byte.  */
  b = (uws->data >> 24) & 0xff;
  uws->data <<= 8;
  return b;
}

[[gnu::always_inline]] _Unwind_VRS_Result _My_Unwind_VRS_Get(
  _Unwind_Context* context,
  _Unwind_VRS_RegClass,
  _uw regno,
  _Unwind_VRS_DataRepresentation,
  void* valuep)
{
  auto* vrs = reinterpret_cast<phase1_vrs*>(context);
  *(_uw*)valuep = vrs->core.r[regno];
  return _UVRSR_OK;
}

/* ABI defined function to load a virtual register from memory.  */

[[gnu::always_inline]] _Unwind_VRS_Result _My_Unwind_VRS_Set(
  _Unwind_Context* context,
  _Unwind_VRS_RegClass,
  _uw regno,
  _Unwind_VRS_DataRepresentation,
  void* valuep)
{
  auto* vrs = reinterpret_cast<phase1_vrs*>(context);
  vrs->core.r[regno] = *(_uw*)valuep;
  return _UVRSR_OK;
}

extern "C"
{

  [[gnu::always_inline]] _Unwind_VRS_Result __wrap__Unwind_VRS_Pop(
    _Unwind_Context* context,
    _Unwind_VRS_RegClass regclass,
    _uw discriminator,
    _Unwind_VRS_DataRepresentation)
  {
    auto* vrs = reinterpret_cast<phase1_vrs*>(context);

    switch (regclass) {
      case _UVRSC_CORE: {
        std::uint32_t mask = discriminator & 0xffff;
        // The mask may not demand that the stack pointer be popped, but the
        // stack pointer will still need to be popped anyway, so this check
        // determines if the mask handles this or not.
        bool set_stack_pointer_afterwards = (mask & R_SP) == 0x0;

        std::uint32_t* ptr =  // NOTLINTNEXTLINE
          reinterpret_cast<std::uint32_t*>(vrs->core.r[R_SP]);
        /* Pop the requested registers.  */
        while (mask) {
          auto reg_to_restore = std::countr_zero(mask);
          mask &= ~(1 << reg_to_restore);
          vrs->core.r[reg_to_restore] = *(ptr++);
        }
        if (set_stack_pointer_afterwards) {
          vrs->core.r[R_SP] = reinterpret_cast<std::uint32_t>(ptr);
        }
      }
        return _UVRSR_OK;
      case _UVRSC_VFP:
        return _UVRSR_OK;
      case _UVRSC_WMMXD:
        return _UVRSR_OK;
      case _UVRSC_WMMXC:
        return _UVRSR_OK;
      default:
        return _UVRSR_FAILED;
    }
  }

  /* Execute the unwinding instructions described by UWS.  */
  _Unwind_Reason_Code __wrap___gnu_unwind_execute(_Unwind_Context* context,
                                                  __gnu_unwind_state* uws)
  {
    _uw op;
    int set_pc;
    _uw reg;
    set_pc = 0;
    for (;;) {
      op = next_unwind_byte(uws);
      if (op == 0xb0) {
        /* If we haven't already set pc then copy it from lr.  */
        if (!set_pc) {
          _My_Unwind_VRS_Get(context, _UVRSC_CORE, R_LR, _UVRSD_UINT32, &reg);
          _My_Unwind_VRS_Set(context, _UVRSC_CORE, R_PC, _UVRSD_UINT32, &reg);
          set_pc = 1;
        }
        /* Drop out of the loop.  */
        break;
      }
      if ((op & 0x80) == 0) {
        /* vsp = vsp +- (imm6 << 2 + 4).  */
        _uw offset;

        offset = ((op & 0x3f) << 2) + 4;
        _My_Unwind_VRS_Get(context, _UVRSC_CORE, R_SP, _UVRSD_UINT32, &reg);
        if (op & 0x40)
          reg -= offset;
        else
          reg += offset;
        _My_Unwind_VRS_Set(context, _UVRSC_CORE, R_SP, _UVRSD_UINT32, &reg);
        continue;
      }

      if ((op & 0xf0) == 0x80) {
        op = (op << 8) | next_unwind_byte(uws);
        if (op == 0x8000) {
          /* Refuse to unwind.  */
          return _URC_FAILURE;
        }
        /* Pop r4-r15 under mask.  */
        op = (op << 4) & 0xfff0;
        if (_Unwind_VRS_Pop(context, _UVRSC_CORE, op, _UVRSD_UINT32) !=
            _UVRSR_OK)
          return _URC_FAILURE;
        if (op & (1 << R_PC))
          set_pc = 1;
        continue;
      }
      if ((op & 0xf0) == 0x90) {
        op &= 0xf;
        if (op == 13 || op == 15)
          /* Reserved.  */
          return _URC_FAILURE;
        /* vsp = r[nnnn].  */
        _My_Unwind_VRS_Get(context, _UVRSC_CORE, op, _UVRSD_UINT32, &reg);
        _My_Unwind_VRS_Set(context, _UVRSC_CORE, R_SP, _UVRSD_UINT32, &reg);
        continue;
      }
      if ((op & 0xf0) == 0xa0) {
        /* Pop r4-r[4+nnn], [lr].  */
        _uw mask;

        mask = (0xff0 >> (7 - (op & 7))) & 0xff0;
        if (op & 8)
          mask |= (1 << R_LR);
        if (_Unwind_VRS_Pop(context, _UVRSC_CORE, mask, _UVRSD_UINT32) !=
            _UVRSR_OK)
          return _URC_FAILURE;
        continue;
      }
      if ((op & 0xf0) == 0xb0) {
        /* op == 0xb0 already handled.  */
        if (op == 0xb1) {
          op = next_unwind_byte(uws);
          if (op == 0 || ((op & 0xf0) != 0))
            /* Spare.  */
            return _URC_FAILURE;
          /* Pop r0-r4 under mask.  */
          if (_Unwind_VRS_Pop(context, _UVRSC_CORE, op, _UVRSD_UINT32) !=
              _UVRSR_OK)
            return _URC_FAILURE;
          continue;
        }
        if (op == 0xb2) {
          /* vsp = vsp + 0x204 + (uleb128 << 2).  */
          int shift;

          _My_Unwind_VRS_Get(context, _UVRSC_CORE, R_SP, _UVRSD_UINT32, &reg);
          op = next_unwind_byte(uws);
          shift = 2;
          while (op & 0x80) {
            reg += ((op & 0x7f) << shift);
            shift += 7;
            op = next_unwind_byte(uws);
          }
          reg += ((op & 0x7f) << shift) + 0x204;
          _My_Unwind_VRS_Set(context, _UVRSC_CORE, R_SP, _UVRSD_UINT32, &reg);
          continue;
        }
        if (op == 0xb3) {
          /* Pop VFP registers with fldmx.  */
          op = next_unwind_byte(uws);
          op = ((op & 0xf0) << 12) | ((op & 0xf) + 1);
          if (_Unwind_VRS_Pop(context, _UVRSC_VFP, op, _UVRSD_VFPX) !=
              _UVRSR_OK)
            return _URC_FAILURE;
          continue;
        }
        if ((op & 0xfc) == 0xb4) /* Obsolete FPA.  */
          return _URC_FAILURE;

        /* op & 0xf8 == 0xb8.  */
        /* Pop VFP D[8]-D[8+nnn] with fldmx.  */
        op = 0x80000 | ((op & 7) + 1);
        if (_Unwind_VRS_Pop(context, _UVRSC_VFP, op, _UVRSD_VFPX) != _UVRSR_OK)
          return _URC_FAILURE;
        continue;
      }
      if ((op & 0xf0) == 0xc0) {
        if (op == 0xc6) {
          /* Pop iWMMXt D registers.  */
          op = next_unwind_byte(uws);
          op = ((op & 0xf0) << 12) | ((op & 0xf) + 1);
          if (_Unwind_VRS_Pop(context, _UVRSC_WMMXD, op, _UVRSD_UINT64) !=
              _UVRSR_OK)
            return _URC_FAILURE;
          continue;
        }
        if (op == 0xc7) {
          op = next_unwind_byte(uws);
          if (op == 0 || (op & 0xf0) != 0)
            /* Spare.  */
            return _URC_FAILURE;
          /* Pop iWMMXt wCGR{3,2,1,0} under mask.  */
          if (_Unwind_VRS_Pop(context, _UVRSC_WMMXC, op, _UVRSD_UINT32) !=
              _UVRSR_OK)
            return _URC_FAILURE;
          continue;
        }
        if ((op & 0xf8) == 0xc0) {
          /* Pop iWMMXt wR[10]-wR[10+nnn].  */
          op = 0xa0000 | ((op & 0xf) + 1);
          if (_Unwind_VRS_Pop(context, _UVRSC_WMMXD, op, _UVRSD_UINT64) !=
              _UVRSR_OK)
            return _URC_FAILURE;
          continue;
        }
        if (op == 0xc8) {
          /* Pop VFPv3 registers D[16+ssss]-D[16+ssss+cccc] with vldm.  */
          op = next_unwind_byte(uws);
          op = (((op & 0xf0) + 16) << 12) | ((op & 0xf) + 1);
          if (_Unwind_VRS_Pop(context, _UVRSC_VFP, op, _UVRSD_DOUBLE) !=
              _UVRSR_OK)
            return _URC_FAILURE;
          continue;
        }
        if (op == 0xc9) {
          /* Pop VFP registers with fldmd.  */
          op = next_unwind_byte(uws);
          op = ((op & 0xf0) << 12) | ((op & 0xf) + 1);
          if (_Unwind_VRS_Pop(context, _UVRSC_VFP, op, _UVRSD_DOUBLE) !=
              _UVRSR_OK)
            return _URC_FAILURE;
          continue;
        }
        /* Spare.  */
        return _URC_FAILURE;
      }
      if ((op & 0xf8) == 0xd0) {
        /* Pop VFP D[8]-D[8+nnn] with fldmd.  */
        op = 0x80000 | ((op & 7) + 1);
        if (_Unwind_VRS_Pop(context, _UVRSC_VFP, op, _UVRSD_DOUBLE) !=
            _UVRSR_OK)
          return _URC_FAILURE;
        continue;
      }
      /* Spare.  */
      return _URC_FAILURE;
    }
    return _URC_OK;
  }

  _Unwind_Reason_Code __wrap___gnu_unwind_frame(_Unwind_Control_Block* ucbp,
                                                _Unwind_Context* context)
  {
    _uw* ptr;
    __gnu_unwind_state uws;

    ptr = (_uw*)ucbp->pr_cache.ehtp;
    /* Skip over the personality routine address.  */
    ptr++;
    /* Setup the unwinder state.  */
    uws.data = (*ptr) << 8;
    uws.next = ptr + 1;
    uws.bytes_left = 3;
    uws.words_left = ((*ptr) >> 24) & 0xff;

    return __wrap___gnu_unwind_execute(context, &uws);
  }

  __EIT_entry const* search_EIT_table(__EIT_entry const* table,
                                      int nrec,  // NOLINT
                                      std::uint32_t return_address)
  {
    if (nrec == 0) {
      return nullptr;
    }
    std::span<__EIT_entry const> table_span(table, nrec);
    auto const& entry = std::upper_bound(table_span.begin(),
                                         table_span.end(),
                                         return_address,
                                         eit_entry_less_than{});
    return entry.base();
  }
}
