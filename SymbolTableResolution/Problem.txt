# Export/Import Table Resolution

## Problem Description
During the loader/linker phase of a compiler toolchain, the linker maintains a **sorted table** of virtual instruction offsets extracted from a binary's export and import records. To resolve a relative relocation entry, the linker must identify two distinct offsets in this table whose values sum exactly to a given `target` address.

You are given a `0-indexed` integer array `sortedTable` that is already sorted in non-decreasing order, and an integer `target`. Return the **1-based indices** of the two offsets as a pair `[index1, index2]` such that `index1 < index2`.

The toolchain guarantees that exactly one valid pair exists. Your implementation must process the table in **`O(n)` time** and use **`O(1)` auxiliary space** to satisfy production memory and throughput constraints in a JIT/Linker pipeline.

## Examples

**Example 1:**
```
Input: sortedTable = [10, 25, 30, 45, 60], target = 70
Output: [2, 4]
Explanation: sortedTable[1] (25) + sortedTable[3] (45) = 70.
Using 1-based indexing, the result is [2, 4].
```

**Example 2:**
```
Input: sortedTable = [4, 8, 12, 16], target = 20
Output: [1, 4]
Explanation: 4 + 16 = 20. Indices return as [1, 4].
```

**Example 3:**
```
Input: sortedTable = [100, 200, 300, 400], target = 600
Output: [2, 3]
Explanation: 200 + 300 = 600. Indices return as [2, 3].
```

## Constraints
- `2 <= sortedTable.length <= 10^5`
- `0 <= sortedTable[i] <= 10^9`
- `sortedTable` is sorted in non-decreasing order.
- `0 <= target <= 2 * 10^9`
- Exactly one valid solution exists.
- `index1 != index2`

## Function Signature (C++)
```cpp
#include <vector>

class Solution {
public:
    /**
     * Resolves two offsets from a sorted export/import table that sum to the target.
     *
     * @param sortedTable A vector of virtual offsets sorted in non-decreasing order.
     * @param target The relocation target address to match.
     * @return A vector of two 1-based indices [index1, index2] where index1 < index2.
     */
    std::vector<int> resolveSymbolPair(std::vector<int>& sortedTable, int target);
};
```

## Notes
- The input array uses `0-based` indexing per standard C++ conventions, but the return value must use `1-based` indexing to align with legacy DWARF debug range formats.
- You may assume the input array is never mutated by the caller.
- The `O(n)` time and `O(1)` space requirements are strict system constraints; solutions relying on auxiliary data structures or nested iteration will fail pipeline validation.
