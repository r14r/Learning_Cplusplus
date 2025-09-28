#include "demos.hpp"

#include <chrono>
#include <cstddef>
#include <exception>
#include <filesystem>
#include <future>
#include <iomanip>
#include <iostream>
#include <memory>
#include <numeric>
#include <random>
#include <stdexcept>
#include <string>
#include <thread>
#include <utility>
#include <vector>

namespace {
template <typename T>
T average(const std::vector<T> &values) {
    if (values.empty()) {
        throw std::invalid_argument("Cannot average an empty vector");
    }
    return std::accumulate(values.begin(), values.end(), T{}) /
           static_cast<T>(values.size());
}

struct Resource {
    explicit Resource(std::string name) : name(std::move(name)) {
        std::cout << "Acquiring resource: " << this->name << '\n';
    }
    ~Resource() { std::cout << "Releasing resource: " << name << '\n'; }

    std::string name;
};

void demonstrate_threads() {
    std::vector<int> values(1'000'000);
    std::iota(values.begin(), values.end(), 1);

    auto compute_sum = [&values](std::size_t begin, std::size_t end) {
        auto start = values.begin() + static_cast<std::ptrdiff_t>(begin);
        auto finish = values.begin() + static_cast<std::ptrdiff_t>(end);
        return std::accumulate(start, finish, 0LL);
    };

    auto mid = values.size() / 2;
    auto future_one = std::async(std::launch::async, compute_sum, 0, mid);
    auto future_two = std::async(std::launch::async, compute_sum, mid, values.size());

    auto total = future_one.get() + future_two.get();
    std::cout << "Concurrency -> sum 1..1,000,000 = " << total << '\n';
}
} // namespace

void run_advanced_demo() {
    print_section("3. Modern C++ features");

    std::vector<double> samples{2.0, 4.0, 6.0, 8.0};
    try {
        std::cout << "Templates -> average = " << average(samples) << '\n';
    } catch (const std::exception &ex) {
        std::cout << "Error computing average: " << ex.what() << '\n';
    }

    {
        std::shared_ptr<Resource> shared = std::make_shared<Resource>("database");
        std::weak_ptr<Resource> observer = shared;
        std::cout << "Smart pointers -> use_count = " << shared.use_count() << '\n';
        if (auto locked = observer.lock()) {
            std::cout << "Observer locked resource: " << locked->name << '\n';
        }
    }

    auto safe_divide = [](int a, int b) {
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        return static_cast<double>(a) / static_cast<double>(b);
    };

    try {
        std::cout << "Exceptions -> 10 / 2 = " << safe_divide(10, 2) << '\n';
        std::cout << "Exceptions -> 5 / 0 = ";
        std::cout << safe_divide(5, 0) << '\n';
    } catch (const std::exception &ex) {
        std::cout << "caught " << ex.what() << '\n';
    }

    demonstrate_threads();

    std::filesystem::path config_path{"config/settings.json"};
    std::cout << "Filesystem -> " << config_path << " (exists? "
              << std::boolalpha << std::filesystem::exists(config_path) << ")\n";

    std::cout << std::noboolalpha;
}
