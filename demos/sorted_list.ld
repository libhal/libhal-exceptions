
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
    _ZSt17__throw_bad_allocv = .;
    abort = .;
    _GLOBAL__sub_I__ZNSt3pmr15memory_resourceD2Ev = .;
    _GLOBAL__sub_I___cxa_get_globals_fast = .;
    _start = .;
    deregister_tm_clones = .;
    register_tm_clones = .;
    __do_global_dtors_aux = .;
    frame_dummy = .;
    _Z41__static_initialization_and_destruction_0ii = .;
    _ZN3hal13set_terminateEPFvvE = .;
    _ZN3hal13get_terminateEv = .;
    _ZN3hal23set_exception_allocatorEPNSt3pmr15memory_resourceE = .;
    _ZN3hal23get_exception_allocatorEv = .;
    _GLOBAL__sub_I__ZN10__cxxabiv119__terminate_handlerE = .;
    _ZN10__cxxabiv119__terminate_handlerMUlvE_4_FUNEv = .;
    _ZN3hal26single_exception_allocatorILj256EE11do_allocateEjj = .;
    _ZNK3hal26single_exception_allocatorILj256EE11do_is_equalERKNSt3pmr15memory_resourceE = .;
    _ZN3hal26single_exception_allocatorILj256EE13do_deallocateEPvjj = .;
    _ZN3hal26single_exception_allocatorILj256EED2Ev = .;
    _ZN3hal26single_exception_allocatorILj256EED0Ev = .;
    _ZN2ke8get_su16EPv = .;
    _ZN2ke6get_luEPv = .;
    _ZN2ke17current_exceptionEv = .;
    _ZN2ke23get_arm_exception_indexEv = .;
    _ZN2ke13get_rtti_typeEPKv = .;
    _ZN2ke22extract_si_parent_infoEPKv = .;
    _exit = .;
    __wrap___cxa_allocate_exception = .;
    __wrap___cxa_call_unexpected = .;
    __wrap___cxa_begin_catch = .;
    _ZN2ke12unwind_frameERKNS_14instructions_tERNS_12cortex_m_cpuE = .;
    _ZN2ke15get_index_entryEm = .;
    _ZN2ke15raise_exceptionERNS_16exception_objectE = .;
    __wrap___cxa_end_cleanup = .;
    __wrap___cxa_rethrow = .;
    __wrap___cxa_throw = .;
    __wrap___cxa_free_exception = .;
    __wrap___cxa_end_catch = .;
    _ZN2ke15index_less_thanclEmRKNS_13index_entry_tE = .;
    _ZN2ke7to_lsdaERNS_16exception_objectE = .;
    _ZN2ke18multi_read_uleb128ILj4EEENS_17decoded_uleb128_tIXT_EEEPKh = .;
    _ZN2ke23parse_uleb128_call_siteEPKhmS1_ = .;
    _ZN2ke2asIPKjEEPKT_PKv = .;
    _ZN2ke14action_decoder33get_current_type_info_from_filterEv = .;
    _ZN2ke14action_decoder19get_next_catch_typeEv = .;
    _ZN2ke15parse_call_siteILNS_13lsda_encodingE9EEENS_14call_site_infoEPPKhmS4_ = .;
    _ZN2ke18pop_register_rangeILj7ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE = .;
    _ZN2ke18pop_register_rangeILj6ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE = .;
    _ZN2ke18pop_register_rangeILj5ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE = .;
    _ZN2ke18pop_register_rangeILj4ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE = .;
    _ZN2ke18pop_register_rangeILj3ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE = .;
    _ZN2ke18pop_register_rangeILj2ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE = .;
    _ZN2ke18pop_register_rangeILj1ELNS_6pop_lrE1EEEPKmS3_RNS_12cortex_m_cpuE = .;
    _ZN2ke2asItEEPKT_PKv = .;
    _ZN2ke15parse_call_siteILNS_13lsda_encodingE2EEENS_14call_site_infoEPPKhmS4_ = .;
    _ZN2ke2asImEEPKT_PKv = .;
    _ZN2ke15parse_call_siteILNS_13lsda_encodingE3EEENS_14call_site_infoEPPKhmS4_ = .;
    _ZN2ke2asIsEEPKT_PKv = .;
    _ZN2ke15parse_call_siteILNS_13lsda_encodingE10EEENS_14call_site_infoEPPKhmS4_ = .;
    _ZN2ke2asIlEEPKT_PKv = .;
    _ZN2ke15parse_call_siteILNS_13lsda_encodingE11EEENS_14call_site_infoEPPKhmS4_ = .;
    _ZN2ke2asIxEEPKT_PKv = .;
    _ZN2ke15parse_call_siteILNS_13lsda_encodingE12EEENS_14call_site_infoEPPKhmS4_ = .;
    _ZN2ke2asIyEEPKT_PKv = .;
    _ZN2ke15skip_dwarf_infoEPPKh = .;
    _ZN2ke12parse_headerEPPKh = .;
    _ZN2ke15parse_call_siteILNS_13lsda_encodingE4EEENS_14call_site_infoEPPKhmS4_ = .;
    _ZN2ke19flattened_hierarchyILj12EE9push_backERKNS_20base_class_type_infoE = .;
    _ZSt9__advanceIN9__gnu_cxx17__normal_iteratorIPKN2ke13index_entry_tESt4spanIS4_Lj4294967295EEEEiEvRT_T0_St26random_access_iterator_tag = .;
    _ZSt13__upper_boundIN9__gnu_cxx17__normal_iteratorIPKN2ke13index_entry_tESt4spanIS4_Lj4294967295EEEEmNS0_5__ops14_Val_comp_iterINS2_15index_less_thanEEEET_SD_SD_RKT0_T1_ = .;
    _ZSt9__find_ifIPN2ke20base_class_type_infoEN9__gnu_cxx5__ops10_Iter_predIZNS0_14enter_functionERNS0_16exception_objectEEUlRKT_E_EEES8_S8_S8_T0_St26random_access_iterator_tag = .;
    _ZSt7find_ifIPN2ke20base_class_type_infoEZNS0_14enter_functionERNS0_16exception_objectEEUlRKT_E_ES5_S5_S5_T0_ = .;
    _ZN2ke14enter_functionERNS_16exception_objectE = .;
    _ZN2ke2asIKhEEPKT_PKv = .;
    _ZN2ke2asIPKiEEPKT_PKv = .;
    _ZN2ke13push_vmi_infoILj12EEEvPvRNS_20base_class_type_infoERNS_19flattened_hierarchyIXT_EEE = .;
    _ZN2ke12flatten_rttiILj12EEEvPvRNS_19flattened_hierarchyIXT_EEEPKSt9type_info = .;
    _ZSt9__fill_a1IhEN9__gnu_cxx11__enable_ifIXsrSt9__is_byteIT_E7__valueEvE6__typeEPS3_S7_RKS3_ = .;
    __wrap___gnu_unwind_pr_common = .;
    __wrap___aeabi_unwind_cpp_pr0 = .;
    __wrap__sig_func = .;
    __wrap___gxx_personality_v0 = .;
    __wrap_deregister_tm_clones = .;
    __wrap_register_tm_clones = .;
    _Z11applicationR13resource_list = .;
    _Z14funct_group0_5v = .;
    _Z14funct_group0_4v = .;
    _Z14funct_group0_3v = .;
    _Z14funct_group0_2v = .;
    _Z14funct_group0_1v = .;
    _Z14funct_group0_0v = .;
    _Z15funct_group1_11v = .;
    _Z15funct_group1_10v = .;
    _Z14funct_group1_9v = .;
    _Z14funct_group1_8v = .;
    _Z14funct_group1_7v = .;
    _Z14funct_group1_6v = .;
    _Z14funct_group1_5v = .;
    _Z14funct_group1_4v = .;
    _Z14funct_group1_3v = .;
    _Z14funct_group1_2v = .;
    _Z14funct_group1_1v = .;
    _Z14funct_group1_0v = .;
    _Z15funct_group2_23v = .;
    _Z15funct_group2_22v = .;
    _Z15funct_group2_21v = .;
    _Z15funct_group2_20v = .;
    _Z15funct_group2_19v = .;
    _Z15funct_group2_18v = .;
    _Z15funct_group2_17v = .;
    _Z15funct_group2_16v = .;
    _Z15funct_group2_15v = .;
    _Z15funct_group2_14v = .;
    _Z15funct_group2_13v = .;
    _Z15funct_group2_12v = .;
    _Z15funct_group2_11v = .;
    _Z15funct_group2_10v = .;
    _Z14funct_group2_9v = .;
    _Z14funct_group2_8v = .;
    _Z14funct_group2_7v = .;
    _Z14funct_group2_6v = .;
    _Z14funct_group2_5v = .;
    _Z14funct_group2_4v = .;
    _Z14funct_group2_3v = .;
    _Z14funct_group2_2v = .;
    _Z14funct_group2_1v = .;
    _Z14funct_group2_0v = .;
    _Z15funct_group3_47v = .;
    _Z15funct_group3_46v = .;
    _Z15funct_group3_45v = .;
    _Z15funct_group3_44v = .;
    _Z15funct_group3_43v = .;
    _Z15funct_group3_42v = .;
    _Z15funct_group3_41v = .;
    _Z15funct_group3_40v = .;
    _Z15funct_group3_39v = .;
    _Z15funct_group3_38v = .;
    _Z15funct_group3_37v = .;
    _Z15funct_group3_36v = .;
    _Z15funct_group3_35v = .;
    _Z15funct_group3_34v = .;
    _Z15funct_group3_33v = .;
    _Z15funct_group3_32v = .;
    _Z15funct_group3_31v = .;
    _Z15funct_group3_30v = .;
    _Z15funct_group3_29v = .;
    _Z15funct_group3_28v = .;
    _Z15funct_group3_27v = .;
    _Z15funct_group3_26v = .;
    _Z15funct_group3_25v = .;
    _Z15funct_group3_24v = .;
    _Z15funct_group3_23v = .;
    _Z15funct_group3_22v = .;
    _Z15funct_group3_21v = .;
    _Z15funct_group3_20v = .;
    _Z15funct_group3_19v = .;
    _Z15funct_group3_18v = .;
    _Z15funct_group3_17v = .;
    _Z15funct_group3_16v = .;
    _Z15funct_group3_15v = .;
    _Z15funct_group3_14v = .;
    _Z15funct_group3_13v = .;
    _Z15funct_group3_12v = .;
    _Z15funct_group3_11v = .;
    _Z15funct_group3_10v = .;
    _Z14funct_group3_9v = .;
    _Z14funct_group3_8v = .;
    _Z14funct_group3_7v = .;
    _Z14funct_group3_6v = .;
    _Z14funct_group3_5v = .;
    _Z14funct_group3_4v = .;
    _Z14funct_group3_3v = .;
    _Z14funct_group3_2v = .;
    _Z14funct_group3_1v = .;
    _Z14funct_group3_0v = .;
    _Z15funct_group4_95v = .;
    _Z15funct_group4_94v = .;
    _Z15funct_group4_93v = .;
    _Z15funct_group4_92v = .;
    _Z15funct_group4_91v = .;
    _Z15funct_group4_90v = .;
    _Z15funct_group4_89v = .;
    _Z15funct_group4_88v = .;
    _Z15funct_group4_87v = .;
    _Z15funct_group4_86v = .;
    _Z15funct_group4_85v = .;
    _Z15funct_group4_84v = .;
    _Z15funct_group4_83v = .;
    _Z15funct_group4_82v = .;
    _Z15funct_group4_81v = .;
    _Z15funct_group4_80v = .;
    _Z15funct_group4_79v = .;
    _Z15funct_group4_78v = .;
    _Z15funct_group4_77v = .;
    _Z15funct_group4_76v = .;
    _Z15funct_group4_75v = .;
    _Z15funct_group4_74v = .;
    _Z15funct_group4_73v = .;
    _Z15funct_group4_72v = .;
    _Z15funct_group4_71v = .;
    _Z15funct_group4_70v = .;
    _Z15funct_group4_69v = .;
    _Z15funct_group4_68v = .;
    _Z15funct_group4_67v = .;
    _Z15funct_group4_66v = .;
    _Z15funct_group4_65v = .;
    _Z15funct_group4_64v = .;
    _Z15funct_group4_63v = .;
    _Z15funct_group4_62v = .;
    _Z15funct_group4_61v = .;
    _Z15funct_group4_60v = .;
    _Z15funct_group4_59v = .;
    _Z15funct_group4_58v = .;
    _Z15funct_group4_57v = .;
    _Z15funct_group4_56v = .;
    _Z15funct_group4_55v = .;
    _Z15funct_group4_54v = .;
    _Z15funct_group4_53v = .;
    _Z15funct_group4_52v = .;
    _Z15funct_group4_51v = .;
    _Z15funct_group4_50v = .;
    _Z15funct_group4_49v = .;
    _Z15funct_group4_48v = .;
    _Z15funct_group4_47v = .;
    _Z15funct_group4_46v = .;
    _Z15funct_group4_45v = .;
    _Z15funct_group4_44v = .;
    _Z15funct_group4_43v = .;
    _Z15funct_group4_42v = .;
    _Z15funct_group4_41v = .;
    _Z15funct_group4_40v = .;
    _Z15funct_group4_39v = .;
    _Z15funct_group4_38v = .;
    _Z15funct_group4_37v = .;
    _Z15funct_group4_36v = .;
    _Z15funct_group4_35v = .;
    _Z15funct_group4_34v = .;
    _Z15funct_group4_33v = .;
    _Z15funct_group4_32v = .;
    _Z15funct_group4_31v = .;
    _Z15funct_group4_30v = .;
    _Z15funct_group4_29v = .;
    _Z15funct_group4_28v = .;
    _Z15funct_group4_27v = .;
    _Z15funct_group4_26v = .;
    _Z15funct_group4_25v = .;
    _Z15funct_group4_24v = .;
    _Z15funct_group4_23v = .;
    _Z15funct_group4_22v = .;
    _Z15funct_group4_21v = .;
    _Z15funct_group4_20v = .;
    _Z15funct_group4_19v = .;
    _Z15funct_group4_18v = .;
    _Z15funct_group4_17v = .;
    _Z15funct_group4_16v = .;
    _Z15funct_group4_15v = .;
    _Z15funct_group4_14v = .;
    _Z15funct_group4_13v = .;
    _Z15funct_group4_12v = .;
    _Z15funct_group4_11v = .;
    _Z15funct_group4_10v = .;
    _Z14funct_group4_9v = .;
    _Z14funct_group4_8v = .;
    _Z14funct_group4_7v = .;
    _Z14funct_group4_6v = .;
    _Z14funct_group4_5v = .;
    _Z14funct_group4_4v = .;
    _Z14funct_group4_3v = .;
    _Z14funct_group4_2v = .;
    _Z14funct_group4_1v = .;
    _Z14funct_group4_0v = .;
    _Z14funct_group5_5v = .;
    _Z14funct_group5_4v = .;
    _Z14funct_group5_3v = .;
    _Z14funct_group5_2v = .;
    _Z14funct_group5_1v = .;
    _Z14funct_group5_0v = .;
    _Z15funct_group6_11v = .;
    _Z15funct_group6_10v = .;
    _Z14funct_group6_9v = .;
    _Z14funct_group6_8v = .;
    _Z14funct_group6_7v = .;
    _Z14funct_group6_6v = .;
    _Z14funct_group6_5v = .;
    _Z14funct_group6_4v = .;
    _Z14funct_group6_3v = .;
    _Z14funct_group6_2v = .;
    _Z14funct_group6_1v = .;
    _Z14funct_group6_0v = .;
    _ZN7class_0C1El = .;
    _ZN7class_07triggerEv = .;
    _ZN7class_1C2El = .;
    _ZN7class_17triggerEv = .;
    _Z17terminate_handlerv = .;
    main = .;
    _Z19initialize_platformv = .;
    _ZN3hal8cortex_m11dwt_counterD2Ev = .;
    _ZN3hal8cortex_m11dwt_counterD0Ev = .;
    _ZN3hal8cortex_m11dwt_counter13driver_uptimeEv = .;
    _ZN3hal8cortex_m11dwt_counter16driver_frequencyEv = .;
    _ZN3hal8cortex_m11dwt_counterC2Ef = .;
    _ZN3hal8cortex_m11dwt_counter22register_cpu_frequencyEf = .;
    _ZN3hal7stm32f116configure_clocksENS0_10clock_treeE = .;
    _ZN3hal7stm32f19frequencyENS0_10peripheralE = .;
    _ZN3hal7stm32f139maximum_speed_using_internal_oscillatorEv = .;
    __aeabi_atexit = .;
    _ZNKSt9bad_alloc4whatEv = .;
    _ZNSt9bad_allocD1Ev = .;
    _ZNSt9bad_allocD0Ev = .;
    _ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv = .;
    _ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_ = .;
    _ZN10__cxxabiv117__class_type_infoD2Ev = .;
    _ZN10__cxxabiv117__class_type_infoD0Ev = .;
    _ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE = .;
    _ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE = .;
    _ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj = .;
    _ZdlPvj = .;
    _ZNSt9exceptionD1Ev = .;
    _ZNKSt9exception4whatEv = .;
    _ZNSt9exceptionD0Ev = .;
    _ZN10__cxxabiv111__terminateEPFvvE = .;
    _ZSt9terminatev = .;
    __cxa_guard_acquire = .;
    __cxa_guard_abort = .;
    __cxa_guard_release = .;
    _ZN9__gnu_cxx20recursive_init_errorD2Ev = .;
    _ZN9__gnu_cxx20recursive_init_errorD0Ev = .;
    _ZN9__gnu_cxx20recursive_init_errorC1Ev = .;
    _ZN10__cxxabiv120__si_class_type_infoD1Ev = .;
    _ZN10__cxxabiv120__si_class_type_infoD0Ev = .;
    _ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_ = .;
    _ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE = .;
    _ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE = .;
    _ZNSt9type_infoD2Ev = .;
    _ZNKSt9type_info14__is_pointer_pEv = .;
    _ZNKSt9type_infoeqERKS_ = .;
    _ZN10__cxxabiv121__vmi_class_type_infoD2Ev = .;
    _ZN10__cxxabiv121__vmi_class_type_infoD0Ev = .;
    _ZNK10__cxxabiv121__vmi_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_ = .;
    _ZNK10__cxxabiv121__vmi_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE = .;
    _ZNK10__cxxabiv121__vmi_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE = .;
    _ZNKSt3pmr12_GLOBAL__N_110null_res_t11do_is_equalERKNS_15memory_resourceE = .;
    _ZNSt3pmr12_GLOBAL__N_110null_res_t13do_deallocateEPvjj = .;
    _ZNSt3pmr12_GLOBAL__N_110null_res_tD1Ev = .;
    _ZNSt3pmr12_GLOBAL__N_112newdel_res_tD1Ev = .;
    _ZNSt3pmr12_GLOBAL__N_113constant_initINS0_12newdel_res_tEED1Ev = .;
    _ZNSt3pmr12_GLOBAL__N_113constant_initINS0_10null_res_tEED1Ev = .;
    _ZNSt3pmr12_GLOBAL__N_113constant_initISt6atomicIPNS_15memory_resourceEEED1Ev = .;
    _ZNSt3pmr12_GLOBAL__N_112newdel_res_tD0Ev = .;
    _ZNSt3pmr12_GLOBAL__N_110null_res_tD0Ev = .;
    _ZNSt3pmr12_GLOBAL__N_112newdel_res_t13do_deallocateEPvjj = .;
    _ZNSt3pmr12_GLOBAL__N_112newdel_res_t11do_allocateEjj = .;
    _ZNSt3pmr12_GLOBAL__N_110null_res_t11do_allocateEjj = .;
    _ZNSt3pmr15memory_resourceD1Ev = .;
    _ZdlPv = .;
    _ZdlPvjSt11align_val_t = .;
    _ZnwjSt11align_val_t = .;
    _ZdlPvSt11align_val_t = .;
    _ZN12_GLOBAL__N_113constant_initD1Ev = .;
    _ZSt15get_new_handlerv = .;
    __aeabi_frsub = .;
    __aeabi_fsub = .;
    __addsf3 = .;
    __floatunsisf = .;
    __floatsisf = .;
    __aeabi_ul2f = .;
    __aeabi_l2f = .;
    __aeabi_fmul = .;
    __aeabi_fdiv = .;
    __gesf2 = .;
    __ltsf2 = .;
    __cmpsf2 = .;
    __aeabi_cfrcmple = .;
    __aeabi_cfcmpeq = .;
    __aeabi_fcmpeq = .;
    __aeabi_fcmplt = .;
    __aeabi_fcmple = .;
    __aeabi_fcmpge = .;
    __aeabi_fcmpgt = .;
    __popcountsi2 = .;
    selfrel_offset31 = .;
    search_EIT_table = .;
    __gnu_unwind_get_pr_addr = .;
    get_eit_entry = .;
    restore_non_core_regs = .;
    _Unwind_decode_typeinfo_ptr.constprop.0 = .;
    _Unwind_DebugHook = .;
    unwind_phase2 = .;
    unwind_phase2_forced = .;
    __gnu_Unwind_RaiseException = .;
    __gnu_Unwind_ForcedUnwind = .;
    __gnu_Unwind_Resume = .;
    __gnu_Unwind_Resume_or_Rethrow = .;
    _Unwind_VRS_Get = .;
    _Unwind_GetGR = .;
    _Unwind_VRS_Set = .;
    _Unwind_SetGR = .;
    __gnu_Unwind_Backtrace = .;
    __gnu_unwind_pr_common = .;
    __aeabi_unwind_cpp_pr0 = .;
    __aeabi_unwind_cpp_pr1 = .;
    __aeabi_unwind_cpp_pr2 = .;
    _Unwind_VRS_Pop = .;
    restore_core_regs = .;
    __gnu_Unwind_Restore_VFP = .;
    __gnu_Unwind_Save_VFP = .;
    __gnu_Unwind_Restore_VFP_D = .;
    __gnu_Unwind_Save_VFP_D = .;
    __gnu_Unwind_Restore_VFP_D_16_to_31 = .;
    __gnu_Unwind_Save_VFP_D_16_to_31 = .;
    __gnu_Unwind_Restore_WMMXD = .;
    __gnu_Unwind_Save_WMMXD = .;
    __gnu_Unwind_Restore_WMMXC = .;
    __gnu_Unwind_Save_WMMXC = .;
    _Unwind_RaiseException = .;
    _Unwind_Resume = .;
    ___Unwind_Resume_or_Rethrow = .;
    _Unwind_ForcedUnwind = .;
    ___Unwind_Backtrace = .;
    next_unwind_byte = .;
    __gnu_unwind_execute = .;
    strcmp = .;
    __aeabi_memcpy8 = .;
    memset = .;
    free = .;
    __malloc_sbrk_aligned = .;
    __malloc_grow_chunk = .;
    __malloc_malloc = .;
    aligned_alloc = .;
    __libc_init_array = .;
    __retarget_lock_acquire_recursive = .;
    __retarget_lock_release_recursive = .;
    __cxa_atexit = .;
    sbrk = .;
    arm_usagefault_isr = .;
    arm_nmi_isr = .;
    raise = .;
    _on_exit = .;

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
