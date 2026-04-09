### **Hazard-Aware Instruction Scheduling**

**Problem Description**
You are implementing a backend instruction scheduler for a simplified processor pipeline. The compiler front-end has generated a linear sequence of `n` instructions. Each instruction `i` has an associated performance weight `weights[i]` representing its contribution to overall execution throughput.

Due to structural hardware hazards (e.g., shared execution units, memory ports, or register file banks), the pipeline cannot safely issue two consecutive instructions from the original sequence in adjacent cycle slots without triggering a hardware stall. To maximize performance, your scheduler must select a subset of instructions to issue such that:
1. No two selected instructions are adjacent in the original sequence.
2. The sum of their performance weights is maximized.

Return the maximum total throughput weight achievable.

**Examples**

**Example 1:**
```
Input: weights = [3, 1, 4, 1, 5]
Output: 12
Explanation: Selecting instructions at indices 0, 2, and 4 yields weights [3, 4, 5]. No two are adjacent in the original sequence. Total throughput = 3 + 4 + 5 = 12.
```

**Example 2:**
```
Input: weights = [2, 2, 2, 2]
Output: 4
Explanation: The optimal selection picks non-adjacent instructions (e.g., indices 0 and 2, or 1 and 3). Maximum sum = 2 + 2 = 4.
```

**Example 3:**
```
Input: weights = [5]
Output: 5
Explanation: Only one instruction exists, so it can be safely issued without hazard risk.
```

**Constraints**
- `1 <= weights.length <= 10^5`
- `0 <= weights[i] <= 10^4`
- The instruction sequence is fixed; reordering or duplication is not permitted.
- A solution with `O(n)` time complexity and `O(1)` auxiliary space is expected.

**Starter Code (C++)**
```cpp
#include <vector>

class Solution {
public:
    int maxPipelineThroughput(std::vector<int>& weights) {

    }
};
```
