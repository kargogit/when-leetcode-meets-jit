#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> resolveSymbolPair(std::vector<int>& sortedTable, int target) {
        int left = 0;
        int right = (int)sortedTable.size() - 1;

        while (left < right) {
            int sum = sortedTable[left] + sortedTable[right];
            if (sum == target)
                return {left + 1, right + 1};
            else if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};

int main() {
    Solution sol;

    std::vector<int> t1 = {10, 25, 30, 45, 60};
    auto r1 = sol.resolveSymbolPair(t1, 70);
    std::cout << "[" << r1[0] << ", " << r1[1] << "]\n"; // [2, 4]

    std::vector<int> t2 = {4, 8, 12, 16};
    auto r2 = sol.resolveSymbolPair(t2, 20);
    std::cout << "[" << r2[0] << ", " << r2[1] << "]\n"; // [1, 4]

    std::vector<int> t3 = {100, 200, 300, 400};
    auto r3 = sol.resolveSymbolPair(t3, 600);
    std::cout << "[" << r3[0] << ", " << r3[1] << "]\n"; // [2, 3]

    return 0;
}
