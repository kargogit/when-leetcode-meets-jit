# Bounds Check Elimination

In modern compilers and JIT runtimes, array accesses are guarded by runtime bounds checks to prevent `IndexOutOfBounds` exceptions. These checks introduce measurable overhead. An optimization pass can safely strip them out **only if** it can statically prove that every dynamically computed index will naturally remain within valid array bounds.

You are given an integer array `jumpLengths`, where `jumpLengths[i]` represents the maximum number of positions the program can advance from index `i` during execution. Starting at index `0`, the optimizer must track the maximum dynamically reachable index to verify that the execution stream can safely reach the end of the array without stalling or exceeding bounds.

Determine if the final index is reachable. If it is, all intermediate bounds checks along the execution path can be safely eliminated.

Return `true` if the last index is reachable, otherwise return `false`.

### Example 1
**Input:** `jumpLengths = [2,3,1,1,4]`
**Output:** `true`
**Explanation:** From index `0`, advance up to `1` step to reach index `1`. From index `1`, advance up to `3` steps to reach index `4` (the last index). The path stays within valid bounds, so checks can be eliminated.

### Example 2
**Input:** `jumpLengths = [3,2,1,0,4]`
**Output:** `false`
**Explanation:** The maximum reachable index stalls at `3`. Since `jumpLengths[3] == 0`, execution cannot advance further, making the last index unreachable. Bounds checks cannot be safely removed.

### Constraints
* `1 <= jumpLengths.length <= 10^4`
* `0 <= jumpLengths[i] <= 10^5`

### C++ Skeleton
```cpp
#include <vector>

class Solution {
public:
    bool canEliminateBoundsChecks(std::vector<int>& jumpLengths) {

    }
};
```
