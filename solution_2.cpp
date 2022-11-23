#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> data(n, 0);
    for (int i = 0; i < n; i += 1) {
        std::cin >> data[i];
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
    std::cout << idx_unique;
}