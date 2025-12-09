SECTIONS {
  .text.sorted : {
    /* LEAF & unsortable functions below */
    /* Unwind info 0x00000001 */
    *(.text.unlikely._Z3endv)
    *(.text.unlikely._exit)
    *(.text.unlikely.__wrap___cxa_call_unexpected)
    *(.text.unlikely._ZSt9terminatev)
    *(.text.unlikely._Unwind_GetDataRelBase)
    *(.text.unlikely._Unwind_GetTextRelBase)
    *(.text.unlikely.abort)
    *(.text.startup._ZN2ke5cacheIFvPvPSt9type_infoPFvS1_EEEENS_14instructions_tEPT_)
    *(.text.startup._sub_I_65535_0.0)
    *(.text.startup._GLOBAL__sub_I__ZNSt3pmr15memory_resourceD2Ev)
    *(.text.startup._GLOBAL__sub_I__ZSt20__throw_system_errori)
    *(.text._start)
    *(.text.deregister_tm_clones)
    *(.text.register_tm_clones)
    *(.text.__do_global_dtors_aux)
    *(.text.frame_dummy)
    *(.text._ZN10__cxxabiv119__terminate_handlerMUlvE_4_FUNEv)
    *(.text._ZN3hal26single_exception_allocator11do_allocateEjj)
    *(.text._ZNK3hal26single_exception_allocator11do_is_equalERKNSt3pmr15memory_resourceE)
    *(.text._ZZ19initialize_platformvENUlvE_4_FUNEv)
    *(.text._ZN3hal7stm32f112gpio_manager6outputD2Ev)
    *(.text._ZN3hal8cortex_m11dwt_counterD2Ev)
    *(.text._ZNK28single_block_memory_resourceILj256EE11do_is_equalERKNSt3pmr15memory_resourceE)
    *(.text._ZN3hal8cortex_m11dwt_counter13driver_uptimeEv)
    *(.text._ZN3hal8cortex_m11dwt_counter16driver_frequencyEv)
    *(.text._ZN3hal7stm32f14uart12driver_writeESt4spanIKhLj4294967295EE)
    *(.text._ZN3hal7stm32f14uart11driver_readESt4spanIhLj4294967295EE)
    *(.text._ZN3hal7stm32f14uart12driver_flushEv)
    *(.text._Z5pausev)
    *(.text._ZN2ke12unwind_frameERKNS_14instructions_tERNS_12cortex_m_cpuE)
    *(.text._ZN3hal26single_exception_allocator13do_deallocateEPvjj)
    *(.text._ZN28single_block_memory_resourceILj256EE11do_allocateEjj)
    *(.text._ZN3hal26single_exception_allocatorD2Ev.lto_priv.0)
    *(.text._ZN28single_block_memory_resourceILj256EED2Ev.lto_priv.0)
    *(.text._ZN3hal26single_exception_allocatorD0Ev)
    *(.text._ZN3hal7stm32f112gpio_manager6outputD0Ev)
    *(.text._ZN3hal8cortex_m11dwt_counterD0Ev)
    *(.text._ZN28single_block_memory_resourceILj256EED0Ev)
    *(.text._ZN28single_block_memory_resourceILj256EE13do_deallocateEPvjj)
    *(.text._ZN3hal7stm32f14uart16driver_configureERKNS_6serial8settingsE)
    *(.text._ZN2ke16capture_cpu_coreERNS_12cortex_m_cpuE)
    *(.text._ZN2ke16restore_cpu_coreERNS_12cortex_m_cpuE)
    *(.text._ZN2ke15raise_exceptionERNS_23exception_control_blockE.constprop.0)
    *(.text.__wrap___cxa_free_exception)
    *(.text.__wrap___cxa_end_catch)
    *(.text.__wrap___cxa_begin_catch)
    *(.text.__wrap___cxa_end_cleanup)
    *(.text.__wrap__Unwind_Resume)
    *(.text.__wrap___aeabi_unwind_cpp_pr0)
    *(.text.__wrap___aeabi_unwind_cpp_pr1)
    *(.text.__wrap___gxx_personality_v0)
    *(.text._Z5startv)
    *(.text.__aeabi_atexit)
    *(.text._ZNKSt9bad_alloc4whatEv)
    *(.text._ZNSt9bad_allocD2Ev)
    *(.text._ZNSt9bad_allocD0Ev)
    *(.text._ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_)
    *(.text._ZN10__cxxabiv117__class_type_infoD2Ev)
    *(.text._ZN10__cxxabiv117__class_type_infoD0Ev)
    *(.text._ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE)
    *(.text._ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE)
    *(.text._ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj)
    *(.text._ZdlPvj)
    *(.text._ZNSt9exceptionD2Ev)
    *(.text._ZN10__cxxabiv120__si_class_type_infoD2Ev)
    *(.text._ZN10__cxxabiv120__si_class_type_infoD0Ev)
    *(.text._ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_)
    *(.text._ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE)
    *(.text._ZNSt9type_infoD2Ev)
    *(.text._ZNKSt9type_info14__is_pointer_pEv)
    *(.text._ZNKSt9type_infoeqERKS_)
    *(.text._ZN10__cxxabiv121__vmi_class_type_infoD2Ev)
    *(.text._ZN10__cxxabiv121__vmi_class_type_infoD0Ev)
    *(.text._ZN9__gnu_cxx15__concat_size_tEPcjj)
    *(.text._ZNKSt3pmr12_GLOBAL__N_112newdel_res_t11do_is_equalERKNS_15memory_resourceE)
    *(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t13do_deallocateEPvjj)
    *(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_tD2Ev)
    *(.text._ZNSt3pmr12_GLOBAL__N_110null_res_tD2Ev)
    *(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_12newdel_res_tEED2Ev)
    *(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_10null_res_tEED2Ev)
    *(.text._ZNSt3pmr12_GLOBAL__N_113constant_initINS0_14atomic_mem_resEED2Ev)
    *(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_tD0Ev)
    *(.text._ZNSt3pmr12_GLOBAL__N_110null_res_tD0Ev)
    *(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_t13do_deallocateEPvjj)
    *(.text._ZNSt3pmr12_GLOBAL__N_112newdel_res_t11do_allocateEjj)
    *(.text._ZNSt3pmr15memory_resourceD2Ev)
    *(.text._ZdlPv)
    *(.text._ZdlPvjSt11align_val_t)
    *(.text._ZNKSt11logic_error4whatEv)
    *(.text._ZNSt11logic_errorD2Ev)
    *(.text._ZNSt12length_errorD2Ev)
    *(.text._ZNSt12out_of_rangeD2Ev)
    *(.text._ZNSt11logic_errorD0Ev)
    *(.text._ZNSt12length_errorD0Ev)
    *(.text._ZNSt12out_of_rangeD0Ev)
    *(.text._ZNSs4_Rep10_M_destroyERKSaIcE)
    *(.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv)
    *(.text._ZNK12_GLOBAL__N_122generic_error_category4nameEv)
    *(.text._ZNK12_GLOBAL__N_122generic_error_category10equivalentEiRKSt15error_condition)
    *(.text._ZN12_GLOBAL__N_122generic_error_categoryD2Ev)
    *(.text._ZNK12_GLOBAL__N_121system_error_category4nameEv)
    *(.text._ZNK12_GLOBAL__N_121system_error_category23default_error_conditionEi)
    *(.text._ZN12_GLOBAL__N_121system_error_categoryD2Ev)
    *(.text._ZNKSt3_V214error_category23default_error_conditionEi)
    *(.text._ZNKSt3_V214error_category10equivalentERKSt10error_codei)
    *(.text._ZN12_GLOBAL__N_113constant_initINS_22generic_error_categoryEED2Ev)
    *(.text._ZN12_GLOBAL__N_113constant_initINS_21system_error_categoryEED2Ev)
    *(.text._ZN12_GLOBAL__N_122generic_error_categoryD0Ev)
    *(.text._ZN12_GLOBAL__N_121system_error_categoryD0Ev)
    *(.text._ZNK12_GLOBAL__N_121system_error_category10equivalentEiRKSt15error_condition)
    *(.text._ZdlPvSt11align_val_t)
    *(.text._ZSt15get_new_handlerv)
    *_arm_addsubdf3.o(.text*)
    *_arm_muldivdf3.o(.text*)
    *_arm_fixunsdfsi.o(.text*)
    *_arm_addsubsf3.o(.text*)
    *_arm_fixunssfsi.o(.text*)
    *_arm_muldivsf3.o(.text*)
    *_arm_cmpsf2.o(.text*)
    *_arm_unordsf2.o(.text*)
    *_aeabi_ldivmod.o(.text*)
    *(.text.__fixsfdi)
    *(.text.__fixunssfdi)
    *(.text.read_uleb128)
    *(.text.read_sleb128)
    *(.text.base_of_encoded_value)
    *(.text.read_encoded_value_with_base)
    *(.text.selfrel_offset31)
    *(.text.search_EIT_table)
    *(.text.__gnu_unwind_get_pr_addr)
    *(.text._Unwind_decode_typeinfo_ptr.constprop.0)
    *(.text._Unwind_DebugHook)
    *(.text.__gnu_Unwind_ForcedUnwind)
    *(.text._Unwind_VRS_Get)
    *(.text._Unwind_GetGR)
    *(.text._Unwind_VRS_Set)
    *(.text._Unwind_SetGR)
    *(.text.__aeabi_unwind_cpp_pr0)
    *(.text.__aeabi_unwind_cpp_pr1)
    *(.text.__aeabi_unwind_cpp_pr2)
    *libunwind.o(.text*)
    *(.text.next_unwind_byte)
    *(.text.unwind_UCB_from_context)
    *strcmp.S.o(.text*)
    *(.text.memcpy)
    *(.text.memset)
    *strlen.S.o(.text*)
    *(.text.free)
    *(.text.__malloc_sbrk_aligned)
    *(.text.__malloc_grow_chunk)
    *(.text.malloc)
    *(.text.memalign)
    *(.text.__libc_init_array)
    *(.text.__retarget_lock_acquire_recursive)
    *(.text.__retarget_lock_release_recursive)
    *(.text.__cxa_atexit)
    *(.text.__call_exitprocs)
    *(.text._on_exit)
    *(.text.__xpg_strerror_r)
    *(.text.sbrk)
    *(.text.arm_halt_isr)
    *(.text.arm_ignore_isr)
    *(.text.roundf)
    *strcpy.S.o(.text*)
    *(.text.raise)
    *(.text._strerror_r)
    *(.text.__udivmoddi4)
    *_dvmd_tls.o(.text*)
    /* Unwind info 0x8004afb0 */
    *(.text.startup.main)
    /* Unwind info 0x8012afb0 */
    *(.text._ZNK10__cxxabiv121__vmi_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE)
    /* Unwind info 0x8008afb0 */
    *(.text._ZNK10__cxxabiv121__vmi_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE)
    *(.text.__gnu_unwind_pr_common)
    /* Unwind info 0x8004adb0 */
    *(.text.__gnu_unwind_execute)
    /* Unwind info 0x80033fac */
    *(.text._Unwind_VRS_Pop)
    /* Unwind info 0x8013a8b0 */
    *(.text._Z19depth_14_percent_25v.isra.0)
    *(.text._Z19depth_04_percent_75v.isra.0)
    *(.text._Z19depth_12_percent_75v.isra.0)
    *(.text._Z19depth_16_percent_75v.isra.0)
    *(.text._Z19depth_63_percent_75v.isra.0)
    *(.text._Z19depth_12_percent_50v.isra.0)
    *(.text._Z19depth_40_percent_50v.isra.0)
    *(.text._Z19depth_58_percent_50v.isra.0)
    *(.text._Z18depth_10_percent_0v.isra.0)
    *(.text._Z18depth_16_percent_0v.isra.0)
    *(.text._Z18depth_20_percent_0v.isra.0)
    *(.text._Z18depth_21_percent_0v.isra.0)
    *(.text._Z18depth_54_percent_0v.isra.0)
    *(.text._Z18depth_59_percent_0v.isra.0)
    *(.text._Z18depth_64_percent_0v.isra.0)
    /* Unwind info 0x8003a8b0 */
    *(.text._Z19depth_22_percent_25v.isra.0)
    *(.text._Z19depth_39_percent_25v.isra.0)
    *(.text._Z19depth_43_percent_25v.isra.0)
    *(.text._Z19depth_69_percent_25v.isra.0)
    *(.text._Z19depth_08_percent_75v.isra.0)
    *(.text._Z19depth_20_percent_75v.isra.0)
    *(.text._Z19depth_39_percent_75v.isra.0)
    *(.text._Z19depth_10_percent_50v.isra.0)
    *(.text._Z19depth_24_percent_50v.isra.0)
    *(.text._Z19depth_08_percent_25v.isra.0)
    *(.text._Z19depth_10_percent_25v.isra.0)
    *(.text._Z18depth_06_percent_0v.isra.0)
    *(.text._Z18depth_41_percent_0v.isra.0)
    *(.text._Z18depth_68_percent_0v.isra.0)
    *(.text._Unwind_SetGR)
    /* Unwind info 0x8009a8b0 */
    *(.text._Z19depth_41_percent_25v.isra.0)
    *(.text._Z19depth_70_percent_25v.isra.0)
    *(.text._Z19depth_28_percent_75v.isra.0)
    *(.text._Z19depth_51_percent_75v.isra.0)
    *(.text._Z19depth_06_percent_50v.isra.0)
    *(.text._Z19depth_54_percent_50v.isra.0)
    *(.text._Z18depth_01_percent_0v.isra.0)
    *(.text._Z18depth_28_percent_0v.isra.0)
    *(.text._Z18depth_55_percent_0v.isra.0)
    *(.text._Z18depth_58_percent_0v.isra.0)
    *(.text._Z18depth_60_percent_0v.isra.0)
    /* Unwind info 0x8007a8b0 */
    *(.text._Z19depth_19_percent_25v.isra.0)
    *(.text._Z19depth_30_percent_25v.isra.0)
    *(.text._Z19depth_34_percent_25v.isra.0)
    *(.text._Z19depth_36_percent_25v.isra.0)
    *(.text._Z19depth_49_percent_25v.isra.0)
    *(.text._Z19depth_56_percent_25v.isra.0)
    *(.text._Z19depth_67_percent_75v.isra.0)
    *(.text._Z19depth_64_percent_50v.isra.0)
    *(.text._Z19depth_07_percent_25v.isra.0)
    *(.text._Z18depth_19_percent_0v.isra.0)
    *(.text._Z18depth_22_percent_0v.isra.0)
    *(.text._Z18depth_49_percent_0v.isra.0)
    *(.text._Z18depth_53_percent_0v.isra.0)
    *(.text._Z18depth_57_percent_0v.isra.0)
    /* Unwind info 0x800da8b0 */
    *(.text._Z19depth_23_percent_25v.isra.0)
    *(.text._Z19depth_27_percent_25v.isra.0)
    *(.text._Z19depth_35_percent_25v.isra.0)
    *(.text._Z19depth_53_percent_25v.isra.0)
    *(.text._Z19depth_64_percent_25v.isra.0)
    *(.text._Z19depth_43_percent_75v.isra.0)
    *(.text._Z19depth_70_percent_75v.isra.0)
    *(.text._Z19depth_08_percent_50v.isra.0)
    *(.text._Z19depth_70_percent_50v.isra.0)
    *(.text._Z18depth_08_percent_0v.isra.0)
    *(.text._Z18depth_17_percent_0v.isra.0)
    *(.text._Z18depth_31_percent_0v.isra.0)
    *(.text._Z18depth_45_percent_0v.isra.0)
    *(.text._Z18depth_61_percent_0v.isra.0)
    /* Unwind info 0x801fa8b0 */
    *(.text._Z19depth_24_percent_25v.isra.0)
    *(.text._Z19depth_55_percent_25v.isra.0)
    *(.text._Z19depth_60_percent_25v.isra.0)
    *(.text._Z19depth_59_percent_75v.isra.0)
    *(.text._Z19depth_14_percent_50v.isra.0)
    *(.text._Z19depth_60_percent_50v.isra.0)
    *(.text._Z19depth_02_percent_25v.isra.0)
    *(.text._Z18depth_04_percent_0v.isra.0)
    *(.text._Z18depth_23_percent_0v.isra.0)
    *(.text._Z18depth_36_percent_0v.isra.0)
    *(.text._Z18depth_44_percent_0v.isra.0)
    *(.text._Z18depth_50_percent_0v.isra.0)
    *(.text._Z18depth_63_percent_0v.isra.0)
    *(.text._Z18depth_66_percent_0v.isra.0)
    /* Unwind info 0x8015a8b0 */
    *(.text._Z19depth_45_percent_25v.isra.0)
    *(.text._Z19depth_57_percent_25v.isra.0)
    *(.text._Z19depth_02_percent_50v.isra.0)
    *(.text._Z19depth_34_percent_50v.isra.0)
    *(.text._Z19depth_50_percent_50v.isra.0)
    *(.text._Z19depth_66_percent_50v.isra.0)
    *(.text._Z18depth_12_percent_0v.isra.0)
    *(.text._Z18depth_18_percent_0v.isra.0)
    *(.text._Z18depth_24_percent_0v.isra.0)
    *(.text._Z18depth_33_percent_0v.isra.0)
    *(.text._Z18depth_35_percent_0v.isra.0)
    *(.text._Z18depth_46_percent_0v.isra.0)
    *(.text._Z18depth_51_percent_0v.isra.0)
    /* Unwind info 0x8002a9b0 */
    *(.text._ZN3hal7stm32f113configure_pinENS0_10pin_selectENS0_12pin_config_tE)
    *(.text.get_eit_entry)
    /* Unwind info 0x8005a8b0 */
    *(.text._Z19depth_15_percent_25v.isra.0)
    *(.text._Z19depth_32_percent_25v.isra.0)
    *(.text._Z19depth_68_percent_25v.isra.0)
    *(.text._Z18depth_02_percent_0v.isra.0)
    *(.text._Z18depth_03_percent_0v.isra.0)
    *(.text._Z18depth_14_percent_0v.isra.0)
    *(.text._Z18depth_25_percent_0v.isra.0)
    *(.text._Z18depth_26_percent_0v.isra.0)
    *(.text._Z18depth_32_percent_0v.isra.0)
    *(.text._Z18depth_39_percent_0v.isra.0)
    *(.text._Z18depth_52_percent_0v.isra.0)
    /* Unwind info 0x800fa8b0 */
    *(.text._Z19depth_16_percent_25v.isra.0)
    *(.text._Z19depth_40_percent_25v.isra.0)
    *(.text._Z19depth_48_percent_25v.isra.0)
    *(.text._Z19depth_52_percent_25v.isra.0)
    *(.text._Z19depth_65_percent_25v.isra.0)
    *(.text._Z19depth_32_percent_50v.isra.0)
    *(.text._Z19depth_46_percent_50v.isra.0)
    *(.text._Z18depth_11_percent_0v.isra.0)
    *(.text._Z18depth_29_percent_0v.isra.0)
    *(.text._Z18depth_30_percent_0v.isra.0)
    *(.text._Z18depth_34_percent_0v.isra.0)
    /* Unwind info 0x8011a8b0 */
    *(.text._Z19depth_18_percent_25v.isra.0)
    *(.text._Z19depth_47_percent_75v.isra.0)
    *(.text._Z19depth_55_percent_75v.isra.0)
    *(.text._Z19depth_20_percent_50v.isra.0)
    *(.text._Z19depth_48_percent_50v.isra.0)
    *(.text._Z19depth_04_percent_25v.isra.0)
    *(.text._Z18depth_05_percent_0v.isra.0)
    *(.text._Z18depth_42_percent_0v.isra.0)
    *(.text._Z18depth_56_percent_0v.isra.0)
    *(.text._Z18depth_67_percent_0v.isra.0)
    /* Unwind info 0x8017a8b0 */
    *(.text._Z19depth_31_percent_25v.isra.0)
    *(.text._Z19depth_47_percent_25v.isra.0)
    *(.text._Z19depth_59_percent_25v.isra.0)
    *(.text._Z19depth_24_percent_75v.isra.0)
    *(.text._Z19depth_35_percent_75v.isra.0)
    *(.text._Z19depth_42_percent_50v.isra.0)
    *(.text._Z19depth_44_percent_50v.isra.0)
    *(.text._Z19depth_03_percent_25v.isra.0)
    *(.text._Z18depth_48_percent_0v.isra.0)
    *(.text._Z18depth_62_percent_0v.isra.0)
    /* Unwind info 0x8019a8b0 */
    *(.text._Z19depth_67_percent_25v.isra.0)
    *(.text._Z19depth_32_percent_75v.isra.0)
    *(.text._Z19depth_04_percent_50v.isra.0)
    *(.text._Z19depth_26_percent_50v.isra.0)
    *(.text._Z19depth_56_percent_50v.isra.0)
    *(.text._Z19depth_06_percent_25v.isra.0)
    *(.text._Z18depth_13_percent_0v.isra.0)
    *(.text._Z18depth_38_percent_0v.isra.0)
    *(.text._Z18depth_65_percent_0v.isra.0)
    *(.text._Z18depth_70_percent_0v.isra.0)
    /* Unwind info 0x8002afb0 */
    *(.text.__wrap___cxa_throw)
    *(.text._ZNK10__cxxabiv121__vmi_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_)
    /* Unwind info 0x801ba8b0 */
    *(.text._Z19depth_20_percent_25v.isra.0)
    *(.text._Z19depth_44_percent_25v.isra.0)
    *(.text._Z19depth_63_percent_25v.isra.0)
    *(.text._Z19depth_28_percent_50v.isra.0)
    *(.text._Z19depth_38_percent_50v.isra.0)
    *(.text._Z19depth_12_percent_25v.isra.0)
    *(.text._Z18depth_47_percent_0v.isra.0)
    *(.text._Z18depth_69_percent_0v.isra.0)
    /* Unwind info 0x801da8b0 */
    *(.text._Z19depth_61_percent_25v.isra.0)
    *(.text._Z19depth_18_percent_50v.isra.0)
    *(.text._Z19depth_22_percent_50v.isra.0)
    *(.text._Z19depth_30_percent_50v.isra.0)
    *(.text._Z19depth_52_percent_50v.isra.0)
    *(.text._Z18depth_15_percent_0v.isra.0)
    *(.text._Z18depth_27_percent_0v.isra.0)
    *(.text._Z18depth_43_percent_0v.isra.0)
    /* Unwind info 0x80a8b0b0 */
    *(.text.unlikely._ZN3hal7stm32f127throw_if_pin_is_unavailableENS0_10pin_selectE.part.0)
    *(.text.unlikely._ZN3hal7stm32f112_GLOBAL__N_124get_enable_register_infoENS0_10peripheralE.part.0)
    *(.text._ZNSt12length_errorC2EPKc)
    *(.text._ZNSt12out_of_rangeC2EPKc)
    *(.text._ZNSs4_Rep9_S_createEjjRKSaIcE)
    *(.text._Znwj)
    *(.text.restore_non_core_regs)
    /* Unwind info 0x80acb0b0 */
    *(.text._ZN3hal5delayERNS_12steady_clockENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE.constprop.0)
    *(.text._ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE)
    *(.text._ZN9__gnu_cxx15__snprintf_liteEPcjPKcSt9__va_list)
    /* Unwind info 0x8001a8b0 */
    *(.text._Z19depth_28_percent_25v.isra.0)
    *(.text._Z19depth_37_percent_25v.isra.0)
    *(.text._Z19depth_51_percent_25v.isra.0)
    *(.text._Z19depth_16_percent_50v.isra.0)
    *(.text._Z19depth_36_percent_50v.isra.0)
    *(.text._Z18depth_37_percent_0v.isra.0)
    *(.text._Z18depth_40_percent_0v.isra.0)
    /* Unwind info 0x80aab0b0 */
    *(.text._ZN3hal7stm32f112gpio_manager6output16driver_configureERKNS_10output_pin8settingsE)
    *(.text.read_encoded_value)
    *(.text.unwind_phase2)
    *(.text.__gnu_Unwind_Resume)
    /* Unwind info 0x800ba8b0 */
    *(.text._Z19depth_26_percent_25v.isra.0)
    *(.text._Z19depth_62_percent_50v.isra.0)
    *(.text._Z19depth_68_percent_50v.isra.0)
    *(.text._Z19depth_11_percent_25v.isra.0)
    *(.text._Z18depth_07_percent_0v.isra.0)
    *(.text._Z18depth_09_percent_0v.isra.0)
    /* Unwind info 0x7fffeafc */
    *(.text._Z34run_test_depth01_error4_cleanup_25v)
    *(.text._Z19depth_29_percent_25v.isra.0)
    *(.text._Z19depth_46_percent_25v.isra.0)
    *(.text._Z34run_test_depth50_error4_cleanup_25v)
    /* Unwind info 0x800cadb0 */
    *(.text.__gcc_personality_v0)
    /* Unwind info 0x7fffeaf4 */
    *(.text._Z20depth_01_percent_100v.isra.0)
    /* Unwind info 0x7fffef58 */
    *(.text._Z19depth_01_percent_75v.isra.0)
    /* Unwind info 0x7ffff254 */
    *(.text._Z19depth_01_percent_50v.isra.0)
    /* Unwind info 0x7ffff3fc */
    *(.text._Z19depth_01_percent_25v.isra.0)
    /* Unwind info 0x80b108a9 */
    *(.text.__wrap___cxa_rethrow)
    *(.text.__wrap___cxa_allocate_exception)
    *(.text._ZnwjSt11align_val_t)
    /* Unwind info 0x80b276af */
    *(.text.unwind_phase2_forced)
    /* Unwind info 0x7fffeb2c */
    *(.text._ZN3hal7stm32f14uartD2Ev)
    *(.text._Z19depth_13_percent_25v.isra.0)
    /* Unwind info 0x8001aab0 */
    *(.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEj)
    *(.text.parse_lsda_header)
    /* Unwind info 0x7fffeb30 */
    *(.text._ZN3hal7stm32f14uartD0Ev)
    /* Unwind info 0x7ffff198 */
    *(.text._ZNK12_GLOBAL__N_122generic_error_category7messageB5cxx11Ei)
    /* Unwind info 0x80b20fac */
    *(.text.__gnu_Unwind_Backtrace)
    /* Unwind info 0x7fffeb18 */
    *(.text._Z35run_test_depth01_error64_cleanup_25v)
    *(.text._Z35run_test_depth50_error64_cleanup_25v)
    /* Unwind info 0x7fffeb00 */
    *(.text._Z34run_test_depth30_error4_cleanup_25v)
    *(.text._Z35run_test_depth70_error64_cleanup_25v)
    /* Unwind info 0x7fffeb20 */
    *(.text._Z19depth_17_percent_25v.isra.0)
    *(.text._Z36run_test_depth01_error64_cleanup_100v)
    /* Unwind info 0x7fffeb1c */
    *(.text._Z35run_test_depth30_error64_cleanup_25v)
    *(.text._Z19depth_54_percent_25v.isra.0)
    /* Unwind info 0x7fffeb04 */
    *(.text._Z19depth_62_percent_25v.isra.0)
    *(.text._Z35run_test_depth01_error4_cleanup_100v)
    /* Unwind info 0x7fffeb14 */
    *(.text._Z19depth_21_percent_25v.isra.0)
    *(.text._Z19depth_38_percent_25v.isra.0)
    /* Unwind info 0x7fffeb08 */
    *(.text._Z19depth_25_percent_25v.isra.0)
    *(.text._Z19depth_42_percent_25v.isra.0)
    /* Unwind info 0x7ffff1bc */
    *(.text._ZNSt11logic_errorC2EPKc)
    /* Unwind info 0x8002abb0 */
    *(.text._ZNSt12__cow_stringC2EPKcj)
    /* Unwind info 0x803a3fab */
    *(.text.__gnu_Unwind_RaiseException)
    /* Unwind info 0x80048400 */
    *(.text._Unwind_GetGR.constprop.0)
    *(.text._Unwind_GetGR.constprop.0)
    *(.text.__gnu_unwind_frame)
    /* Unwind info 0x7ffff12c */
    *(.text._Z19depth_44_percent_75v.isra.0)
    *(.text.__gnu_Unwind_Resume_or_Rethrow)
    /* Unwind info 0x7fffff24 */
    *(.text.unlikely._ZSt24__throw_out_of_range_fmtPKcz)
    /* Unwind info 0x7ffff0e4 */
    *(.text._Z19depth_33_percent_75v.isra.0)
    *(.text._Unwind_GetLanguageSpecificData)
    /* Unwind info 0x7ffff1b4 */
    *(.text._Z19depth_54_percent_75v.isra.0)
    *(.text._ZN10__cxxabiv111__terminateEPFvvE)
    /* Unwind info 0x7ffff1ac */
    *(.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj)
    /* Unwind info 0x7ffff0e0 */
    *(.text._Z19depth_31_percent_75v.isra.0)
    *(.text._Unwind_GetRegionStart)
    /* Unwind info 0x80971cab */
    *(.text.unlikely._ZN9__gnu_cxx26__throw_insufficient_spaceEPKcS1_)
    /* Unwind info 0x7ffff1d0 */
    *(.text._Z19depth_58_percent_75v.isra.0)
    *(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t11do_allocateEjj)
    /* Unwind info 0x7fffe9b0 */
    *(.text._ZN3hal7stm32f18power_onENS0_10peripheralE)
    /* Unwind info 0x7fffe9ac */
    *(.text._Z33run_test_depth70_error4_cleanup_0v)
    /* Unwind info 0x7fffe9c8 */
    *(.text._Z34run_test_depth70_error64_cleanup_0v)
    /* Unwind info 0x7fffe9e4 */
    *(.text._Z33run_test_depth50_error4_cleanup_0v)
    /* Unwind info 0x7fffea00 */
    *(.text._Z34run_test_depth50_error64_cleanup_0v)
    /* Unwind info 0x7fffea1c */
    *(.text._Z33run_test_depth30_error4_cleanup_0v)
    /* Unwind info 0x7fffea38 */
    *(.text._Z34run_test_depth30_error64_cleanup_0v)
    /* Unwind info 0x7fffea54 */
    *(.text._Z33run_test_depth10_error4_cleanup_0v)
    /* Unwind info 0x7fffea70 */
    *(.text._Z34run_test_depth10_error64_cleanup_0v)
    /* Unwind info 0x7fffea8c */
    *(.text._Z33run_test_depth01_error4_cleanup_0v)
    /* Unwind info 0x7fffeaa8 */
    *(.text._Z34run_test_depth01_error64_cleanup_0v)
    /* Unwind info 0x7fffeac4 */
    *(.text._Z34run_test_depth10_error4_cleanup_25v)
    /* Unwind info 0x7fffeae0 */
    *(.text._Z35run_test_depth10_error64_cleanup_25v)
    /* Unwind info 0x7fffeae4 */
    *(.text._Z34run_test_depth70_error4_cleanup_25v)
    /* Unwind info 0x7fffeba8 */
    *(.text._Z35run_test_depth10_error4_cleanup_100v)
    /* Unwind info 0x7fffebc4 */
    *(.text._Z36run_test_depth10_error64_cleanup_100v)
    /* Unwind info 0x7fffecd0 */
    *(.text._Z35run_test_depth30_error4_cleanup_100v)
    /* Unwind info 0x7fffecec */
    *(.text._Z36run_test_depth30_error64_cleanup_100v)
    /* Unwind info 0x7fffedf8 */
    *(.text._Z35run_test_depth50_error4_cleanup_100v)
    /* Unwind info 0x7fffee14 */
    *(.text._Z36run_test_depth50_error64_cleanup_100v)
    /* Unwind info 0x7fffef20 */
    *(.text._Z35run_test_depth70_error4_cleanup_100v)
    /* Unwind info 0x7fffef3c */
    *(.text._Z36run_test_depth70_error64_cleanup_100v)
    /* Unwind info 0x7fffef68 */
    *(.text._Z34run_test_depth01_error4_cleanup_75v)
    /* Unwind info 0x7fffef84 */
    *(.text._Z35run_test_depth01_error64_cleanup_75v)
    /* Unwind info 0x7fffefe4 */
    *(.text._Z34run_test_depth10_error4_cleanup_75v)
    /* Unwind info 0x7ffff000 */
    *(.text._Z35run_test_depth10_error64_cleanup_75v)
    /* Unwind info 0x7ffff0a8 */
    *(.text._Z34run_test_depth30_error4_cleanup_75v)
    /* Unwind info 0x7ffff0c4 */
    *(.text._Z35run_test_depth30_error64_cleanup_75v)
    /* Unwind info 0x7ffff16c */
    *(.text._Z34run_test_depth50_error4_cleanup_75v)
    /* Unwind info 0x7ffff188 */
    *(.text._Z35run_test_depth50_error64_cleanup_75v)
    /* Unwind info 0x7ffff21c */
    *(.text._Z34run_test_depth70_error4_cleanup_75v)
    /* Unwind info 0x7ffff238 */
    *(.text._Z35run_test_depth70_error64_cleanup_75v)
    /* Unwind info 0x7ffff264 */
    *(.text._Z34run_test_depth01_error4_cleanup_50v)
    /* Unwind info 0x7ffff280 */
    *(.text._Z35run_test_depth01_error64_cleanup_50v)
    /* Unwind info 0x7ffff2a4 */
    *(.text._Z34run_test_depth10_error4_cleanup_50v)
    /* Unwind info 0x7ffff2c0 */
    *(.text._Z35run_test_depth10_error64_cleanup_50v)
    /* Unwind info 0x7ffff304 */
    *(.text._Z34run_test_depth30_error4_cleanup_50v)
    /* Unwind info 0x7ffff320 */
    *(.text._Z35run_test_depth30_error64_cleanup_50v)
    /* Unwind info 0x7ffff364 */
    *(.text._Z34run_test_depth50_error4_cleanup_50v)
    /* Unwind info 0x7ffff380 */
    *(.text._Z35run_test_depth50_error64_cleanup_50v)
    /* Unwind info 0x7ffff3c4 */
    *(.text._Z34run_test_depth70_error4_cleanup_50v)
    /* Unwind info 0x7ffff3e0 */
    *(.text._Z35run_test_depth70_error64_cleanup_50v)
    /* Unwind info 0x7fffeb28 */
    *(.text._Z19depth_33_percent_25v.isra.0)
    /* Unwind info 0x7fffeaf0 */
    *(.text._Z19depth_50_percent_25v.isra.0)
    /* Unwind info 0x7fffeb10 */
    *(.text._Z19depth_58_percent_25v.isra.0)
    /* Unwind info 0x7fffeaf8 */
    *(.text._Z19depth_66_percent_25v.isra.0)
    /* Unwind info 0x7fffeb3c */
    *(.text._Z20depth_02_percent_100v.isra.0)
    /* Unwind info 0x7fffeb48 */
    *(.text._Z20depth_03_percent_100v.isra.0)
    /* Unwind info 0x7fffeb54 */
    *(.text._Z20depth_04_percent_100v.isra.0)
    /* Unwind info 0x7fffeb60 */
    *(.text._Z20depth_05_percent_100v.isra.0)
    /* Unwind info 0x7fffeb6c */
    *(.text._Z20depth_06_percent_100v.isra.0)
    /* Unwind info 0x7fffeb78 */
    *(.text._Z20depth_07_percent_100v.isra.0)
    /* Unwind info 0x7fffeb84 */
    *(.text._Z20depth_08_percent_100v.isra.0)
    /* Unwind info 0x7fffeb90 */
    *(.text._Z20depth_09_percent_100v.isra.0)
    /* Unwind info 0x7fffeb9c */
    *(.text._Z20depth_10_percent_100v.isra.0)
    /* Unwind info 0x7fffebe0 */
    *(.text._Z20depth_11_percent_100v.isra.0)
    /* Unwind info 0x7fffebec */
    *(.text._Z20depth_12_percent_100v.isra.0)
    /* Unwind info 0x7fffebf8 */
    *(.text._Z20depth_13_percent_100v.isra.0)
    /* Unwind info 0x7fffec04 */
    *(.text._Z20depth_14_percent_100v.isra.0)
    /* Unwind info 0x7fffec10 */
    *(.text._Z20depth_15_percent_100v.isra.0)
    /* Unwind info 0x7fffec1c */
    *(.text._Z20depth_16_percent_100v.isra.0)
    /* Unwind info 0x7fffec28 */
    *(.text._Z20depth_17_percent_100v.isra.0)
    /* Unwind info 0x7fffec34 */
    *(.text._Z20depth_18_percent_100v.isra.0)
    /* Unwind info 0x7fffec40 */
    *(.text._Z20depth_19_percent_100v.isra.0)
    /* Unwind info 0x7fffec4c */
    *(.text._Z20depth_20_percent_100v.isra.0)
    /* Unwind info 0x7fffec58 */
    *(.text._Z20depth_21_percent_100v.isra.0)
    /* Unwind info 0x7fffec64 */
    *(.text._Z20depth_22_percent_100v.isra.0)
    /* Unwind info 0x7fffec70 */
    *(.text._Z20depth_23_percent_100v.isra.0)
    /* Unwind info 0x7fffec7c */
    *(.text._Z20depth_24_percent_100v.isra.0)
    /* Unwind info 0x7fffec88 */
    *(.text._Z20depth_25_percent_100v.isra.0)
    /* Unwind info 0x7fffec94 */
    *(.text._Z20depth_26_percent_100v.isra.0)
    /* Unwind info 0x7fffeca0 */
    *(.text._Z20depth_27_percent_100v.isra.0)
    /* Unwind info 0x7fffecac */
    *(.text._Z20depth_28_percent_100v.isra.0)
    /* Unwind info 0x7fffecb8 */
    *(.text._Z20depth_29_percent_100v.isra.0)
    /* Unwind info 0x7fffecc4 */
    *(.text._Z20depth_30_percent_100v.isra.0)
    /* Unwind info 0x7fffed08 */
    *(.text._Z20depth_31_percent_100v.isra.0)
    /* Unwind info 0x7fffed14 */
    *(.text._Z20depth_32_percent_100v.isra.0)
    /* Unwind info 0x7fffed20 */
    *(.text._Z20depth_33_percent_100v.isra.0)
    /* Unwind info 0x7fffed2c */
    *(.text._Z20depth_34_percent_100v.isra.0)
    /* Unwind info 0x7fffed38 */
    *(.text._Z20depth_35_percent_100v.isra.0)
    /* Unwind info 0x7fffed44 */
    *(.text._Z20depth_36_percent_100v.isra.0)
    /* Unwind info 0x7fffed50 */
    *(.text._Z20depth_37_percent_100v.isra.0)
    /* Unwind info 0x7fffed5c */
    *(.text._Z20depth_38_percent_100v.isra.0)
    /* Unwind info 0x7fffed68 */
    *(.text._Z20depth_39_percent_100v.isra.0)
    /* Unwind info 0x7fffed74 */
    *(.text._Z20depth_40_percent_100v.isra.0)
    /* Unwind info 0x7fffed80 */
    *(.text._Z20depth_41_percent_100v.isra.0)
    /* Unwind info 0x7fffed8c */
    *(.text._Z20depth_42_percent_100v.isra.0)
    /* Unwind info 0x7fffed98 */
    *(.text._Z20depth_43_percent_100v.isra.0)
    /* Unwind info 0x7fffeda4 */
    *(.text._Z20depth_44_percent_100v.isra.0)
    /* Unwind info 0x7fffedb0 */
    *(.text._Z20depth_45_percent_100v.isra.0)
    /* Unwind info 0x7fffedbc */
    *(.text._Z20depth_46_percent_100v.isra.0)
    /* Unwind info 0x7fffedc8 */
    *(.text._Z20depth_47_percent_100v.isra.0)
    /* Unwind info 0x7fffedd4 */
    *(.text._Z20depth_48_percent_100v.isra.0)
    /* Unwind info 0x7fffede0 */
    *(.text._Z20depth_49_percent_100v.isra.0)
    /* Unwind info 0x7fffedec */
    *(.text._Z20depth_50_percent_100v.isra.0)
    /* Unwind info 0x7fffee30 */
    *(.text._Z20depth_51_percent_100v.isra.0)
    /* Unwind info 0x7fffee3c */
    *(.text._Z20depth_52_percent_100v.isra.0)
    /* Unwind info 0x7fffee48 */
    *(.text._Z20depth_53_percent_100v.isra.0)
    /* Unwind info 0x7fffee54 */
    *(.text._Z20depth_54_percent_100v.isra.0)
    /* Unwind info 0x7fffee60 */
    *(.text._Z20depth_55_percent_100v.isra.0)
    /* Unwind info 0x7fffee6c */
    *(.text._Z20depth_56_percent_100v.isra.0)
    /* Unwind info 0x7fffee78 */
    *(.text._Z20depth_57_percent_100v.isra.0)
    /* Unwind info 0x7fffee84 */
    *(.text._Z20depth_58_percent_100v.isra.0)
    /* Unwind info 0x7fffee90 */
    *(.text._Z20depth_59_percent_100v.isra.0)
    /* Unwind info 0x7fffee9c */
    *(.text._Z20depth_60_percent_100v.isra.0)
    /* Unwind info 0x7fffeea8 */
    *(.text._Z20depth_61_percent_100v.isra.0)
    /* Unwind info 0x7fffeeb4 */
    *(.text._Z20depth_62_percent_100v.isra.0)
    /* Unwind info 0x7fffeec0 */
    *(.text._Z20depth_63_percent_100v.isra.0)
    /* Unwind info 0x7fffeecc */
    *(.text._Z20depth_64_percent_100v.isra.0)
    /* Unwind info 0x7fffeed8 */
    *(.text._Z20depth_65_percent_100v.isra.0)
    /* Unwind info 0x7fffeee4 */
    *(.text._Z20depth_66_percent_100v.isra.0)
    /* Unwind info 0x7fffeef0 */
    *(.text._Z20depth_67_percent_100v.isra.0)
    /* Unwind info 0x7fffeefc */
    *(.text._Z20depth_68_percent_100v.isra.0)
    /* Unwind info 0x7fffef08 */
    *(.text._Z20depth_69_percent_100v.isra.0)
    /* Unwind info 0x7fffef14 */
    *(.text._Z20depth_70_percent_100v.isra.0)
    /* Unwind info 0x7fffefa0 */
    *(.text._Z19depth_02_percent_75v.isra.0)
    /* Unwind info 0x7fffefac */
    *(.text._Z19depth_03_percent_75v.isra.0)
    /* Unwind info 0x7fffefb0 */
    *(.text._Z19depth_05_percent_75v.isra.0)
    /* Unwind info 0x7fffefbc */
    *(.text._Z19depth_06_percent_75v.isra.0)
    /* Unwind info 0x7fffefc8 */
    *(.text._Z19depth_07_percent_75v.isra.0)
    /* Unwind info 0x7fffefcc */
    *(.text._Z19depth_09_percent_75v.isra.0)
    /* Unwind info 0x7fffefd8 */
    *(.text._Z19depth_10_percent_75v.isra.0)
    /* Unwind info 0x7ffff01c */
    *(.text._Z19depth_11_percent_75v.isra.0)
    /* Unwind info 0x7ffff020 */
    *(.text._Z19depth_13_percent_75v.isra.0)
    /* Unwind info 0x7ffff02c */
    *(.text._Z19depth_14_percent_75v.isra.0)
    /* Unwind info 0x7ffff038 */
    *(.text._Z19depth_15_percent_75v.isra.0)
    /* Unwind info 0x7ffff03c */
    *(.text._Z19depth_17_percent_75v.isra.0)
    /* Unwind info 0x7ffff048 */
    *(.text._Z19depth_18_percent_75v.isra.0)
    /* Unwind info 0x7ffff054 */
    *(.text._Z19depth_19_percent_75v.isra.0)
    /* Unwind info 0x7ffff058 */
    *(.text._Z19depth_21_percent_75v.isra.0)
    /* Unwind info 0x7ffff064 */
    *(.text._Z19depth_22_percent_75v.isra.0)
    /* Unwind info 0x7ffff070 */
    *(.text._Z19depth_23_percent_75v.isra.0)
    /* Unwind info 0x7ffff074 */
    *(.text._Z19depth_25_percent_75v.isra.0)
    /* Unwind info 0x7ffff080 */
    *(.text._Z19depth_26_percent_75v.isra.0)
    /* Unwind info 0x7ffff08c */
    *(.text._Z19depth_27_percent_75v.isra.0)
    /* Unwind info 0x7ffff090 */
    *(.text._Z19depth_29_percent_75v.isra.0)
    /* Unwind info 0x7ffff09c */
    *(.text._Z19depth_30_percent_75v.isra.0)
    /* Unwind info 0x7ffff0f0 */
    *(.text._Z19depth_34_percent_75v.isra.0)
    /* Unwind info 0x7ffff0f4 */
    *(.text._Z19depth_36_percent_75v.isra.0)
    /* Unwind info 0x7ffff100 */
    *(.text._Z19depth_37_percent_75v.isra.0)
    /* Unwind info 0x7ffff10c */
    *(.text._Z19depth_38_percent_75v.isra.0)
    /* Unwind info 0x7ffff110 */
    *(.text._Z19depth_40_percent_75v.isra.0)
    /* Unwind info 0x7ffff11c */
    *(.text._Z19depth_41_percent_75v.isra.0)
    /* Unwind info 0x7ffff128 */
    *(.text._Z19depth_42_percent_75v.isra.0)
    /* Unwind info 0x7ffff138 */
    *(.text._Z19depth_45_percent_75v.isra.0)
    /* Unwind info 0x7ffff144 */
    *(.text._Z19depth_46_percent_75v.isra.0)
    /* Unwind info 0x7ffff148 */
    *(.text._Z19depth_48_percent_75v.isra.0)
    /* Unwind info 0x7ffff154 */
    *(.text._Z19depth_49_percent_75v.isra.0)
    /* Unwind info 0x7ffff160 */
    *(.text._Z19depth_50_percent_75v.isra.0)
    /* Unwind info 0x7ffff19c */
    *(.text._Z19depth_52_percent_75v.isra.0)
    /* Unwind info 0x7ffff1a8 */
    *(.text._Z19depth_53_percent_75v.isra.0)
    /* Unwind info 0x7ffff1b8 */
    *(.text._Z19depth_56_percent_75v.isra.0)
    /* Unwind info 0x7ffff1c4 */
    *(.text._Z19depth_57_percent_75v.isra.0)
    /* Unwind info 0x7ffff1d4 */
    *(.text._Z19depth_60_percent_75v.isra.0)
    /* Unwind info 0x7ffff1e0 */
    *(.text._Z19depth_61_percent_75v.isra.0)
    /* Unwind info 0x7ffff1ec */
    *(.text._Z19depth_62_percent_75v.isra.0)
    /* Unwind info 0x7ffff1f0 */
    *(.text._Z19depth_64_percent_75v.isra.0)
    /* Unwind info 0x7ffff1fc */
    *(.text._Z19depth_65_percent_75v.isra.0)
    /* Unwind info 0x7ffff208 */
    *(.text._Z19depth_66_percent_75v.isra.0)
    /* Unwind info 0x7ffff20c */
    *(.text._Z19depth_68_percent_75v.isra.0)
    /* Unwind info 0x7ffff218 */
    *(.text._Z19depth_69_percent_75v.isra.0)
    /* Unwind info 0x7ffff294 */
    *(.text._Z19depth_03_percent_50v.isra.0)
    /* Unwind info 0x7ffff298 */
    *(.text._Z19depth_05_percent_50v.isra.0)
    /* Unwind info 0x7ffff29c */
    *(.text._Z19depth_07_percent_50v.isra.0)
    /* Unwind info 0x7ffff2a0 */
    *(.text._Z19depth_09_percent_50v.isra.0)
    /* Unwind info 0x7ffff2dc */
    *(.text._Z19depth_11_percent_50v.isra.0)
    /* Unwind info 0x7ffff2e0 */
    *(.text._Z19depth_13_percent_50v.isra.0)
    /* Unwind info 0x7ffff2e4 */
    *(.text._Z19depth_15_percent_50v.isra.0)
    /* Unwind info 0x7ffff2e8 */
    *(.text._Z19depth_17_percent_50v.isra.0)
    /* Unwind info 0x7ffff2ec */
    *(.text._Z19depth_19_percent_50v.isra.0)
    /* Unwind info 0x7ffff2f0 */
    *(.text._Z19depth_21_percent_50v.isra.0)
    /* Unwind info 0x7ffff2f4 */
    *(.text._Z19depth_23_percent_50v.isra.0)
    /* Unwind info 0x7ffff2f8 */
    *(.text._Z19depth_25_percent_50v.isra.0)
    /* Unwind info 0x7ffff2fc */
    *(.text._Z19depth_27_percent_50v.isra.0)
    /* Unwind info 0x7ffff300 */
    *(.text._Z19depth_29_percent_50v.isra.0)
    /* Unwind info 0x7ffff33c */
    *(.text._Z19depth_31_percent_50v.isra.0)
    /* Unwind info 0x7ffff340 */
    *(.text._Z19depth_33_percent_50v.isra.0)
    /* Unwind info 0x7ffff344 */
    *(.text._Z19depth_35_percent_50v.isra.0)
    /* Unwind info 0x7ffff348 */
    *(.text._Z19depth_37_percent_50v.isra.0)
    /* Unwind info 0x7ffff34c */
    *(.text._Z19depth_39_percent_50v.isra.0)
    /* Unwind info 0x7ffff350 */
    *(.text._Z19depth_41_percent_50v.isra.0)
    /* Unwind info 0x7ffff354 */
    *(.text._Z19depth_43_percent_50v.isra.0)
    /* Unwind info 0x7ffff358 */
    *(.text._Z19depth_45_percent_50v.isra.0)
    /* Unwind info 0x7ffff35c */
    *(.text._Z19depth_47_percent_50v.isra.0)
    /* Unwind info 0x7ffff360 */
    *(.text._Z19depth_49_percent_50v.isra.0)
    /* Unwind info 0x7ffff39c */
    *(.text._Z19depth_51_percent_50v.isra.0)
    /* Unwind info 0x7ffff3a0 */
    *(.text._Z19depth_53_percent_50v.isra.0)
    /* Unwind info 0x7ffff3a4 */
    *(.text._Z19depth_55_percent_50v.isra.0)
    /* Unwind info 0x7ffff3a8 */
    *(.text._Z19depth_57_percent_50v.isra.0)
    /* Unwind info 0x7ffff3ac */
    *(.text._Z19depth_59_percent_50v.isra.0)
    /* Unwind info 0x7ffff3b0 */
    *(.text._Z19depth_61_percent_50v.isra.0)
    /* Unwind info 0x7ffff3b4 */
    *(.text._Z19depth_63_percent_50v.isra.0)
    /* Unwind info 0x7ffff3b8 */
    *(.text._Z19depth_65_percent_50v.isra.0)
    /* Unwind info 0x7ffff3bc */
    *(.text._Z19depth_67_percent_50v.isra.0)
    /* Unwind info 0x7ffff3c0 */
    *(.text._Z19depth_69_percent_50v.isra.0)
    /* Unwind info 0x7ffff3f4 */
    *(.text._Z19depth_05_percent_25v.isra.0)
    /* Unwind info 0x7ffff3e8 */
    *(.text._Z19depth_09_percent_25v.isra.0)
    /* Unwind info 0x7fffeb34 */
    *(.text._ZN3hal7stm32f112gpio_manager6output12driver_levelEb)
    /* Unwind info 0x8003aab0 */
    *(.text._ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv)
    /* Unwind info 0x7ffff1a4 */
    *(.text._ZNKSt3_V214error_category10_M_messageB5cxx11Ei)
    /* Unwind info 0x7fffff0c */
    *(.text.unlikely._ZSt19__throw_logic_errorPKc)
    /* Unwind info 0x7fffff18 */
    *(.text.unlikely._ZSt20__throw_length_errorPKc)
    /* Unwind info 0x7fffeb38 */
    *(.text._ZN3hal7stm32f112gpio_manager6output12driver_levelEv)
    /* Unwind info 0x7fffff08 */
    *(.text.unlikely._ZSt17__throw_bad_allocv)
  }
}
INSERT BEFORE .text;
