#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_set>
#include <sstream>

struct ISolution {
    virtual void operator()(std::vector<int> &cin) const = 0;
};

struct FirstSolution : ISolution {
    void operator()(std::vector<int> &cin) const override {
        int n = cin.size();
        std::vector<int> as(200001, -1);
        for (int i = 0; i < n; i += 1) {
            int idx = cin[i];
            as[idx] = n - i - 1;
        }
        std::distance(as.begin(), std::max_element(as.begin(), as.end()));
    }
};

struct SecondSolution : ISolution {
    void operator()(std::vector<int> &cin) const override {
        int n = cin.size();
        std::unordered_set<int> unique;
        unique.reserve(200000);
        int idx_unique = n;
        for (int i = n - 1; 0 <= i; i -= 1) {
            if (!unique.contains(cin[i]))
            {
                idx_unique = cin[i];
                unique.insert(idx_unique);
            }
        }
    }
};