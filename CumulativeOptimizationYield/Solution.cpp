#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxOptimizationYield(vector<int>& metric_scores) {
        int maxYield = 0;
        for ( int i = 1; i < metric_scores.size(); i++ ) {
            int currStep = (metric_scores[i] - metric_scores[i-1]);
            if ( currStep > 0 ) {
                maxYield += currStep;
            }
        }
        return maxYield;
    }
};


int main() {
    Solution solution;

    vector<int> metric_scores1 = {7, 1, 5, 3, 6, 4};
    vector<int> metric_scores2 = {1, 2, 3, 4, 5};
    vector<int> metric_scores3 = {7, 6, 4, 3, 1};
    vector<int> metric_scores4 = {1, 3, 2, 4};

    cout << solution.maxOptimizationYield(metric_scores1) << endl; // 7
    cout << solution.maxOptimizationYield(metric_scores2) << endl; // 4
    cout << solution.maxOptimizationYield(metric_scores3) << endl; // 0
    cout << solution.maxOptimizationYield(metric_scores4) << endl; // 4

    return 0;
}
