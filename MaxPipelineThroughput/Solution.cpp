#include <iostream>
#include <vector>

class Solution {
public:
    int maxPipelineThroughput(std::vector<int>& weights) {
        if (weights.empty()) return 0;
        if (weights.size() == 1) return weights[0];

        int prev2 = 0, prev1 = 0;

        for (int w : weights) {
            int current = std::max(prev1, prev2 + w);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    Solution sol;

    std::vector<int> w1 = {3, 1, 4, 1, 5};
    std::cout << "Example 1: " << sol.maxPipelineThroughput(w1) << "\n"; // 12

    std::vector<int> w2 = {2, 2, 2, 2};
    std::cout << "Example 2: " << sol.maxPipelineThroughput(w2) << "\n"; // 4

    std::vector<int> w3 = {5};
    std::cout << "Example 3: " << sol.maxPipelineThroughput(w3) << "\n"; // 5

    return 0;
}
