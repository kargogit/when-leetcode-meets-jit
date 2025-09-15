### Maximum ILP Throughput Window

**Description:**
You are implementing a Code Generation pass for an optimizing JIT compiler. The program analysis phase has already processed a linear instruction trace and produced an array `alignment_caps`, where `alignment_caps[i]` represents the maximum sustainable Instruction-Level Parallelism (ILP) width or cache-line alignment capacity at the `i`-th pipeline boundary.

When scheduling a parallel execution window between two boundaries `i` and `j` (`i < j`), the effective throughput is strictly bottlenecked by the narrower capacity: `min(alignment_caps[i], alignment_caps[j])`. The total parallel execution gain scales linearly with the cycle distance between the boundaries: `(j - i)`.

Your task is to select two pipeline boundaries that maximize the total parallel throughput, calculated as:
`throughput = min(alignment_caps[i], alignment_caps[j]) * (j - i)`

Return the maximum achievable throughput.

**Example 1:**
```
Input: alignment_caps = [1, 8, 6, 2, 5, 4, 8, 3, 7]
Output: 49
Explanation: The optimal window spans index 1 to index 8. Bottleneck capacity = min(8, 7) = 7. Cycle distance = 8 - 1 = 7. Throughput = 7 * 7 = 49.
```

**Example 2:**
```
Input: alignment_caps = [1, 1]
Output: 1
Explanation: Only one valid window exists. min(1, 1) * 1 = 1.
```

**Example 3:**
```
Input: alignment_caps = [4, 3, 2, 1, 4]
Output: 16
Explanation: The optimal window spans index 0 to index 4. min(4, 4) * 4 = 16.
```

**Constraints:**
- `n == alignment_caps.length`
- `2 <= n <= 10^5`
- `0 <= alignment_caps[i] <= 10^4`
- *Compiler Pass Requirement:* Solution must run in `O(n)` time and use `O(1)` auxiliary space to satisfy JIT compilation latency targets.

**C++ Skeleton:**
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximizeILPThroughput(std::vector<int>& alignment_caps) {

    }
};
```
