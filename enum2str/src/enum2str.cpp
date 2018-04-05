//============================================================================
// Name        : enum2str.cpp
// Author      : frv
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <chrono>

#include "global_types.h"

int main() {
    std::cout << "!!!Conversion enum from/to std::string !!!" << std::endl;

    std::string test_var = "http";

    TrafficType enum_var;

    using milli = std::chrono::milliseconds;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        enum_var = TrafficType_str2enum(test_var);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "str2enum(), map based took "
            << std::chrono::duration_cast<milli>(finish - start).count()
            << " milliseconds\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        enum_var = TrafficType_str2enum_v0(test_var);
    }
    finish = std::chrono::high_resolution_clock::now();
    std::cout << "str2enum_v0(), if else based took "
            << std::chrono::duration_cast<milli>(finish - start).count()
            << " milliseconds\n";

    std::cout << "As string: " << TrafficType_enum2str(enum_var) << std::endl;

    return 0;
}
