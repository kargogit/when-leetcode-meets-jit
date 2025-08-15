#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxTierUpDelta(std::vector<int>& frequencies) {
        int minFreq = frequencies[0];
        int maxDelta = 0;
        for ( auto freq : frequencies ) {
            maxDelta = max( maxDelta, freq - minFreq );
            minFreq = min( minFreq, freq );
        }
        return maxDelta;
    }
};


int main() {
    Solution solution;

    vector<int> frequencies1 = {7, 1, 5, 3, 6, 4};
    cout << solution.maxTierUpDelta(frequencies1) << endl; // Output: 5

    vector<int> frequencies2 = {7, 6, 4, 3, 1};
    cout << solution.maxTierUpDelta(frequencies2) << endl; // Output: 0

    return 0;
}
