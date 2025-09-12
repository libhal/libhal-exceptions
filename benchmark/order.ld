SECTIONS {
  .text.sorted : {
    /* LEAF & unsortable functions below */
    /* [0] Unwind info 0x00000001 */
    *(.text.unlikely._Z3endv)
    *(.text.unlikely._exit)
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
    *(.text._ZN3hal26single_exception_allocator11do_allocateEjj)
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
    /* [1] Unwind info 0x8003a8b0 */
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
    /* [2] Unwind info 0x8001a8b0 */
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
    /* [3] Unwind info 0x8002a9b0 */
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
    /* [4] Unwind info 0x8004afb0 */
    *(.text.startup.main)
    /* [5] Unwind info 0x8012afb0 */
    *(.text._ZNK10__cxxabiv121__vmi_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE)
    /* [6] Unwind info 0x8001aab0 */
    *(.text._ZN3hal7stm32f113configure_pinENS0_10pin_selectENS0_12pin_config_tE)
    *(.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEj)
    /* [7] Unwind info 0x80acb0b0 */
    *(.text._ZN3hal5delayERNS_12steady_clockENSt6chrono8durationIxSt5ratioILx1ELx1000000000EEEE.constprop.0)
    *(.text._ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE)
    *(.text._ZN9__gnu_cxx15__snprintf_liteEPcjPKcSt9__va_list)
    /* [8] Unwind info 0x80b108af */
    *(.text.__wrap___cxa_throw)
    /* [9] Unwind info 0x8008afb0 */
    *(.text._ZNK10__cxxabiv121__vmi_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE)
    /* [10] Unwind info 0x80a8b0b0 */
    *(.text.unlikely._ZN3hal7stm32f127throw_if_pin_is_unavailableENS0_10pin_selectE.part.0)
    *(.text.unlikely._ZN3hal7stm32f112_GLOBAL__N_124get_enable_register_infoENS0_10peripheralE.part.0)
    *(.text._ZNSt12length_errorC2EPKc)
    *(.text._ZNSt12out_of_rangeC2EPKc)
    *(.text._ZNSs4_Rep9_S_createEjjRKSaIcE)
    /* [11] Unwind info 0x7ffff024 */
    *(.text._Z20depth_01_percent_025v.isra.0)
    /* [12] Unwind info 0x8004a9b0 */
    *(.text._Z20depth_01_percent_000v.isra.0)
    /* [13] Unwind info 0x7ffff76c */
    *(.text._ZNK12_GLOBAL__N_122generic_error_category7messageB5cxx11Ei)
    /* [14] Unwind info 0x80b108a9 */
    *(.text.__wrap___cxa_rethrow)
    *(.text.__wrap___cxa_allocate_exception)
    /* [15] Unwind info 0x7ffff7a8 */
    *(.text._ZN3hal7stm32f14uartD2Ev)
    /* [16] Unwind info 0x7ffff7ac */
    *(.text._ZN3hal7stm32f14uartD0Ev)
    /* [17] Unwind info 0x80aab0b0 */
    *(.text._ZN3hal7stm32f112gpio_manager6output16driver_configureERKNS_10output_pin8settingsE)
    /* [18] Unwind info 0x8002afb0 */
    *(.text._ZNK10__cxxabiv121__vmi_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_)
    /* [19] Unwind info 0x7ffff790 */
    *(.text._ZNSt11logic_errorC2EPKc)
    /* [20] Unwind info 0x8002abb0 */
    *(.text._ZNSt12__cow_stringC2EPKcj)
    /* [21] Unwind info 0x7fffff48 */
    *(.text.unlikely._ZSt24__throw_out_of_range_fmtPKcz)
    /* [22] Unwind info 0x7ffff088 */
    *(.text._Z20depth_09_percent_100v.isra.0)
    /* [23] Unwind info 0x7ffff148 */
    *(.text._Z20depth_25_percent_100v.isra.0)
    /* [24] Unwind info 0x7ffff160 */
    *(.text._Z20depth_27_percent_100v.isra.0)
    /* [25] Unwind info 0x7ffff1f0 */
    *(.text._Z20depth_39_percent_100v.isra.0)
    /* [26] Unwind info 0x7ffff220 */
    *(.text._Z20depth_43_percent_100v.isra.0)
    /* [27] Unwind info 0x7ffff284 */
    *(.text._Z20depth_09_percent_050v.isra.0)
    /* [28] Unwind info 0x7ffff2a4 */
    *(.text._Z20depth_25_percent_050v.isra.0)
    /* [29] Unwind info 0x7ffff2a8 */
    *(.text._Z20depth_27_percent_050v.isra.0)
    /* [30] Unwind info 0x7ffff2c0 */
    *(.text._Z20depth_39_percent_050v.isra.0)
    /* [31] Unwind info 0x7ffff2c8 */
    *(.text._Z20depth_43_percent_050v.isra.0)
    /* [32] Unwind info 0x7ffff2dc */
    *(.text._Z20depth_09_percent_025v.isra.0)
    /* [33] Unwind info 0x7ffff2c4 */
    *(.text._Z20depth_25_percent_025v.isra.0)
    /* [34] Unwind info 0x7ffff058 */
    *(.text._Z20depth_05_percent_100v.isra.0)
    /* [35] Unwind info 0x7ffff0f4 */
    *(.text._Z20depth_18_percent_100v.isra.0)
    /* [36] Unwind info 0x7ffff100 */
    *(.text._Z20depth_19_percent_100v.isra.0)
    /* [37] Unwind info 0x7ffff130 */
    *(.text._Z20depth_23_percent_100v.isra.0)
    /* [38] Unwind info 0x7ffff13c */
    *(.text._Z20depth_24_percent_100v.isra.0)
    /* [39] Unwind info 0x7ffff190 */
    *(.text._Z20depth_31_percent_100v.isra.0)
    /* [40] Unwind info 0x7ffff19c */
    *(.text._Z20depth_32_percent_100v.isra.0)
    /* [41] Unwind info 0x7ffff1c0 */
    *(.text._Z20depth_35_percent_100v.isra.0)
    /* [42] Unwind info 0x7ffff1d8 */
    *(.text._Z20depth_37_percent_100v.isra.0)
    /* [43] Unwind info 0x7ffff1e4 */
    *(.text._Z20depth_38_percent_100v.isra.0)
    /* [44] Unwind info 0x7ffff22c */
    *(.text._Z20depth_44_percent_100v.isra.0)
    /* [45] Unwind info 0x7ffff238 */
    *(.text._Z20depth_45_percent_100v.isra.0)
    /* [46] Unwind info 0x7ffff244 */
    *(.text._Z20depth_46_percent_100v.isra.0)
    /* [47] Unwind info 0x7ffff27c */
    *(.text._Z20depth_05_percent_050v.isra.0)
    /* [48] Unwind info 0x7ffff298 */
    *(.text._Z20depth_19_percent_050v.isra.0)
    /* [49] Unwind info 0x7ffff2a0 */
    *(.text._Z20depth_23_percent_050v.isra.0)
    /* [50] Unwind info 0x7ffff2b0 */
    *(.text._Z20depth_31_percent_050v.isra.0)
    /* [51] Unwind info 0x7ffff2b8 */
    *(.text._Z20depth_35_percent_050v.isra.0)
    /* [52] Unwind info 0x7ffff2bc */
    *(.text._Z20depth_37_percent_050v.isra.0)
    /* [53] Unwind info 0x7ffff2cc */
    *(.text._Z20depth_45_percent_050v.isra.0)
    /* [54] Unwind info 0x7ffff2d8 */
    *(.text._Z20depth_05_percent_025v.isra.0)
    /* [55] Unwind info 0x7ffff2b8 */
    *(.text._Z20depth_38_percent_025v.isra.0)
    /* [56] Unwind info 0x7ffff2b8 */
    *(.text._Z20depth_46_percent_025v.isra.0)
    /* [57] Unwind info 0x7ffff780 */
    *(.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj)
    /* [58] Unwind info 0x7ffff040 */
    *(.text._Z20depth_03_percent_100v.isra.0)
    /* [59] Unwind info 0x7ffff04c */
    *(.text._Z20depth_04_percent_100v.isra.0)
    /* [60] Unwind info 0x7ffff064 */
    *(.text._Z20depth_06_percent_100v.isra.0)
    /* [61] Unwind info 0x7ffff070 */
    *(.text._Z20depth_07_percent_100v.isra.0)
    /* [62] Unwind info 0x7ffff07c */
    *(.text._Z20depth_08_percent_100v.isra.0)
    /* [63] Unwind info 0x7ffff094 */
    *(.text._Z20depth_10_percent_100v.isra.0)
    /* [64] Unwind info 0x7ffff0a0 */
    *(.text._Z20depth_11_percent_100v.isra.0)
    /* [65] Unwind info 0x7ffff0ac */
    *(.text._Z20depth_12_percent_100v.isra.0)
    /* [66] Unwind info 0x7ffff0c4 */
    *(.text._Z20depth_14_percent_100v.isra.0)
    /* [67] Unwind info 0x7ffff0d0 */
    *(.text._Z20depth_15_percent_100v.isra.0)
    /* [68] Unwind info 0x7ffff0dc */
    *(.text._Z20depth_16_percent_100v.isra.0)
    /* [69] Unwind info 0x7ffff10c */
    *(.text._Z20depth_20_percent_100v.isra.0)
    /* [70] Unwind info 0x7ffff124 */
    *(.text._Z20depth_22_percent_100v.isra.0)
    /* [71] Unwind info 0x7ffff154 */
    *(.text._Z20depth_26_percent_100v.isra.0)
    /* [72] Unwind info 0x7ffff16c */
    *(.text._Z20depth_28_percent_100v.isra.0)
    /* [73] Unwind info 0x7ffff1b4 */
    *(.text._Z20depth_34_percent_100v.isra.0)
    /* [74] Unwind info 0x7ffff1cc */
    *(.text._Z20depth_36_percent_100v.isra.0)
    /* [75] Unwind info 0x7ffff1fc */
    *(.text._Z20depth_40_percent_100v.isra.0)
    /* [76] Unwind info 0x7ffff208 */
    *(.text._Z20depth_41_percent_100v.isra.0)
    /* [77] Unwind info 0x7ffff214 */
    *(.text._Z20depth_42_percent_100v.isra.0)
    /* [78] Unwind info 0x7ffff250 */
    *(.text._Z20depth_47_percent_100v.isra.0)
    /* [79] Unwind info 0x7ffff268 */
    *(.text._Z20depth_49_percent_100v.isra.0)
    /* [80] Unwind info 0x7ffff274 */
    *(.text._Z20depth_50_percent_100v.isra.0)
    /* [81] Unwind info 0x7ffff278 */
    *(.text._Z20depth_03_percent_050v.isra.0)
    /* [82] Unwind info 0x7ffff280 */
    *(.text._Z20depth_07_percent_050v.isra.0)
    /* [83] Unwind info 0x7ffff288 */
    *(.text._Z20depth_11_percent_050v.isra.0)
    /* [84] Unwind info 0x7ffff290 */
    *(.text._Z20depth_15_percent_050v.isra.0)
    /* [85] Unwind info 0x7ffff2c4 */
    *(.text._Z20depth_41_percent_050v.isra.0)
    /* [86] Unwind info 0x7ffff2d0 */
    *(.text._Z20depth_47_percent_050v.isra.0)
    /* [87] Unwind info 0x7ffff2d4 */
    *(.text._Z20depth_49_percent_050v.isra.0)
    /* [88] Unwind info 0x7ffff2bc */
    *(.text._Z20depth_42_percent_025v.isra.0)
    /* [89] Unwind info 0x7ffff2ac */
    *(.text._Z20depth_50_percent_025v.isra.0)
    /* [90] Unwind info 0x80971cab */
    *(.text.unlikely._ZN9__gnu_cxx26__throw_insufficient_spaceEPKcS1_)
    /* [91] Unwind info 0x7ffff034 */
    *(.text._Z20depth_02_percent_100v.isra.0)
    /* [92] Unwind info 0x7ffff0b8 */
    *(.text._Z20depth_13_percent_100v.isra.0)
    /* [93] Unwind info 0x7ffff0e8 */
    *(.text._Z20depth_17_percent_100v.isra.0)
    /* [94] Unwind info 0x7ffff118 */
    *(.text._Z20depth_21_percent_100v.isra.0)
    /* [95] Unwind info 0x7ffff178 */
    *(.text._Z20depth_29_percent_100v.isra.0)
    /* [96] Unwind info 0x7ffff25c */
    *(.text._Z20depth_48_percent_100v.isra.0)
    /* [97] Unwind info 0x7ffff28c */
    *(.text._Z20depth_13_percent_050v.isra.0)
    /* [98] Unwind info 0x7ffff294 */
    *(.text._Z20depth_17_percent_050v.isra.0)
    /* [99] Unwind info 0x7ffff29c */
    *(.text._Z20depth_21_percent_050v.isra.0)
    /* [100] Unwind info 0x7ffff2ac */
    *(.text._Z20depth_29_percent_050v.isra.0)
    /* [101] Unwind info 0x7ffff2d0 */
    *(.text._Z20depth_13_percent_025v.isra.0)
    /* [102] Unwind info 0x7ffff2c4 */
    *(.text._Z20depth_17_percent_025v.isra.0)
    /* [103] Unwind info 0x7ffff2c0 */
    *(.text._Z20depth_21_percent_025v.isra.0)
    /* [104] Unwind info 0x7ffff2c8 */
    *(.text._Z20depth_29_percent_025v.isra.0)
    /* [105] Unwind info 0x7ffff020 */
    *(.text._ZN3hal7stm32f18power_onENS0_10peripheralE)
    /* [106] Unwind info 0x7ffff184 */
    *(.text._Z20depth_30_percent_100v.isra.0)
    /* [107] Unwind info 0x7ffff1a8 */
    *(.text._Z20depth_33_percent_100v.isra.0)
    /* [108] Unwind info 0x7ffff2b4 */
    *(.text._Z20depth_33_percent_050v.isra.0)
    /* [109] Unwind info 0x7ffff2c4 */
    *(.text._Z20depth_33_percent_025v.isra.0)
    /* [110] Unwind info 0x7ffff1c8 */
    *(.text._Z38run_test_depth_50_error_04_cleanup_000v)
    /* [111] Unwind info 0x7ffff1e4 */
    *(.text._Z38run_test_depth_35_error_04_cleanup_000v)
    /* [112] Unwind info 0x7ffff200 */
    *(.text._Z38run_test_depth_15_error_04_cleanup_000v)
    /* [113] Unwind info 0x7ffff21c */
    *(.text._Z38run_test_depth_05_error_04_cleanup_000v)
    /* [114] Unwind info 0x7ffff238 */
    *(.text._Z38run_test_depth_01_error_04_cleanup_000v)
    /* [115] Unwind info 0x7ffff254 */
    *(.text._Z38run_test_depth_50_error_04_cleanup_025v)
    /* [116] Unwind info 0x7ffff270 */
    *(.text._Z38run_test_depth_35_error_04_cleanup_025v)
    /* [117] Unwind info 0x7ffff28c */
    *(.text._Z38run_test_depth_15_error_04_cleanup_025v)
    /* [118] Unwind info 0x7ffff2a8 */
    *(.text._Z38run_test_depth_05_error_04_cleanup_025v)
    /* [119] Unwind info 0x7ffff2c4 */
    *(.text._Z38run_test_depth_01_error_04_cleanup_025v)
    /* [120] Unwind info 0x7ffff2e0 */
    *(.text._Z38run_test_depth_50_error_04_cleanup_050v)
    /* [121] Unwind info 0x7ffff2fc */
    *(.text._Z38run_test_depth_35_error_04_cleanup_050v)
    /* [122] Unwind info 0x7ffff318 */
    *(.text._Z38run_test_depth_15_error_04_cleanup_050v)
    /* [123] Unwind info 0x7ffff334 */
    *(.text._Z38run_test_depth_05_error_04_cleanup_050v)
    /* [124] Unwind info 0x7ffff350 */
    *(.text._Z38run_test_depth_50_error_04_cleanup_100v)
    /* [125] Unwind info 0x7ffff36c */
    *(.text._Z38run_test_depth_35_error_04_cleanup_100v)
    /* [126] Unwind info 0x7ffff388 */
    *(.text._Z38run_test_depth_15_error_04_cleanup_100v)
    /* [127] Unwind info 0x7ffff3a4 */
    *(.text._Z38run_test_depth_05_error_04_cleanup_100v)
    /* [128] Unwind info 0x7ffff3c0 */
    *(.text._Z38run_test_depth_50_error_16_cleanup_000v)
    /* [129] Unwind info 0x7ffff3dc */
    *(.text._Z38run_test_depth_35_error_16_cleanup_000v)
    /* [130] Unwind info 0x7ffff3f8 */
    *(.text._Z38run_test_depth_15_error_16_cleanup_000v)
    /* [131] Unwind info 0x7ffff414 */
    *(.text._Z38run_test_depth_05_error_16_cleanup_000v)
    /* [132] Unwind info 0x7ffff430 */
    *(.text._Z38run_test_depth_01_error_16_cleanup_000v)
    /* [133] Unwind info 0x7ffff44c */
    *(.text._Z38run_test_depth_50_error_16_cleanup_025v)
    /* [134] Unwind info 0x7ffff468 */
    *(.text._Z38run_test_depth_35_error_16_cleanup_025v)
    /* [135] Unwind info 0x7ffff484 */
    *(.text._Z38run_test_depth_15_error_16_cleanup_025v)
    /* [136] Unwind info 0x7ffff4a0 */
    *(.text._Z38run_test_depth_05_error_16_cleanup_025v)
    /* [137] Unwind info 0x7ffff4bc */
    *(.text._Z38run_test_depth_01_error_16_cleanup_025v)
    /* [138] Unwind info 0x7ffff4d8 */
    *(.text._Z38run_test_depth_50_error_16_cleanup_050v)
    /* [139] Unwind info 0x7ffff4f4 */
    *(.text._Z38run_test_depth_35_error_16_cleanup_050v)
    /* [140] Unwind info 0x7ffff510 */
    *(.text._Z38run_test_depth_15_error_16_cleanup_050v)
    /* [141] Unwind info 0x7ffff52c */
    *(.text._Z38run_test_depth_05_error_16_cleanup_050v)
    /* [142] Unwind info 0x7ffff548 */
    *(.text._Z38run_test_depth_50_error_16_cleanup_100v)
    /* [143] Unwind info 0x7ffff564 */
    *(.text._Z38run_test_depth_35_error_16_cleanup_100v)
    /* [144] Unwind info 0x7ffff580 */
    *(.text._Z38run_test_depth_15_error_16_cleanup_100v)
    /* [145] Unwind info 0x7ffff59c */
    *(.text._Z38run_test_depth_05_error_16_cleanup_100v)
    /* [146] Unwind info 0x7ffff5b8 */
    *(.text._Z38run_test_depth_50_error_65_cleanup_000v)
    /* [147] Unwind info 0x7ffff5d4 */
    *(.text._Z38run_test_depth_35_error_65_cleanup_000v)
    /* [148] Unwind info 0x7ffff5f0 */
    *(.text._Z38run_test_depth_15_error_65_cleanup_000v)
    /* [149] Unwind info 0x7ffff60c */
    *(.text._Z38run_test_depth_05_error_65_cleanup_000v)
    /* [150] Unwind info 0x7ffff628 */
    *(.text._Z38run_test_depth_01_error_65_cleanup_000v)
    /* [151] Unwind info 0x7ffff644 */
    *(.text._Z38run_test_depth_50_error_65_cleanup_025v)
    /* [152] Unwind info 0x7ffff660 */
    *(.text._Z38run_test_depth_35_error_65_cleanup_025v)
    /* [153] Unwind info 0x7ffff67c */
    *(.text._Z38run_test_depth_15_error_65_cleanup_025v)
    /* [154] Unwind info 0x7ffff698 */
    *(.text._Z38run_test_depth_05_error_65_cleanup_025v)
    /* [155] Unwind info 0x7ffff6b4 */
    *(.text._Z38run_test_depth_01_error_65_cleanup_025v)
    /* [156] Unwind info 0x7ffff6d0 */
    *(.text._Z38run_test_depth_50_error_65_cleanup_050v)
    /* [157] Unwind info 0x7ffff6ec */
    *(.text._Z38run_test_depth_35_error_65_cleanup_050v)
    /* [158] Unwind info 0x7ffff708 */
    *(.text._Z38run_test_depth_15_error_65_cleanup_050v)
    /* [159] Unwind info 0x7ffff724 */
    *(.text._Z38run_test_depth_05_error_65_cleanup_050v)
    /* [160] Unwind info 0x7ffff740 */
    *(.text._Z38run_test_depth_50_error_65_cleanup_100v)
    /* [161] Unwind info 0x7ffff75c */
    *(.text._Z38run_test_depth_35_error_65_cleanup_100v)
    /* [162] Unwind info 0x7ffff778 */
    *(.text._Z38run_test_depth_15_error_65_cleanup_100v)
    /* [163] Unwind info 0x7ffff794 */
    *(.text._Z38run_test_depth_05_error_65_cleanup_100v)
    /* [164] Unwind info 0x7ffff7b0 */
    *(.text._ZN3hal7stm32f112gpio_manager6output12driver_levelEb)
    /* [165] Unwind info 0x8003aab0 */
    *(.text._ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv)
    /* [166] Unwind info 0x7ffff778 */
    *(.text._ZNKSt3_V214error_category10_M_messageB5cxx11Ei)
    /* [167] Unwind info 0x7fffff30 */
    *(.text.unlikely._ZSt19__throw_logic_errorPKc)
    /* [168] Unwind info 0x7fffff3c */
    *(.text.unlikely._ZSt20__throw_length_errorPKc)
    /* [169] Unwind info 0x7ffff034 */
    *(.text._ZNSt5arrayISt8optionalIN6stdext16inplace_functionIFvbELj8ELj8EEEELj16EED2Ev)
    /* [170] Unwind info 0x7ffff7b4 */
    *(.text._ZN3hal7stm32f112gpio_manager6output12driver_levelEv)
    /* [171] Unwind info 0x7fffff2c */
    *(.text.unlikely._ZSt17__throw_bad_allocv)
    /* [172] Unwind info 0x7ffff778 */
    *(.text._ZN10__cxxabiv111__terminateEPFvvE)
    /* [173] Unwind info 0x7ffff794 */
    *(.text._ZNSt3pmr12_GLOBAL__N_110null_res_t11do_allocateEjj)
  }
}
INSERT BEFORE .text;
