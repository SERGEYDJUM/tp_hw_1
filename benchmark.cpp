#include <chrono>
#include <random>
#include <vector>
#include <matplot/matplot.h>
#include <iostream>
#include "solutions.cpp" 

struct TestData {
    std::mt19937 mte{1337};
    std::uniform_int_distribution<> distr{0, 200000};

    std::vector<int> get_case(int size) {
        std::vector<int> test_case{};
        for (size_t j = 0; j < size; j++) {
            test_case.push_back(distr(mte));
        }
        return test_case;
    }
};

struct Benchmark {
    FirstSolution fsol{};
    SecondSolution ssol{};
    TestData tests{};

    std::vector<int> sizes{};
    std::vector<int> res_first{};
    std::vector<int> res_second{};

    Benchmark(int step = 10000) {
        for (size_t i = 0; i <= 200000; i+=step) {
            sizes.push_back(i);
        }
    }

    int measure(std::vector<int> &test_case, ISolution &solver) {
        auto start = std::chrono::high_resolution_clock::now();
        solver(test_case);
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    void run(int avg_over = 5) {
        for (size_t j = 0; j < sizes.size(); j++) {
            int time_sum_f = 0;
            int time_sum_s = 0;
            for (size_t i = 0; i < avg_over; i++) {
                auto test_case = tests.get_case(sizes[j]);
                time_sum_f += measure(test_case, fsol);
                time_sum_s += measure(test_case, ssol);
            }
            res_first.push_back(time_sum_f/avg_over);
            res_second.push_back(time_sum_s/avg_over);
        }
    }
};

int main() {
    Benchmark bench{5000};
    bench.run(5);
    matplot::plot(bench.sizes, bench.res_first);
    matplot::show();
}