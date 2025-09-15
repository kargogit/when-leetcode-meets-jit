#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximizeILPThroughput(vector<int>& alignment_caps) {
        int left = 0;
        int right = (int)alignment_caps.size() - 1;
        int best = 0;

        while (left < right) {
            int width = right - left;
            int height = min(alignment_caps[left], alignment_caps[right]);
            best = max(best, width * height);

            if (alignment_caps[left] < alignment_caps[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return best;
    }
};

int main() {
    Solution solution;

    vector<int> alignment_caps1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> alignment_caps2 = {1, 1};
    vector<int> alignment_caps3 = {4, 3, 2, 1, 4};

    cout << solution.maximizeILPThroughput(alignment_caps1) << '\n'; // 49
    cout << solution.maximizeILPThroughput(alignment_caps2) << '\n'; // 1
    cout << solution.maximizeILPThroughput(alignment_caps3) << '\n'; // 16

    return 0;
}
