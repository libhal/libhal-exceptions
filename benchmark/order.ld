SECTIONS {
  .text.sorted : {
    /* LEAF & unsortable functions below */
    /* Unwind info 0x00000001 */
    *(.text.unlikely._Z3endv)
    *(.text.unlikely._exit)
    *(.text.unlikely.__wrap___cxa_call_unexpected)
    *(.text.unlikely._Znwj)
    *(.text.unlikely._ZnwjSt11align_val_t)
    *(.text.unlikely._ZSt9terminatev)
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
    *(.text._Z5startv)
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
    *(.text._ZN3hal26single_exception_allocatorD2Ev)
    *(.text._ZN3hal26single_exception_allocatorD0Ev)
    *(.text._ZN28single_block_memory_resourceILj256EED2Ev)
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
    *(.text._ZdlPvj)
    *(.text._ZdlPv)
    *(.text._ZdlPvSt11align_val_t)
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
    *_arm_addsubdf3.o(.text*)
    *_arm_muldivdf3.o(.text*)
    *_arm_fixunsdfsi.o(.text*)
    *_arm_addsubsf3.o(.text*)
    *_arm_fixunssfsi.o(.text*)
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
    *_arm_muldivsf3.o(.text*)
    *_arm_cmpsf2.o(.text*)
    *_arm_unordsf2.o(.text*)
    *_aeabi_ldivmod.o(.text*)
    *(.text.__fixsfdi)
    *(.text.__fixunssfdi)
    *strcmp.S.o(.text*)
    *(.text.memcpy)
    *(.text.memset)
    *strlen.S.o(.text*)
    *(.text.__libc_init_array)
    *(.text.__retarget_lock_acquire_recursive)
    *(.text.__retarget_lock_release_recursive)
    *(.text.__cxa_atexit)
    *(.text.__call_exitprocs)
    *(.text._on_exit)
    *(.text.__xpg_strerror_r)
    *(.text.arm_halt_isr)
    *(.text.arm_ignore_isr)
    *(.text.roundf)
    *strcpy.S.o(.text*)
    *(.text.raise)
    *(.text._strerror_r)
    *(.text.__udivmoddi4)
    *_dvmd_tls.o(.text*)
    /* Unwind info 0x8003a8b0 */
    *(.text._Z20depth_04_percent_050v.isra.0)
    *(.text._Z20depth_06_percent_050v.isra.0)
    *(.text._Z20depth_08_percent_050v.isra.0)
    *(.text._Z20depth_14_percent_050v.isra.0)
    *(.text._Z20depth_16_percent_050v.isra.0)
    *(.text._Z20depth_20_percent_050v.isra.0)
    *(.text._Z20depth_22_percent_050v.isra.0)
    *(.text._Z20depth_24_percent_050v.isra.0)
    *(.text._Z20depth_26_percent_050v.isra.0)
    *(.text._Z20depth_28_percent_050v.isra.0)
    *(.text._Z20depth_32_percent_050v.isra.0)
    *(.text._Z20depth_34_percent_050v.isra.0)
    *(.text._Z20depth_46_percent_050v.isra.0)
    *(.text._Z20depth_50_percent_050v.isra.0)
    *(.text._Z20depth_03_percent_025v.isra.0)
    *(.text._Z20depth_04_percent_025v.isra.0)
    *(.text._Z20depth_06_percent_025v.isra.0)
    *(.text._Z20depth_07_percent_025v.isra.0)
    *(.text._Z20depth_08_percent_025v.isra.0)
    *(.text._Z20depth_11_percent_025v.isra.0)
    *(.text._Z20depth_14_percent_025v.isra.0)
    *(.text._Z20depth_16_percent_025v.isra.0)
    *(.text._Z20depth_19_percent_025v.isra.0)
    *(.text._Z20depth_20_percent_025v.isra.0)
    *(.text._Z20depth_22_percent_025v.isra.0)
    *(.text._Z20depth_23_percent_025v.isra.0)
    *(.text._Z20depth_24_percent_025v.isra.0)
    *(.text._Z20depth_26_percent_025v.isra.0)
    *(.text._Z20depth_27_percent_025v.isra.0)
    *(.text._Z20depth_28_percent_025v.isra.0)
    *(.text._Z20depth_32_percent_025v.isra.0)
    *(.text._Z20depth_34_percent_025v.isra.0)
    *(.text._Z20depth_35_percent_025v.isra.0)
    *(.text._Z20depth_37_percent_025v.isra.0)
    *(.text._Z20depth_43_percent_025v.isra.0)
    *(.text._Z20depth_47_percent_025v.isra.0)
    *(.text._Z20depth_49_percent_025v.isra.0)
    *(.text._Z20depth_03_percent_000v.isra.0)
    *(.text._Z20depth_04_percent_000v.isra.0)
    *(.text._Z20depth_05_percent_000v.isra.0)
    *(.text._Z20depth_06_percent_000v.isra.0)
    *(.text._Z20depth_07_percent_000v.isra.0)
    *(.text._Z20depth_08_percent_000v.isra.0)
    *(.text._Z20depth_11_percent_000v.isra.0)
    *(.text._Z20depth_14_percent_000v.isra.0)
    *(.text._Z20depth_16_percent_000v.isra.0)
    *(.text._Z20depth_19_percent_000v.isra.0)
    *(.text._Z20depth_20_percent_000v.isra.0)
    *(.text._Z20depth_22_percent_000v.isra.0)
    *(.text._Z20depth_23_percent_000v.isra.0)
    *(.text._Z20depth_24_percent_000v.isra.0)
    *(.text._Z20depth_26_percent_000v.isra.0)
    *(.text._Z20depth_27_percent_000v.isra.0)
    *(.text._Z20depth_28_percent_000v.isra.0)
    *(.text._Z20depth_32_percent_000v.isra.0)
    *(.text._Z20depth_34_percent_000v.isra.0)
    *(.text._Z20depth_35_percent_000v.isra.0)
    *(.text._Z20depth_37_percent_000v.isra.0)
    *(.text._Z20depth_43_percent_000v.isra.0)
    *(.text._Z20depth_46_percent_000v.isra.0)
    *(.text._Z20depth_47_percent_000v.isra.0)
    *(.text._Z20depth_49_percent_000v.isra.0)
    *(.text._Z20depth_50_percent_000v.isra.0)
    /* Unwind info 0x8002a9b0 */
    *(.text._Z20depth_10_percent_050v.isra.0)
    *(.text._Z20depth_12_percent_050v.isra.0)
    *(.text._Z20depth_36_percent_050v.isra.0)
    *(.text._Z20depth_40_percent_050v.isra.0)
    *(.text._Z20depth_42_percent_050v.isra.0)
    *(.text._Z20depth_10_percent_025v.isra.0)
    *(.text._Z20depth_12_percent_025v.isra.0)
    *(.text._Z20depth_15_percent_025v.isra.0)
    *(.text._Z20depth_36_percent_025v.isra.0)
    *(.text._Z20depth_39_percent_025v.isra.0)
    *(.text._Z20depth_40_percent_025v.isra.0)
    *(.text._Z20depth_41_percent_025v.isra.0)
    *(.text._Z20depth_09_percent_000v.isra.0)
    *(.text._Z20depth_10_percent_000v.isra.0)
    *(.text._Z20depth_12_percent_000v.isra.0)
    *(.text._Z20depth_15_percent_000v.isra.0)
    *(.text._Z20depth_25_percent_000v.isra.0)
    *(.text._Z20depth_36_percent_000v.isra.0)
    *(.text._Z20depth_39_percent_000v.isra.0)
    *(.text._Z20depth_40_percent_000v.isra.0)
    *(.text._Z20depth_41_percent_000v.isra.0)
    *(.text._Z20depth_42_percent_000v.isra.0)
    *(.text._ZN3hal7stm32f113configure_pinENS0_10pin_selectENS0_12pin_config_tE)
    *(.text.get_eit_entry)
    /* Unwind info 0x8001a8b0 */
    *(.text._Z20depth_02_percent_025v.isra.0)
    *(.text._Z20depth_18_percent_050v.isra.0)
    *(.text._Z20depth_30_percent_050v.isra.0)
    *(.text._Z20depth_38_percent_050v.isra.0)
    *(.text._Z20depth_44_percent_050v.isra.0)
    *(.text._Z20depth_48_percent_050v.isra.0)
    *(.text._Z20depth_18_percent_025v.isra.0)
    *(.text._Z20depth_30_percent_025v.isra.0)
    *(.text._Z20depth_31_percent_025v.isra.0)
    *(.text._Z20depth_44_percent_025v.isra.0)
    *(.text._Z20depth_45_percent_025v.isra.0)
    *(.text._Z20depth_48_percent_025v.isra.0)
    *(.text._Z20depth_02_percent_000v.isra.0)
    *(.text._Z20depth_13_percent_000v.isra.0)
    *(.text._Z20depth_17_percent_000v.isra.0)
    *(.text._Z20depth_18_percent_000v.isra.0)
    *(.text._Z20depth_21_percent_000v.isra.0)
    *(.text._Z20depth_29_percent_000v.isra.0)
    *(.text._Z20depth_30_percent_000v.isra.0)
    *(.text._Z20depth_31_percent_000v.isra.0)
    *(.text._Z20depth_33_percent_000v.isra.0)
    *(.text._Z20depth_38_percent_000v.isra.0)
    *(.text._Z20depth_44_percent_000v.isra.0)
    *(.text._Z20depth_45_percent_000v.isra.0)
    *(.text._Z20depth_48_percent_000v.isra.0)
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
    /* Unwind info 0x8002afb0 */
    *(.text.__wrap___cxa_throw)
    *(.text._ZNK10__cxxabiv121__vmi_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_)
    /* Unwind info 0x7ffff2c8 */
    *(.text._Z20depth_41_percent_050v.isra.0)
    *(.text._Z20depth_17_percent_025v.isra.0)
    *(.text._Z20depth_25_percent_025v.isra.0)
    *(.text._Z20depth_33_percent_025v.isra.0)
    *(.text._Z38run_test_depth_01_error_04_cleanup_025v)
    /* Unwind info 0x80acb0b0 */
    *(.text._ZN3hal5delayERNS_12steady_clockENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE.constprop.0)
    *(.text._ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE)
    *(.text._ZN9__gnu_cxx15__snprintf_liteEPcjPKcSt9__va_list)
    /* Unwind info 0x80a8b0b0 */
    *(.text.unlikely._ZN3hal7stm32f127throw_if_pin_is_unavailableENS0_10pin_selectE.part.0)
    *(.text.unlikely._ZN3hal7stm32f112_GLOBAL__N_124get_enable_register_infoENS0_10peripheralE.part.0)
    *(.text._ZNSt12length_errorC2EPKc)
    *(.text._ZNSt12out_of_rangeC2EPKc)
    *(.text._ZNSs4_Rep9_S_createEjjRKSaIcE)
    *(.text.restore_non_core_regs)
    /* Unwind info 0x80aab0b0 */
    *(.text._ZN3hal7stm32f112gpio_manager6output16driver_configureERKNS_10output_pin8settingsE)
    *(.text.unwind_phase2)
    *(.text.__gnu_Unwind_Resume)
    /* Unwind info 0x7ffff2bc */
    *(.text._Z20depth_35_percent_050v.isra.0)
    *(.text._Z20depth_38_percent_025v.isra.0)
    *(.text._Z20depth_46_percent_025v.isra.0)
    /* Unwind info 0x80b276af */
    *(.text.unwind_phase2_forced)
    /* Unwind info 0x7ffff028 */
    *(.text._Z20depth_01_percent_025v.isra.0)
    /* Unwind info 0x8004a9b0 */
    *(.text._Z20depth_01_percent_000v.isra.0)
    /* Unwind info 0x7ffff2c0 */
    *(.text._Z20depth_37_percent_050v.isra.0)
    *(.text._Z20depth_42_percent_025v.isra.0)
    /* Unwind info 0x7ffff2c4 */
    *(.text._Z20depth_39_percent_050v.isra.0)
    *(.text._Z20depth_21_percent_025v.isra.0)
    /* Unwind info 0x7ffff2cc */
    *(.text._Z20depth_43_percent_050v.isra.0)
    *(.text._Z20depth_29_percent_025v.isra.0)
    /* Unwind info 0x7ffff770 */
    *(.text._ZNK12_GLOBAL__N_122generic_error_category7messageB5cxx11Ei)
    /* Unwind info 0x7ffff2ac */
    *(.text._Z20depth_27_percent_050v.isra.0)
    *(.text._Z38run_test_depth_05_error_04_cleanup_025v)
    /* Unwind info 0x7ffff7ac */
    *(.text._ZN3hal7stm32f14uartD2Ev)
    /* Unwind info 0x7ffff7b0 */
    *(.text._ZN3hal7stm32f14uartD0Ev)
    /* Unwind info 0x80b108a9 */
    *(.text.__wrap___cxa_rethrow)
    *(.text.__wrap___cxa_allocate_exception)
    /* Unwind info 0x7ffff1e8 */
    *(.text._Z20depth_38_percent_100v.isra.0)
    *(.text._Z38run_test_depth_35_error_04_cleanup_000v)
    /* Unwind info 0x7ffff23c */
    *(.text._Z20depth_45_percent_100v.isra.0)
    *(.text._Z38run_test_depth_01_error_04_cleanup_000v)
    /* Unwind info 0x7ffff2b0 */
    *(.text._Z20depth_29_percent_050v.isra.0)
    *(.text._Z20depth_50_percent_025v.isra.0)
    /* Unwind info 0x7ffff2d4 */
    *(.text._Z20depth_47_percent_050v.isra.0)
    *(.text._Z20depth_13_percent_025v.isra.0)
    /* Unwind info 0x7ffff290 */
    *(.text._Z20depth_13_percent_050v.isra.0)
    *(.text._Z38run_test_depth_15_error_04_cleanup_025v)
    /* Unwind info 0x80b20fac */
    *(.text.__gnu_Unwind_Backtrace)
    /* Unwind info 0x7ffff77c */
    *(.text._Z38run_test_depth_15_error_65_cleanup_100v)
    *(.text._ZN10__cxxabiv111__terminateEPFvvE)
    *(.text._ZNKSt3_V214error_category10_M_messageB5cxx11Ei)
    /* Unwind info 0x7ffff794 */
    *(.text._ZNSt11logic_errorC2EPKc)
    /* Unwind info 0x8002abb0 */
    *(.text._ZNSt12__cow_stringC2EPKcj)
    /* Unwind info 0x803a3fab */
    *(.text.__gnu_Unwind_RaiseException)
    /* Unwind info 0x7ffff744 */
    *(.text._Z38run_test_depth_50_error_65_cleanup_100v)
    *(.text.__gnu_Unwind_Resume_or_Rethrow)
    /* Unwind info 0x7fffff3c */
    *(.text.unlikely._ZSt24__throw_out_of_range_fmtPKcz)
    /* Unwind info 0x8001aab0 */
    *(.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEj)
    /* Unwind info 0x7ffff08c */
    *(.text._Z20depth_09_percent_100v.isra.0)
    /* Unwind info 0x7ffff14c */
    *(.text._Z20depth_25_percent_100v.isra.0)
    /* Unwind info 0x7ffff164 */
    *(.text._Z20depth_27_percent_100v.isra.0)
    /* Unwind info 0x7ffff1f4 */
    *(.text._Z20depth_39_percent_100v.isra.0)
    /* Unwind info 0x7ffff224 */
    *(.text._Z20depth_43_percent_100v.isra.0)
    /* Unwind info 0x7ffff288 */
    *(.text._Z20depth_09_percent_050v.isra.0)
    /* Unwind info 0x7ffff2a8 */
    *(.text._Z20depth_25_percent_050v.isra.0)
    /* Unwind info 0x7ffff2e0 */
    *(.text._Z20depth_09_percent_025v.isra.0)
    /* Unwind info 0x7ffff05c */
    *(.text._Z20depth_05_percent_100v.isra.0)
    /* Unwind info 0x7ffff0f8 */
    *(.text._Z20depth_18_percent_100v.isra.0)
    /* Unwind info 0x7ffff104 */
    *(.text._Z20depth_19_percent_100v.isra.0)
    /* Unwind info 0x7ffff134 */
    *(.text._Z20depth_23_percent_100v.isra.0)
    /* Unwind info 0x7ffff140 */
    *(.text._Z20depth_24_percent_100v.isra.0)
    /* Unwind info 0x7ffff194 */
    *(.text._Z20depth_31_percent_100v.isra.0)
    /* Unwind info 0x7ffff1a0 */
    *(.text._Z20depth_32_percent_100v.isra.0)
    /* Unwind info 0x7ffff1c4 */
    *(.text._Z20depth_35_percent_100v.isra.0)
    /* Unwind info 0x7ffff1dc */
    *(.text._Z20depth_37_percent_100v.isra.0)
    /* Unwind info 0x7ffff230 */
    *(.text._Z20depth_44_percent_100v.isra.0)
    /* Unwind info 0x7ffff248 */
    *(.text._Z20depth_46_percent_100v.isra.0)
    /* Unwind info 0x7ffff280 */
    *(.text._Z20depth_05_percent_050v.isra.0)
    /* Unwind info 0x7ffff29c */
    *(.text._Z20depth_19_percent_050v.isra.0)
    /* Unwind info 0x7ffff2a4 */
    *(.text._Z20depth_23_percent_050v.isra.0)
    /* Unwind info 0x7ffff2b4 */
    *(.text._Z20depth_31_percent_050v.isra.0)
    /* Unwind info 0x7ffff2d0 */
    *(.text._Z20depth_45_percent_050v.isra.0)
    /* Unwind info 0x7ffff2dc */
    *(.text._Z20depth_05_percent_025v.isra.0)
    /* Unwind info 0x7ffff784 */
    *(.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj)
    /* Unwind info 0x7ffff044 */
    *(.text._Z20depth_03_percent_100v.isra.0)
    /* Unwind info 0x7ffff050 */
    *(.text._Z20depth_04_percent_100v.isra.0)
    /* Unwind info 0x7ffff068 */
    *(.text._Z20depth_06_percent_100v.isra.0)
    /* Unwind info 0x7ffff074 */
    *(.text._Z20depth_07_percent_100v.isra.0)
    /* Unwind info 0x7ffff080 */
    *(.text._Z20depth_08_percent_100v.isra.0)
    /* Unwind info 0x7ffff098 */
    *(.text._Z20depth_10_percent_100v.isra.0)
    /* Unwind info 0x7ffff0a4 */
    *(.text._Z20depth_11_percent_100v.isra.0)
    /* Unwind info 0x7ffff0b0 */
    *(.text._Z20depth_12_percent_100v.isra.0)
    /* Unwind info 0x7ffff0c8 */
    *(.text._Z20depth_14_percent_100v.isra.0)
    /* Unwind info 0x7ffff0d4 */
    *(.text._Z20depth_15_percent_100v.isra.0)
    /* Unwind info 0x7ffff0e0 */
    *(.text._Z20depth_16_percent_100v.isra.0)
    /* Unwind info 0x7ffff110 */
    *(.text._Z20depth_20_percent_100v.isra.0)
    /* Unwind info 0x7ffff128 */
    *(.text._Z20depth_22_percent_100v.isra.0)
    /* Unwind info 0x7ffff158 */
    *(.text._Z20depth_26_percent_100v.isra.0)
    /* Unwind info 0x7ffff170 */
    *(.text._Z20depth_28_percent_100v.isra.0)
    /* Unwind info 0x7ffff1b8 */
    *(.text._Z20depth_34_percent_100v.isra.0)
    /* Unwind info 0x7ffff1d0 */
    *(.text._Z20depth_36_percent_100v.isra.0)
    /* Unwind info 0x7ffff200 */
    *(.text._Z20depth_40_percent_100v.isra.0)
    /* Unwind info 0x7ffff20c */
    *(.text._Z20depth_41_percent_100v.isra.0)
    /* Unwind info 0x7ffff218 */
    *(.text._Z20depth_42_percent_100v.isra.0)
    /* Unwind info 0x7ffff254 */
    *(.text._Z20depth_47_percent_100v.isra.0)
    /* Unwind info 0x7ffff26c */
    *(.text._Z20depth_49_percent_100v.isra.0)
    /* Unwind info 0x7ffff278 */
    *(.text._Z20depth_50_percent_100v.isra.0)
    /* Unwind info 0x7ffff27c */
    *(.text._Z20depth_03_percent_050v.isra.0)
    /* Unwind info 0x7ffff284 */
    *(.text._Z20depth_07_percent_050v.isra.0)
    /* Unwind info 0x7ffff28c */
    *(.text._Z20depth_11_percent_050v.isra.0)
    /* Unwind info 0x7ffff294 */
    *(.text._Z20depth_15_percent_050v.isra.0)
    /* Unwind info 0x7ffff2d8 */
    *(.text._Z20depth_49_percent_050v.isra.0)
    /* Unwind info 0x7ffff798 */
    *(.text._Z38run_test_depth_05_error_65_cleanup_100v)
    *(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t11do_allocateEjj)
    /* Unwind info 0x80971cab */
    *(.text.unlikely._ZN9__gnu_cxx26__throw_insufficient_spaceEPKcS1_)
    /* Unwind info 0x7ffff038 */
    *(.text._Z20depth_02_percent_100v.isra.0)
    /* Unwind info 0x7ffff0bc */
    *(.text._Z20depth_13_percent_100v.isra.0)
    /* Unwind info 0x7ffff0ec */
    *(.text._Z20depth_17_percent_100v.isra.0)
    /* Unwind info 0x7ffff11c */
    *(.text._Z20depth_21_percent_100v.isra.0)
    /* Unwind info 0x7ffff17c */
    *(.text._Z20depth_29_percent_100v.isra.0)
    /* Unwind info 0x7ffff260 */
    *(.text._Z20depth_48_percent_100v.isra.0)
    /* Unwind info 0x7ffff298 */
    *(.text._Z20depth_17_percent_050v.isra.0)
    /* Unwind info 0x7ffff2a0 */
    *(.text._Z20depth_21_percent_050v.isra.0)
    /* Unwind info 0x7ffff024 */
    *(.text._ZN3hal7stm32f18power_onENS0_10peripheralE)
    /* Unwind info 0x7ffff188 */
    *(.text._Z20depth_30_percent_100v.isra.0)
    /* Unwind info 0x7ffff1ac */
    *(.text._Z20depth_33_percent_100v.isra.0)
    /* Unwind info 0x7ffff2b8 */
    *(.text._Z20depth_33_percent_050v.isra.0)
    /* Unwind info 0x7ffff1cc */
    *(.text._Z38run_test_depth_50_error_04_cleanup_000v)
    /* Unwind info 0x7ffff204 */
    *(.text._Z38run_test_depth_15_error_04_cleanup_000v)
    /* Unwind info 0x7ffff220 */
    *(.text._Z38run_test_depth_05_error_04_cleanup_000v)
    /* Unwind info 0x7ffff258 */
    *(.text._Z38run_test_depth_50_error_04_cleanup_025v)
    /* Unwind info 0x7ffff274 */
    *(.text._Z38run_test_depth_35_error_04_cleanup_025v)
    /* Unwind info 0x7ffff2e4 */
    *(.text._Z38run_test_depth_50_error_04_cleanup_050v)
    /* Unwind info 0x7ffff300 */
    *(.text._Z38run_test_depth_35_error_04_cleanup_050v)
    /* Unwind info 0x7ffff31c */
    *(.text._Z38run_test_depth_15_error_04_cleanup_050v)
    /* Unwind info 0x7ffff338 */
    *(.text._Z38run_test_depth_05_error_04_cleanup_050v)
    /* Unwind info 0x7ffff354 */
    *(.text._Z38run_test_depth_50_error_04_cleanup_100v)
    /* Unwind info 0x7ffff370 */
    *(.text._Z38run_test_depth_35_error_04_cleanup_100v)
    /* Unwind info 0x7ffff38c */
    *(.text._Z38run_test_depth_15_error_04_cleanup_100v)
    /* Unwind info 0x7ffff3a8 */
    *(.text._Z38run_test_depth_05_error_04_cleanup_100v)
    /* Unwind info 0x7ffff3c4 */
    *(.text._Z38run_test_depth_50_error_16_cleanup_000v)
    /* Unwind info 0x7ffff3e0 */
    *(.text._Z38run_test_depth_35_error_16_cleanup_000v)
    /* Unwind info 0x7ffff3fc */
    *(.text._Z38run_test_depth_15_error_16_cleanup_000v)
    /* Unwind info 0x7ffff418 */
    *(.text._Z38run_test_depth_05_error_16_cleanup_000v)
    /* Unwind info 0x7ffff434 */
    *(.text._Z38run_test_depth_01_error_16_cleanup_000v)
    /* Unwind info 0x7ffff450 */
    *(.text._Z38run_test_depth_50_error_16_cleanup_025v)
    /* Unwind info 0x7ffff46c */
    *(.text._Z38run_test_depth_35_error_16_cleanup_025v)
    /* Unwind info 0x7ffff488 */
    *(.text._Z38run_test_depth_15_error_16_cleanup_025v)
    /* Unwind info 0x7ffff4a4 */
    *(.text._Z38run_test_depth_05_error_16_cleanup_025v)
    /* Unwind info 0x7ffff4c0 */
    *(.text._Z38run_test_depth_01_error_16_cleanup_025v)
    /* Unwind info 0x7ffff4dc */
    *(.text._Z38run_test_depth_50_error_16_cleanup_050v)
    /* Unwind info 0x7ffff4f8 */
    *(.text._Z38run_test_depth_35_error_16_cleanup_050v)
    /* Unwind info 0x7ffff514 */
    *(.text._Z38run_test_depth_15_error_16_cleanup_050v)
    /* Unwind info 0x7ffff530 */
    *(.text._Z38run_test_depth_05_error_16_cleanup_050v)
    /* Unwind info 0x7ffff54c */
    *(.text._Z38run_test_depth_50_error_16_cleanup_100v)
    /* Unwind info 0x7ffff568 */
    *(.text._Z38run_test_depth_35_error_16_cleanup_100v)
    /* Unwind info 0x7ffff584 */
    *(.text._Z38run_test_depth_15_error_16_cleanup_100v)
    /* Unwind info 0x7ffff5a0 */
    *(.text._Z38run_test_depth_05_error_16_cleanup_100v)
    /* Unwind info 0x7ffff5bc */
    *(.text._Z38run_test_depth_50_error_65_cleanup_000v)
    /* Unwind info 0x7ffff5d8 */
    *(.text._Z38run_test_depth_35_error_65_cleanup_000v)
    /* Unwind info 0x7ffff5f4 */
    *(.text._Z38run_test_depth_15_error_65_cleanup_000v)
    /* Unwind info 0x7ffff610 */
    *(.text._Z38run_test_depth_05_error_65_cleanup_000v)
    /* Unwind info 0x7ffff62c */
    *(.text._Z38run_test_depth_01_error_65_cleanup_000v)
    /* Unwind info 0x7ffff648 */
    *(.text._Z38run_test_depth_50_error_65_cleanup_025v)
    /* Unwind info 0x7ffff664 */
    *(.text._Z38run_test_depth_35_error_65_cleanup_025v)
    /* Unwind info 0x7ffff680 */
    *(.text._Z38run_test_depth_15_error_65_cleanup_025v)
    /* Unwind info 0x7ffff69c */
    *(.text._Z38run_test_depth_05_error_65_cleanup_025v)
    /* Unwind info 0x7ffff6b8 */
    *(.text._Z38run_test_depth_01_error_65_cleanup_025v)
    /* Unwind info 0x7ffff6d4 */
    *(.text._Z38run_test_depth_50_error_65_cleanup_050v)
    /* Unwind info 0x7ffff6f0 */
    *(.text._Z38run_test_depth_35_error_65_cleanup_050v)
    /* Unwind info 0x7ffff70c */
    *(.text._Z38run_test_depth_15_error_65_cleanup_050v)
    /* Unwind info 0x7ffff728 */
    *(.text._Z38run_test_depth_05_error_65_cleanup_050v)
    /* Unwind info 0x7ffff760 */
    *(.text._Z38run_test_depth_35_error_65_cleanup_100v)
    /* Unwind info 0x7ffff7b4 */
    *(.text._ZN3hal7stm32f112gpio_manager6output12driver_levelEb)
    /* Unwind info 0x8003aab0 */
    *(.text._ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv)
    /* Unwind info 0x7fffff24 */
    *(.text.unlikely._ZSt19__throw_logic_errorPKc)
    /* Unwind info 0x7fffff30 */
    *(.text.unlikely._ZSt20__throw_length_errorPKc)
    /* Unwind info 0x7ffff7b8 */
    *(.text._ZN3hal7stm32f112gpio_manager6output12driver_levelEv)
    /* Unwind info 0x7fffff20 */
    *(.text.unlikely._ZSt17__throw_bad_allocv)
  }
}
INSERT BEFORE .text;
