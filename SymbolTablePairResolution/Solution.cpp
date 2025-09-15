#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> resolveRelocationPair(const std::vector<int>& offsets, int targetBase) {
        std::unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < (int)offsets.size(); i++) {
            int complement = targetBase - offsets[i];
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[offsets[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution sol;

    std::vector<int> offsets1 = {4096, 8192, 12288};
    auto result1 = sol.resolveRelocationPair(offsets1, 12288);
    std::cout << "[" << result1[0] << ", " << result1[1] << "]\n"; // [0, 1]

    std::vector<int> offsets2 = {0, 16, 32, 48};
    auto result2 = sol.resolveRelocationPair(offsets2, 48);
    std::cout << "[" << result2[0] << ", " << result2[1] << "]\n"; // [1, 2]

    return 0;
}
