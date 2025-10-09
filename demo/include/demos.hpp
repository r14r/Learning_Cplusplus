#pragma once

#include <string>

// Runs a series of demonstrations covering core C++ language features.
void run_basics_demo();
void run_oop_demo();
void run_advanced_demo();

// Utility helpers shared across demos.
std::string make_title(const std::string &title);
void print_section(const std::string &title);
