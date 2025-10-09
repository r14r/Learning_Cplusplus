#include "demos.hpp"

#include <algorithm>
#include <iostream>
#include <string>

std::string make_title(const std::string &title) {
    const std::string border(title.size() + 8, '=');
    return border + "\n==  " + title + "  ==\n" + border;
}

void print_section(const std::string &title) {
    const std::string border(title.size() + 4, '-');
    std::cout << "\n" << border << "\n" << title << "\n" << border << '\n';
}
