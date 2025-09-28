#include "demos.hpp"

#include <iostream>

int main() {
    std::cout << make_title("Learning C++ - Feature Walkthrough") << '\n';

    run_basics_demo();
    run_oop_demo();
    run_advanced_demo();

    std::cout << "\nAll demonstrations complete!" << std::endl;
    return 0;
}
