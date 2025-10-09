#include "demos.hpp"

#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

namespace {
int add(int a, int b) {
    return a + b;
}

double hypotenuse(double a, double b) {
    return std::sqrt(a * a + b * b);
}

std::optional<int> find_value(const std::map<std::string, int> &scores,
                              const std::string &name) {
    if (auto it = scores.find(name); it != scores.end()) {
        return it->second;
    }
    return std::nullopt;
}
} // namespace

void run_basics_demo() {
    print_section("1. Language basics");

    int age = 21;
    double temperature = 24.5;
    std::string name = "Avery";
    std::cout << "Variables -> name: " << name << ", age: " << age
              << ", temperature: " << temperature << '\n';

    std::array<int, 3> favourite_numbers{3, 7, 42};
    std::cout << "Array contents:";
    for (int number : favourite_numbers) {
        std::cout << ' ' << number;
    }
    std::cout << '\n';

    std::vector<std::string> shopping_list{"apples", "bread", "milk"};
    shopping_list.push_back("coffee");
    std::cout << "Vector contents:";
    for (const auto &item : shopping_list) {
        std::cout << ' ' << item;
    }
    std::cout << '\n';

    auto sum = add(4, 9);
    std::cout << "Function call -> add(4, 9) = " << sum << '\n';

    auto lambda = [](int value) { return value % 2 == 0; };
    std::cout << "Lambda expression -> 6 is even? " << std::boolalpha << lambda(6)
              << '\n';

    auto [first, second, third] = std::tuple{1, 2, 3};
    std::cout << "Structured bindings -> first: " << first
              << ", second: " << second << ", third: " << third << '\n';

    std::map<std::string, int> scores{{"math", 95}, {"science", 88}, {"art", 73}};
    std::cout << "Associative container -> scores[math] = " << scores["math"]
              << '\n';

    if (auto maybe_science = find_value(scores, "science")) {
        std::cout << "Optional value -> science score = " << *maybe_science << '\n';
    }

    std::cout << "Numeric algorithms -> hypotenuse(3, 4) = " << hypotenuse(3.0, 4.0)
              << '\n';

    std::vector<int> numbers{1, 2, 3, 4, 5};
    auto total = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Standard algorithms -> sum(1..5) = " << total << '\n';

    std::cout << std::noboolalpha;
}
