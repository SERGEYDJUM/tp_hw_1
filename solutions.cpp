#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <string>

struct Solution {
    std::istringstream cin;
    std::ostringstream cout;

    Solution() {}

    void prepare(const std::string &inp) {
        cin = std::istringstream(inp);
    }

    void solve_first(int n) {
        std::vector<int> as(200001, -1);
        for (int i = 0; i < n; i += 1) {
            int idx = 0;
            cin >> idx;
            as[idx] = n - i - 1;
        }
        cout << std::distance(as.begin(), std::max_element(as.begin(), as.end()));
    }

    void solve_second(int n) {
        std::vector<int> data(n, 0);
        for (int i = 0; i < n; i += 1) {
            cin >> data[i];
        }
        std::unordered_set<int> unique;
        unique.reserve(200000);
        int idx_unique = n;
        for (int i = n - 1; 0 <= i; i -= 1) {
            if (!unique.contains(data[i]))
            {
                idx_unique = data[i];
                unique.insert(idx_unique);
            }
        }
        cout << idx_unique;
    }
};