#include <chrono>
#include <random>
#include <vector>
#include <matplot/matplot.h>
#include <iostream>
#include "solutions.cpp" 

Solution PROBLEM{};
std::ostringstream TEST_DATA{};

int measure(bool second, int n) {
    PROBLEM.prepare(TEST_DATA.str());
    auto start = std::chrono::system_clock::now();
    if (second) {
        PROBLEM.solve_second(n);
    } else {
        PROBLEM.solve_first(n);
    }
    auto end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

int main() {
    std::mt19937 rng{1337};
    unsigned int test_values[20000];
    size_t j = 0;
    while (j < 20000) {
        auto num = rng();
        if (num < 200001) {
            test_values[j] = num;
            ++j;
        }
    }

    std::vector<int> results[2];
    for (size_t i = 0; i < 20000; i++) {
        TEST_DATA << test_values[i] << ' ';
        results[0].push_back(measure(false, i+1));
        // results[1].push_back(measure(true, i+1));
    }
    

    std::vector<int> range;
    for (size_t i = 1; i < 20001; i++) {
        range.push_back(i);
    }

    matplot::plot(range, results[0], ".");
    // matplot::plot(range, results[1], "+");
    matplot::show();
}