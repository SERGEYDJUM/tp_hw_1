#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> as(200001, -1);
    for (int i = 0; i < n; i += 1) {
        int idx = 0;
        std::cin >> idx;
        as[idx] = n - i - 1;
    }
    std::cout << std::distance(as.begin(), std::max_element(as.begin(), as.end()));
}