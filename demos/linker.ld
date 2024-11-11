
/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright © 2019 Keith Packard
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* modifications by Khalil Estell to make Near point work */

__flash = 0x08000000;
__flash_size = 64K;
__ram = 0x20000000;
__ram_size = 10K;
__stack_size = 1K;

ENTRY(_start)

/*
 * These values should be provided by the application. We'll include
 * some phony values here to make things link for testing
 */

MEMORY
{
  flash : ORIGIN = __flash, LENGTH = __flash_size
  ram : ORIGIN = __ram, LENGTH = __ram_size
}

ENTRY(_start)

PHDRS
{
  text PT_LOAD FLAGS(5);
  ram PT_LOAD FLAGS(6);
  ram_init PT_LOAD FLAGS(6);
  tls PT_TLS FLAGS(6);
}

SECTIONS
{
  .init : {
    PROVIDE(__stack = ORIGIN(ram) + LENGTH(ram));
    LONG (__stack);
    LONG (_start + 1);
    KEEP (*(.text.init.enter))
    KEEP (*(.data.init.enter))
    KEEP (*(SORT_BY_NAME(.init) SORT_BY_NAME(.init.*)))
  } >flash AT>flash :text

  .text : {
    /* code */
    KEEP(*(.text._ZN3hal7stm32f116configure_clocksENS0_10clock_treeE))
    KEEP(*(.text._ZN2ke12unwind_frameERKNS_14instructions_tERNS_12cortex_m_cpuE))
    KEEP(*(.text.__gnu_unwind_execute))
    KEEP(*(.text._Unwind_VRS_Pop))
    KEEP(*(.text._ZN2ke14enter_functionERNS_16exception_objectE))
    KEEP(*(.text._ZN2ke15raise_exceptionERNS_16exception_objectE))
    KEEP(*(.text.__aeabi_frsub))
    KEEP(*(.text.__aeabi_fmul))
    KEEP(*(.text.__aeabi_fsub))
    KEEP(*(.text.__addsf3))
    KEEP(*(.text._ZN2ke15parse_call_siteILNS_13lsda_encodingE9EEENS_14call_site_infoEPPKhmS4_))
    KEEP(*(.text.__aeabi_fdiv))
    KEEP(*(.text._Z11applicationR13resource_list))
    KEEP(*(.text._ZN3hal7stm32f19frequencyENS0_10peripheralE))
    KEEP(*(.text._ZN2ke14action_decoder19get_next_catch_typeEv))
    KEEP(*(.text.__malloc_malloc))
    KEEP(*(.text.aligned_alloc))
    KEEP(*(.text.__aeabi_ul2f))
    KEEP(*(.text._ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE))
    KEEP(*(.text.__gnu_Unwind_Backtrace))
    KEEP(*(.text.__aeabi_l2f))
    KEEP(*(.text._ZN2ke12parse_headerEPPKh))
    KEEP(*(.text.free))
    KEEP(*(.text._ZN2ke15parse_call_siteILNS_13lsda_encodingE10EEENS_14call_site_infoEPPKhmS4_))
    KEEP(*(.text._ZN2ke15parse_call_siteILNS_13lsda_encodingE12EEENS_14call_site_infoEPPKhmS4_))
    KEEP(*(.text._ZN2ke15parse_call_siteILNS_13lsda_encodingE4EEENS_14call_site_infoEPPKhmS4_))
    KEEP(*(.text.__gesf2))
    KEEP(*(.text._Z14funct_group6_9v))
    KEEP(*(.text._ZN2ke15parse_call_siteILNS_13lsda_encodingE11EEENS_14call_site_infoEPPKhmS4_))
    KEEP(*(.text._ZN2ke15parse_call_siteILNS_13lsda_encodingE3EEENS_14call_site_infoEPPKhmS4_))
    KEEP(*(.text._ZN2ke15parse_call_siteILNS_13lsda_encodingE2EEENS_14call_site_infoEPPKhmS4_))
    KEEP(*(.text._ZN2ke15skip_dwarf_infoEPPKh))
    KEEP(*(.text.__gnu_Unwind_RaiseException))
    KEEP(*(.text.__ltsf2))
    KEEP(*(.text._Z14funct_group0_5v))
    KEEP(*(.text._Z14funct_group5_5v))
    KEEP(*(.text._Z15funct_group1_11v))
    KEEP(*(.text._Z15funct_group2_23v))
    KEEP(*(.text._Z15funct_group3_47v))
    KEEP(*(.text._Z15funct_group4_95v))
    KEEP(*(.text._Z15funct_group6_11v))
    KEEP(*(.text._Z19initialize_platformv))
    KEEP(*(.text.__cmpsf2))
    KEEP(*(.text.raise))
    KEEP(*(.text.__libc_init_array))
    KEEP(*(.text._Z14funct_group0_4v))
    KEEP(*(.text._ZnwjSt11align_val_t))
    KEEP(*(.text._on_exit))
    KEEP(*(.text.__malloc_sbrk_aligned))
    KEEP(*(.text.__wrap___cxa_throw))
    KEEP(*(.text._ZN2ke18multi_read_uleb128ILj4EEENS_17decoded_uleb128_tIXT_EEEPKh))
    KEEP(*(.text._ZN2ke23parse_uleb128_call_siteEPKhmS1_))
    KEEP(*(.text._ZSt13__upper_boundIN9__gnu_cxx17__normal_iteratorIPKN2ke13index_entry_tESt4spanIS4_Lj4294967295EEEEmNS0_5__ops14_Val_comp_iterINS2_15index_less_thanEEEET_SD_SD_RKT0_T1_))
    KEEP(*(.text._GLOBAL__sub_I__ZNSt3pmr15memory_resourceD2Ev))
    KEEP(*(.text._ZN2ke7to_lsdaERNS_16exception_objectE))
    KEEP(*(.text._ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE))
    KEEP(*(.text._ZN7class_07triggerEv))
    KEEP(*(.text._ZN7class_0C1El))
    KEEP(*(.text._ZN7class_17triggerEv))
    KEEP(*(.text._ZN7class_1C2El))
    KEEP(*(.text.__gnu_Unwind_Resume))
    KEEP(*(.text.__malloc_grow_chunk))
    KEEP(*(.text.__wrap___cxa_rethrow))
    KEEP(*(.text.sbrk))
    KEEP(*(.text._Z14funct_group0_0v))
    KEEP(*(.text._Z14funct_group0_1v))
    KEEP(*(.text._Z14funct_group0_2v))
    KEEP(*(.text._Z14funct_group0_3v))
    KEEP(*(.text._Z14funct_group1_0v))
    KEEP(*(.text._Z14funct_group1_1v))
    KEEP(*(.text._Z14funct_group1_2v))
    KEEP(*(.text._Z14funct_group1_3v))
    KEEP(*(.text._Z14funct_group1_4v))
    KEEP(*(.text._Z14funct_group1_5v))
    KEEP(*(.text._Z14funct_group1_6v))
    KEEP(*(.text._Z14funct_group1_7v))
    KEEP(*(.text._Z14funct_group1_8v))
    KEEP(*(.text._Z14funct_group1_9v))
    KEEP(*(.text._Z14funct_group2_0v))
    KEEP(*(.text._Z14funct_group2_1v))
    KEEP(*(.text._Z14funct_group2_2v))
    KEEP(*(.text._Z14funct_group2_3v))
    KEEP(*(.text._Z14funct_group2_4v))
    KEEP(*(.text._Z14funct_group2_5v))
    KEEP(*(.text._Z14funct_group2_6v))
    KEEP(*(.text._Z14funct_group2_7v))
    KEEP(*(.text._Z14funct_group2_8v))
    KEEP(*(.text._Z14funct_group2_9v))
    KEEP(*(.text._Z14funct_group3_0v))
    KEEP(*(.text._Z14funct_group3_1v))
    KEEP(*(.text._Z14funct_group3_2v))
    KEEP(*(.text._Z14funct_group3_3v))
    KEEP(*(.text._Z14funct_group3_4v))
    KEEP(*(.text._Z14funct_group3_5v))
    KEEP(*(.text._Z14funct_group3_6v))
    KEEP(*(.text._Z14funct_group3_7v))
    KEEP(*(.text._Z14funct_group3_8v))
    KEEP(*(.text._Z14funct_group3_9v))
    KEEP(*(.text._Z14funct_group4_0v))
    KEEP(*(.text._Z14funct_group4_1v))
    KEEP(*(.text._Z14funct_group4_2v))
    KEEP(*(.text._Z14funct_group4_3v))
    KEEP(*(.text._Z14funct_group4_4v))
    KEEP(*(.text._Z14funct_group4_5v))
    KEEP(*(.text._Z14funct_group4_6v))
    KEEP(*(.text._Z14funct_group4_7v))
    KEEP(*(.text._Z14funct_group4_8v))
    KEEP(*(.text._Z14funct_group4_9v))
    KEEP(*(.text._Z14funct_group5_0v))
    KEEP(*(.text._Z14funct_group5_1v))
    KEEP(*(.text._Z14funct_group5_2v))
    KEEP(*(.text._Z14funct_group5_3v))
    KEEP(*(.text._Z14funct_group5_4v))
    KEEP(*(.text._Z14funct_group6_0v))
    KEEP(*(.text._Z14funct_group6_1v))
    KEEP(*(.text._Z14funct_group6_2v))
    KEEP(*(.text._Z14funct_group6_3v))
    KEEP(*(.text._Z14funct_group6_4v))
    KEEP(*(.text._Z14funct_group6_5v))
    KEEP(*(.text._Z14funct_group6_6v))
    KEEP(*(.text._Z14funct_group6_7v))
    KEEP(*(.text._Z14funct_group6_8v))
    KEEP(*(.text._Z15funct_group1_10v))
    KEEP(*(.text._Z15funct_group2_10v))
    KEEP(*(.text._Z15funct_group2_11v))
    KEEP(*(.text._Z15funct_group2_12v))
    KEEP(*(.text._Z15funct_group2_13v))
    KEEP(*(.text._Z15funct_group2_14v))
    KEEP(*(.text._Z15funct_group2_15v))
    KEEP(*(.text._Z15funct_group2_16v))
    KEEP(*(.text._Z15funct_group2_17v))
    KEEP(*(.text._Z15funct_group2_18v))
    KEEP(*(.text._Z15funct_group2_19v))
    KEEP(*(.text._Z15funct_group2_20v))
    KEEP(*(.text._Z15funct_group2_21v))
    KEEP(*(.text._Z15funct_group2_22v))
    KEEP(*(.text._Z15funct_group3_10v))
    KEEP(*(.text._Z15funct_group3_11v))
    KEEP(*(.text._Z15funct_group3_12v))
    KEEP(*(.text._Z15funct_group3_13v))
    KEEP(*(.text._Z15funct_group3_14v))
    KEEP(*(.text._Z15funct_group3_15v))
    KEEP(*(.text._Z15funct_group3_16v))
    KEEP(*(.text._Z15funct_group3_17v))
    KEEP(*(.text._Z15funct_group3_18v))
    KEEP(*(.text._Z15funct_group3_19v))
    KEEP(*(.text._Z15funct_group3_20v))
    KEEP(*(.text._Z15funct_group3_21v))
    KEEP(*(.text._Z15funct_group3_22v))
    KEEP(*(.text._Z15funct_group3_23v))
    KEEP(*(.text._Z15funct_group3_24v))
    KEEP(*(.text._Z15funct_group3_25v))
    KEEP(*(.text._Z15funct_group3_26v))
    KEEP(*(.text._Z15funct_group3_27v))
    KEEP(*(.text._Z15funct_group3_28v))
    KEEP(*(.text._Z15funct_group3_29v))
    KEEP(*(.text._Z15funct_group3_30v))
    KEEP(*(.text._Z15funct_group3_31v))
    KEEP(*(.text._Z15funct_group3_32v))
    KEEP(*(.text._Z15funct_group3_33v))
    KEEP(*(.text._Z15funct_group3_34v))
    KEEP(*(.text._Z15funct_group3_35v))
    KEEP(*(.text._Z15funct_group3_36v))
    KEEP(*(.text._Z15funct_group3_37v))
    KEEP(*(.text._Z15funct_group3_38v))
    KEEP(*(.text._Z15funct_group3_39v))
    KEEP(*(.text._Z15funct_group3_40v))
    KEEP(*(.text._Z15funct_group3_41v))
    KEEP(*(.text._Z15funct_group3_42v))
    KEEP(*(.text._Z15funct_group3_43v))
    KEEP(*(.text._Z15funct_group3_44v))
    KEEP(*(.text._Z15funct_group3_45v))
    KEEP(*(.text._Z15funct_group3_46v))
    KEEP(*(.text._Z15funct_group4_10v))
    KEEP(*(.text._Z15funct_group4_11v))
    KEEP(*(.text._Z15funct_group4_12v))
    KEEP(*(.text._Z15funct_group4_13v))
    KEEP(*(.text._Z15funct_group4_14v))
    KEEP(*(.text._Z15funct_group4_15v))
    KEEP(*(.text._Z15funct_group4_16v))
    KEEP(*(.text._Z15funct_group4_17v))
    KEEP(*(.text._Z15funct_group4_18v))
    KEEP(*(.text._Z15funct_group4_19v))
    KEEP(*(.text._Z15funct_group4_20v))
    KEEP(*(.text._Z15funct_group4_21v))
    KEEP(*(.text._Z15funct_group4_22v))
    KEEP(*(.text._Z15funct_group4_23v))
    KEEP(*(.text._Z15funct_group4_24v))
    KEEP(*(.text._Z15funct_group4_25v))
    KEEP(*(.text._Z15funct_group4_26v))
    KEEP(*(.text._Z15funct_group4_27v))
    KEEP(*(.text._Z15funct_group4_28v))
    KEEP(*(.text._Z15funct_group4_29v))
    KEEP(*(.text._Z15funct_group4_30v))
    KEEP(*(.text._Z15funct_group4_31v))
    KEEP(*(.text._Z15funct_group4_32v))
    KEEP(*(.text._Z15funct_group4_33v))
    KEEP(*(.text._Z15funct_group4_34v))
    KEEP(*(.text._Z15funct_group4_35v))
    KEEP(*(.text._Z15funct_group4_36v))
    KEEP(*(.text._Z15funct_group4_37v))
    KEEP(*(.text._Z15funct_group4_38v))
    KEEP(*(.text._Z15funct_group4_39v))
    KEEP(*(.text._Z15funct_group4_40v))
    KEEP(*(.text._Z15funct_group4_41v))
    KEEP(*(.text._Z15funct_group4_42v))
    KEEP(*(.text._Z15funct_group4_43v))
    KEEP(*(.text._Z15funct_group4_44v))
    KEEP(*(.text._Z15funct_group4_45v))
    KEEP(*(.text._Z15funct_group4_46v))
    KEEP(*(.text._Z15funct_group4_47v))
    KEEP(*(.text._Z15funct_group4_48v))
    KEEP(*(.text._Z15funct_group4_49v))
    KEEP(*(.text._Z15funct_group4_50v))
    KEEP(*(.text._Z15funct_group4_51v))
    KEEP(*(.text._Z15funct_group4_52v))
    KEEP(*(.text._Z15funct_group4_53v))
    KEEP(*(.text._Z15funct_group4_54v))
    KEEP(*(.text._Z15funct_group4_55v))
    KEEP(*(.text._Z15funct_group4_56v))
    KEEP(*(.text._Z15funct_group4_57v))
    KEEP(*(.text._Z15funct_group4_58v))
    KEEP(*(.text._Z15funct_group4_59v))
    KEEP(*(.text._Z15funct_group4_60v))
    KEEP(*(.text._Z15funct_group4_61v))
    KEEP(*(.text._Z15funct_group4_62v))
    KEEP(*(.text._Z15funct_group4_63v))
    KEEP(*(.text._Z15funct_group4_64v))
    KEEP(*(.text._Z15funct_group4_65v))
    KEEP(*(.text._Z15funct_group4_66v))
    KEEP(*(.text._Z15funct_group4_67v))
    KEEP(*(.text._Z15funct_group4_68v))
    KEEP(*(.text._Z15funct_group4_69v))
    KEEP(*(.text._Z15funct_group4_70v))
    KEEP(*(.text._Z15funct_group4_71v))
    KEEP(*(.text._Z15funct_group4_72v))
    KEEP(*(.text._Z15funct_group4_73v))
    KEEP(*(.text._Z15funct_group4_74v))
    KEEP(*(.text._Z15funct_group4_75v))
    KEEP(*(.text._Z15funct_group4_76v))
    KEEP(*(.text._Z15funct_group4_77v))
    KEEP(*(.text._Z15funct_group4_78v))
    KEEP(*(.text._Z15funct_group4_79v))
    KEEP(*(.text._Z15funct_group4_80v))
    KEEP(*(.text._Z15funct_group4_81v))
    KEEP(*(.text._Z15funct_group4_82v))
    KEEP(*(.text._Z15funct_group4_83v))
    KEEP(*(.text._Z15funct_group4_84v))
    KEEP(*(.text._Z15funct_group4_85v))
    KEEP(*(.text._Z15funct_group4_86v))
    KEEP(*(.text._Z15funct_group4_87v))
    KEEP(*(.text._Z15funct_group4_88v))
    KEEP(*(.text._Z15funct_group4_89v))
    KEEP(*(.text._Z15funct_group4_90v))
    KEEP(*(.text._Z15funct_group4_91v))
    KEEP(*(.text._Z15funct_group4_92v))
    KEEP(*(.text._Z15funct_group4_93v))
    KEEP(*(.text._Z15funct_group4_94v))
    KEEP(*(.text._Z15funct_group6_10v))
    KEEP(*(.text._ZN3hal8cortex_m11dwt_counterC2Ef))
    KEEP(*(.text._ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_))
    KEEP(*(.text.__cxa_guard_acquire))
    KEEP(*(.text._start))
    KEEP(*(.text._ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv))
    KEEP(*(.text._Unwind_VRS_Get))
    KEEP(*(.text._Unwind_VRS_Set))
    KEEP(*(.text._Z41__static_initialization_and_destruction_0ii))
    KEEP(*(.text._ZNKSt9type_infoeqERKS_))
    KEEP(*(.text._ZTVN10__cxxabiv117__class_type_infoE))
    KEEP(*(.text._ZTVN10__cxxabiv120__si_class_type_infoE))
    KEEP(*(.text._ZN2ke15get_index_entryEm))
    KEEP(*(.text._ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj))
    KEEP(*(.text._ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE))
    KEEP(*(.text._ZN2ke14action_decoder33get_current_type_info_from_filterEv))
    KEEP(*(.text._ZN3hal7stm32f139maximum_speed_using_internal_oscillatorEv))
    KEEP(*(.text.__popcountsi2))
    KEEP(*(.text._ZTSNSt3pmr12_GLOBAL__N_112newdel_res_tE))
    KEEP(*(.text._ZTSN10__cxxabiv120__si_class_type_infoE))
    KEEP(*(.text._ZTSNSt3pmr12_GLOBAL__N_110null_res_tE))
    KEEP(*(.text.__floatunsisf))
    KEEP(*(.text.__wrap___cxa_free_exception))
    KEEP(*(.text._Unwind_ForcedUnwind))
    KEEP(*(.text._Unwind_RaiseException))
    KEEP(*(.text._Unwind_Resume))
    KEEP(*(.text._ZTSN10__cxxabiv117__class_type_infoE))
    KEEP(*(.text.___Unwind_Backtrace))
    KEEP(*(.text.___Unwind_Resume_or_Rethrow))
    KEEP(*(.text.main))
    KEEP(*(.text._ZN3hal26single_exception_allocatorILj256EED0Ev))
    KEEP(*(.text._ZN3hal8cortex_m11dwt_counter13driver_uptimeEv))
    KEEP(*(.text._ZN3hal8cortex_m11dwt_counterD0Ev))
    KEEP(*(.text._ZSt17__throw_bad_allocv))
    KEEP(*(.text.__wrap___cxa_end_catch))
    KEEP(*(.text._ZN2ke18pop_register_rangeILj1ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE))
    KEEP(*(.text._ZN2ke18pop_register_rangeILj2ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE))
    KEEP(*(.text._ZN2ke18pop_register_rangeILj3ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE))
    KEEP(*(.text._ZN2ke18pop_register_rangeILj4ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE))
    KEEP(*(.text._ZN2ke18pop_register_rangeILj5ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE))
    KEEP(*(.text._ZN2ke18pop_register_rangeILj6ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE))
    KEEP(*(.text._ZN2ke18pop_register_rangeILj7ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE))
    KEEP(*(.text._ZN3hal26single_exception_allocatorILj256EE11do_allocateEjj))
    KEEP(*(.text._ZN10__cxxabiv117__class_type_infoD0Ev))
    KEEP(*(.text._ZN10__cxxabiv120__si_class_type_infoD0Ev))
    KEEP(*(.text._ZN9__gnu_cxx20recursive_init_errorD0Ev))
    KEEP(*(.text._ZNSt9bad_allocD0Ev))
    KEEP(*(.text._ZTVNSt3pmr12_GLOBAL__N_110null_res_tE))
    KEEP(*(.text._ZTVNSt3pmr12_GLOBAL__N_112newdel_res_tE))
    KEEP(*(.text.__aeabi_memcpy8))
    KEEP(*(.text.__floatsisf))
    KEEP(*(.text._ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE))
    KEEP(*(.text._ZTSNSt3pmr15memory_resourceE))
    KEEP(*(.text._GLOBAL__sub_I___cxa_get_globals_fast))
    KEEP(*(.text._ZN2ke23get_arm_exception_indexEv))
    KEEP(*(.text.__aeabi_cfrcmple))
    KEEP(*(.text.__wrap___cxa_end_cleanup))
    KEEP(*(.text.restore_core_regs))
    KEEP(*(.text.__gnu_Unwind_ForcedUnwind))
    KEEP(*(.text.__gnu_Unwind_Resume_or_Rethrow))
    KEEP(*(.text.__wrap___cxa_allocate_exception))
    KEEP(*(.text._ZN10__cxxabiv117__class_type_infoD1Ev))
    KEEP(*(.text._ZN10__cxxabiv117__class_type_infoD2Ev))
    KEEP(*(.text._ZN10__cxxabiv120__si_class_type_infoD1Ev))
    KEEP(*(.text._ZN3hal13set_terminateEPFvvE))
    KEEP(*(.text._ZN3hal26single_exception_allocatorILj256EE13do_deallocateEPvjj))
    KEEP(*(.text._ZN3hal26single_exception_allocatorILj256EED2Ev))
    KEEP(*(.text._ZN3hal8cortex_m11dwt_counterD2Ev))
    KEEP(*(.text._ZN9__gnu_cxx20recursive_init_errorD2Ev))
    KEEP(*(.text._ZNSt9bad_allocD1Ev))
    KEEP(*(.text._ZSt9terminatev))
    KEEP(*(.text.strcmp))
    KEEP(*(.text._ZN2ke15index_less_thanclEmRKNS_13index_entry_tE))
    KEEP(*(.text._ZSt9__fill_a1IhEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_))
    KEEP(*(.text.__aeabi_fcmpeq))
    KEEP(*(.text.__aeabi_fcmpge))
    KEEP(*(.text.__aeabi_fcmpgt))
    KEEP(*(.text.__aeabi_fcmple))
    KEEP(*(.text.__aeabi_fcmplt))
    KEEP(*(.text._ZN10__cxxabiv111__terminateEPFvvE))
    KEEP(*(.text._ZSt15get_new_handlerv))
    KEEP(*(.text.__aeabi_cfcmpeq))
    KEEP(*(.text.memset))
    KEEP(*(.text._GLOBAL__sub_I__ZN10__cxxabiv119__terminate_handlerE))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_tD0Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_tD0Ev))
    KEEP(*(.text._ZNSt9exceptionD0Ev))
    KEEP(*(.text.abort))
    KEEP(*(.text._ZTSSt9type_info))
    KEEP(*(.text._ZN2ke17current_exceptionEv))
    KEEP(*(.text._ZN3hal13get_terminateEv))
    KEEP(*(.text._ZN3hal23get_exception_allocatorEv))
    KEEP(*(.text._ZN3hal23set_exception_allocatorEPNSt3pmr15memory_resourceE))
    KEEP(*(.text._ZN9__gnu_cxx20recursive_init_errorC1Ev))
    KEEP(*(.text._ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_))
    KEEP(*(.text._ZTIN10__cxxabiv117__class_type_infoE))
    KEEP(*(.text._ZTIN10__cxxabiv120__si_class_type_infoE))
    KEEP(*(.text._ZTINSt3pmr12_GLOBAL__N_110null_res_tE))
    KEEP(*(.text._ZTINSt3pmr12_GLOBAL__N_112newdel_res_tE))
    KEEP(*(.text._ZNK3hal26single_exception_allocatorILj256EE11do_is_equalERKNSt3pmr15memory_resourceE))
    KEEP(*(.text._ZNKSt3pmr12_GLOBAL__N_110null_res_t11do_is_equalERKNS_15memory_resourceE))
    KEEP(*(.text._ZNKSt3pmr12_GLOBAL__N_112newdel_res_t11do_is_equalERKNS_15memory_resourceE))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_t13do_deallocateEPvjj))
    KEEP(*(.text._ZSt9__advanceIN9__gnu_cxx17__normal_iteratorIPKN2ke13index_entry_tESt4spanIS4_Lj4294967295EEEEiEvRT_T0_St26random_access_iterator_tag))
    KEEP(*(.text.__aeabi_atexit))
    KEEP(*(.text.__cxa_atexit))
    KEEP(*(.text._ZNKSt9bad_alloc4whatEv))
    KEEP(*(.text._ZNKSt9exception4whatEv))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_t11do_allocateEjj))
    KEEP(*(.text._ZTINSt3pmr15memory_resourceE))
    KEEP(*(.text._ZTISt9type_info))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t11do_allocateEjj))
    KEEP(*(.text._ZdlPvjSt11align_val_t))
    KEEP(*(.text.__aeabi_unwind_cpp_pr0))
    KEEP(*(.text.__aeabi_unwind_cpp_pr1))
    KEEP(*(.text.__aeabi_unwind_cpp_pr2))
    KEEP(*(.text.__cxa_guard_abort))
    KEEP(*(.text.__cxa_guard_release))
    KEEP(*(.text.__wrap___cxa_call_unexpected))
    KEEP(*(.text._exit))
    KEEP(*(.text._ZN3hal8cortex_m11dwt_counter16driver_frequencyEv))
    KEEP(*(.text._ZN3hal8cortex_m11dwt_counter22register_cpu_frequencyEf))
    KEEP(*(.text._ZNKSt9type_info14__is_pointer_pEv))
    KEEP(*(.text._ZNKSt9type_info15__is_function_pEv))
    KEEP(*(.text._ZdlPv))
    KEEP(*(.text._ZdlPvSt11align_val_t))
    KEEP(*(.text._ZdlPvj))
    KEEP(*(.text.__wrap___cxa_begin_catch))
    KEEP(*(.text._Z17terminate_handlerv))
    KEEP(*(.text._ZN10__cxxabiv119__terminate_handlerMUlvE_4_FUNEv))
    KEEP(*(.text._ZN12_GLOBAL__N_113constant_initD1Ev))
    KEEP(*(.text._ZN12_GLOBAL__N_113constant_initD2Ev))
    KEEP(*(.text._ZN2ke2asIPKjEEPKT_PKv))
    KEEP(*(.text._ZN2ke2asIlEEPKT_PKv))
    KEEP(*(.text._ZN2ke2asImEEPKT_PKv))
    KEEP(*(.text._ZN2ke2asIsEEPKT_PKv))
    KEEP(*(.text._ZN2ke2asItEEPKT_PKv))
    KEEP(*(.text._ZN2ke2asIxEEPKT_PKv))
    KEEP(*(.text._ZN2ke2asIyEEPKT_PKv))
    KEEP(*(.text._ZN2ke6get_luEPv))
    KEEP(*(.text._ZN2ke8get_su16EPv))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t13do_deallocateEPvjj))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_tD1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_tD2Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_tD1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_tD2Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_10null_res_tEED1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_10null_res_tEED2Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_12newdel_res_tEED1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_12newdel_res_tEED2Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initISt6atomicIPNS_15memory_resourceEEED1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initISt6atomicIPNS_15memory_resourceEEED2Ev))
    KEEP(*(.text._ZNSt3pmr15memory_resourceD1Ev))
    KEEP(*(.text._ZNSt3pmr15memory_resourceD2Ev))
    KEEP(*(.text._ZNSt9exceptionD1Ev))
    KEEP(*(.text._ZNSt9type_infoD2Ev))
    KEEP(*(.text.__retarget_lock_acquire_recursive))
    KEEP(*(.text.__retarget_lock_release_recursive))
    KEEP(*(.text.__wrap___aeabi_unwind_cpp_pr0))
    KEEP(*(.text.__wrap___gnu_unwind_pr_common))
    KEEP(*(.text.__wrap___gxx_personality_v0))
    KEEP(*(.text.__wrap__sig_func))
    KEEP(*(.text.__wrap_deregister_tm_clones))
    KEEP(*(.text.__wrap_register_tm_clones))
    KEEP(*(.text.arm_halt_isr))
    KEEP(*(.text.arm_ignore_isr))
    KEEP(*(.text.arm_nmi_isr))
    KEEP(*(.text.arm_usagefault_isr))
    KEEP(*(.text._GLOBAL__sub_I__ZN10__cxxabiv119__terminate_handlerE))
    KEEP(*(.text._GLOBAL__sub_I__ZNSt3pmr15memory_resourceD2Ev))
    KEEP(*(.text._GLOBAL__sub_I___cxa_get_globals_fast))
    KEEP(*(.text._Unwind_DebugHook))
    KEEP(*(.text._Unwind_GetGR))
    KEEP(*(.text._Unwind_SetGR))
    KEEP(*(.text._Unwind_decode_typeinfo_ptr.constprop.0))
    KEEP(*(.text._Z41__static_initialization_and_destruction_0ii))
    KEEP(*(.text._ZN10__cxxabiv121__vmi_class_type_infoD0Ev))
    KEEP(*(.text._ZN10__cxxabiv121__vmi_class_type_infoD2Ev))
    KEEP(*(.text._ZN12_GLOBAL__N_113constant_initD1Ev))
    KEEP(*(.text._ZN2ke12flatten_rttiILj12EEEvPvRNS_19flattened_hierarchyIXT_EEEPKSt9type_info))
    KEEP(*(.text._ZN2ke13get_rtti_typeEPKv))
    KEEP(*(.text._ZN2ke13push_vmi_infoILj12EEEvPvRNS_20base_class_type_infoERNS_19flattened_hierarchyIXT_EEE))
    KEEP(*(.text._ZN2ke19flattened_hierarchyILj12EE9push_backERKNS_20base_class_type_infoE))
    KEEP(*(.text._ZN2ke22extract_si_parent_infoEPKv))
    KEEP(*(.text._ZN2ke2asIKhEEPKT_PKv))
    KEEP(*(.text._ZN2ke2asIPKiEEPKT_PKv))
    KEEP(*(.text._ZNK10__cxxabiv121__vmi_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE))
    KEEP(*(.text._ZNK10__cxxabiv121__vmi_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE))
    KEEP(*(.text._ZNK10__cxxabiv121__vmi_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_))
    KEEP(*(.text._ZNKSt3pmr12_GLOBAL__N_110null_res_t11do_is_equalERKNS_15memory_resourceE))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t11do_allocateEjj))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t13do_deallocateEPvjj))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_tD0Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_110null_res_tD1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_t11do_allocateEjj))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_t13do_deallocateEPvjj))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_tD0Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_tD1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_10null_res_tEED1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_12newdel_res_tEED1Ev))
    KEEP(*(.text._ZNSt3pmr12_GLOBAL__N_113constant_initISt6atomicIPNS_15memory_resourceEEED1Ev))
    KEEP(*(.text._ZSt7find_ifIPN2ke20base_class_type_infoEZNS0_14enter_functionERNS0_16exception_objectEEUlRKT_E_ES5_S5_S5_T0_))
    KEEP(*(.text._ZSt9__find_ifIPN2ke20base_class_type_infoEN9__gnu_cxx5__ops10_Iter_predIZNS0_14enter_functionERNS0_16exception_objectEEUlRKT_E_EEES8_S8_S8_T0_St26random_access_iterator_tag))
    KEEP(*(.text.__do_global_dtors_aux))
    KEEP(*(.text.__do_global_dtors_aux))
    KEEP(*(.text.__do_global_dtors_aux_fini_array_entry))
    KEEP(*(.text.__frame_dummy_init_array_entry))
    KEEP(*(.text.__gnu_Unwind_Restore_VFP))
    KEEP(*(.text.__gnu_Unwind_Restore_VFP_D))
    KEEP(*(.text.__gnu_Unwind_Restore_VFP_D_16_to_31))
    KEEP(*(.text.__gnu_Unwind_Restore_WMMXC))
    KEEP(*(.text.__gnu_Unwind_Restore_WMMXD))
    KEEP(*(.text.__gnu_Unwind_Save_VFP))
    KEEP(*(.text.__gnu_Unwind_Save_VFP_D))
    KEEP(*(.text.__gnu_Unwind_Save_VFP_D_16_to_31))
    KEEP(*(.text.__gnu_Unwind_Save_WMMXC))
    KEEP(*(.text.__gnu_Unwind_Save_WMMXD))
    KEEP(*(.text.__gnu_unwind_get_pr_addr))
    KEEP(*(.text.__gnu_unwind_pr_common))
    KEEP(*(.text.__init_array_end))
    KEEP(*(.text.__init_array_start))
    KEEP(*(.text.__preinit_array_end))
    KEEP(*(.text.__preinit_array_start))
    KEEP(*(.text.__text_end))
    KEEP(*(.text.deregister_tm_clones))
    KEEP(*(.text.deregister_tm_clones))
    KEEP(*(.text.frame_dummy))
    KEEP(*(.text.frame_dummy))
    KEEP(*(.text.get_eit_entry))
    KEEP(*(.text.next_unwind_byte))
    KEEP(*(.text.register_tm_clones))
    KEEP(*(.text.register_tm_clones))
    KEEP(*(.text.restore_non_core_regs))
    KEEP(*(.text.search_EIT_table))
    KEEP(*(.text.selfrel_offset31))
    KEEP(*(.text.unwind_phase2))
    KEEP(*(.text.unwind_phase2_forced))

    *(.text.unlikely .text.unlikely.*)
    *(.text.startup .text.startup.*)
    *(.text .text.*)
    *(.gnu.linkonce.t.*)
    KEEP (*(.fini))
    __text_end = .;

    PROVIDE (__etext = __text_end);
    PROVIDE (_etext = __text_end);
    PROVIDE (etext = __text_end);

    /* read-only data */
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)

    *(.srodata.cst16)
    *(.srodata.cst8)
    *(.srodata.cst4)
    *(.srodata.cst2)
    *(.srodata .srodata.*)
    *(.data.rel.ro .data.rel.ro.*)
    *(.got .got.*)

    /* Need to pre-align so that the symbols come after padding */
    . = ALIGN(8);

    /* lists of constructors and destructors */
    PROVIDE_HIDDEN ( __preinit_array_start = . );
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN ( __preinit_array_end = . );

    PROVIDE_HIDDEN ( __init_array_start = . );
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array .ctors))
    PROVIDE_HIDDEN ( __init_array_end = . );

    PROVIDE_HIDDEN ( __fini_array_start = . );
    KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
    KEEP (*(.fini_array .dtors))
    PROVIDE_HIDDEN ( __fini_array_end = . );
  } >flash AT>flash :text

  /* additional sections when compiling with C++ exception support */

  .except : {
    *(.gcc_except_table *.gcc_except_table.*)
    KEEP (*(.eh_frame .eh_frame.*))
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    . = ALIGN(8);
  } >flash AT>flash :text

  .except2 : {
    PROVIDE(__exidx_start = .);
    *(.ARM.exidx*)
    PROVIDE(__exidx_end = .);
  } >flash AT>flash :text

  /*
   * Data values which are preserved across reset
   */
  .preserve (NOLOAD) : {
    PROVIDE(__preserve_start__ = .);
    KEEP(*(SORT_BY_NAME(.preserve.*)))
    KEEP(*(.preserve))
    PROVIDE(__preserve_end__ = .);
  } >ram AT>ram :ram

  .data : ALIGN_WITH_INPUT {
    *(.data .data.*)
    *(.gnu.linkonce.d.*)

    /* Need to pre-align so that the symbols come after padding */
     . = ALIGN(8);

    PROVIDE( __global_pointer$ = . + 0x800 );
    *(.sdata .sdata.* .sdata2.*)
    *(.gnu.linkonce.s.*)
  } >ram AT>flash :ram_init

  PROVIDE(__data_start = ADDR(.data));
  PROVIDE(__data_start__ = ADDR(.data));
  PROVIDE(__data_source = LOADADDR(.data));

  /* Thread local initialized data. This gets
   * space allocated as it is expected to be placed
   * in ram to be used as a template for TLS data blocks
   * allocated at runtime. We're slightly abusing that
   * by placing the data in flash where it will be copied
   * into the allocate ram addresses by the existing
   * data initialization code in crt0
   */
  .tdata : ALIGN_WITH_INPUT {
    *(.tdata .tdata.* .gnu.linkonce.td.*)
    PROVIDE(__data_end = .);
  } >ram AT>flash :tls :ram_init

  PROVIDE( __tls_base = ADDR(.tdata));
  PROVIDE( __tdata_source = LOADADDR(.tdata) );
  PROVIDE( __tdata_size = SIZEOF(.tdata) );

  PROVIDE( __edata = __data_end );
  PROVIDE( _edata = __data_end );
  PROVIDE( edata = __data_end );
  PROVIDE( __data_end__ = _data_end );
  PROVIDE( __data_size = __data_end - __data_start );

  .tbss (NOLOAD) : {
    *(.tbss .tbss.* .gnu.linkonce.tb.*)
    *(.tcommon)
    PROVIDE( __tls_end = . );
  } >ram AT>ram :tls :ram

  PROVIDE(__bss_start = ADDR(.tbss));
  PROVIDE(__bss_start__  = ADDR(.tbss));
  PROVIDE( __tbss_size = SIZEOF(.tbss) );
  PROVIDE( __tls_size = __tls_end - __tls_base );

  /*
   * The linker special cases .tbss segments which are
   * identified as segments which are not loaded and are
   * thread_local.
   *
   * For these segments, the linker does not advance 'dot'
   * across them.  We actually need memory allocated for tbss,
   * so we create a special segment here just to make room
   */
  .tbss_space (NOLOAD) : {
    . = . + __tbss_size;
  } >ram AT>ram :ram

  .bss (NOLOAD) : {
    *(.sbss*)
    *(.gnu.linkonce.sb.*)
    *(.bss .bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)

    /* Align the heap */
    . = ALIGN(8);
    __bss_end = .;
    __bss_end__  = .;
  } >ram AT>ram :ram
  PROVIDE( __end = __bss_end );
  PROVIDE( _end = __bss_end );
  PROVIDE( end = __bss_end );
  PROVIDE( __bss_size = __bss_end - __bss_start );

  /* Make the rest of memory available for heap storage */
  PROVIDE(__heap_start = __end);
  PROVIDE(__heap_end = __stack - (DEFINED(__stack_size) ? __stack_size : 0x800));
  PROVIDE(__heap_size = __heap_end - __heap_start);

  /* Define a stack region to make sure it fits in memory */
  .stack (NOLOAD) : {
    . += (DEFINED(__stack_size) ? __stack_size : 0x800);
  } >ram :ram
}
