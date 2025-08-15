#include <vector>
#include <iostream>

class Solution {
public:
    bool canEliminateBoundsChecks(std::vector<int>& jumpLengths) {
        int maxReach = 0;
        for (int i = 0; i < (int)jumpLengths.size(); i++) {
            if (i > maxReach)
                return false;
            maxReach = std::max(maxReach, i + jumpLengths[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;

    std::vector<int> test1 = {2, 3, 1, 1, 4};
    std::cout << (sol.canEliminateBoundsChecks(test1) ? "true" : "false") << "\n";

    std::vector<int> test2 = {3, 2, 1, 0, 4};
    std::cout << (sol.canEliminateBoundsChecks(test2) ? "true" : "false") << "\n";

    return 0;
}
