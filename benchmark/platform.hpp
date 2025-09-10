#pragma once

#include <string_view>

void initialize_platform();
void log_start(std::string_view p_message);
void link_filler_functions();
void run_test();
void start();
void end();
void start_sub();
void end_sub();
void pause();
void end_benchmark();
