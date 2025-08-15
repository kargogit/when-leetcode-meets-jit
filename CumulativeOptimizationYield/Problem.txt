### Cumulative Optimization Yield

**Problem Statement:**

You are implementing a greedy peephole optimizer for a JIT compiler. You are analyzing a hot basic block across a series of sequential micro-op rewrite passes.

You are given an integer array `metric_scores` where `metric_scores[i]` represents the heuristic performance score of the basic block at the `i`-th rewrite pass.

Your goal is to maximize the total performance yield through dead code elimination and micro-op fusion. You can achieve a performance yield by choosing to "initiate" a transformation sequence at one pass and "commit" it at a later pass.

The yield of a single committed transformation is the difference in the score: `metric_scores[commit_pass] - metric_scores[initiate_pass]`.

You may complete as many transformations as you like to accumulate the highest possible total yield, but with the following restriction:
* You may only have at most **one** active, uncommitted transformation sequence at any time (i.e., you must commit the current transformation before you can initiate a new one).
* You may commit a transformation and immediately initiate a new one during the exact same pass.

Return the *maximum total performance yield* you can achieve.

---

### Examples

**Example 1:**
```text
Input: metric_scores = [7,1,5,3,6,4]
Output: 7
Explanation:
- Initiate on pass 1 (score = 1) and commit on pass 2 (score = 5), yield = 5 - 1 = 4.
- Initiate on pass 3 (score = 3) and commit on pass 4 (score = 6), yield = 6 - 3 = 3.
Total yield is 4 + 3 = 7.
```

**Example 2:**
```text
Input: metric_scores = [1,2,3,4,5]
Output: 4
Explanation:
- Initiate on pass 0 (score = 1) and commit on pass 4 (score = 5), yield = 5 - 1 = 4.
Total yield is 4.
```

**Example 3:**
```text
Input: metric_scores = [7,6,4,3,1]
Output: 0
Explanation:
There is no way to achieve a positive performance yield, so no transformations are initiated. The maximum yield is 0.
```

---

### Constraints:

* `1 <= metric_scores.length <= 10^5`
* `0 <= metric_scores[i] <= 10^4`

---

### C++ Scaffolding:

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    int maxOptimizationYield(vector<int>& metric_scores) {
        // Your implementation here

    }
};
```
