### Symbol Table Pair Resolution

#### **Description**
During the **Linker / Assembler** phase of the compilation pipeline, the compiler generates a relocation table containing unresolved symbol offsets. To satisfy a specific memory layout constraint (e.g., page alignment or constant pool indexing), the system must identify exactly two distinct unresolved references whose offset values sum to a required `targetBase` address.

You are given an array `offsets`, where `offsets[i]` represents the numeric offset of an unresolved symbol at instruction index `i`. Return the indices `[i, j]` of the two offsets that sum to `targetBase`.

#### **Requirements**
- Each index may only be used once (a symbol cannot reference itself).
- Exactly one valid pair is guaranteed to exist in the input.
- The returned indices may be in any order.
- The solution must run in **O(N)** time and use **O(N)** auxiliary space to reflect efficient, single-pass symbol table resolution during constant pooling.

#### **Examples**
**Example 1:**
```
Input: offsets = [4096, 8192, 12288], targetBase = 12288
Output: [0, 1]
Explanation: offsets[0] + offsets[1] = 4096 + 8192 = 12288. Indices 0 and 1 are returned.
```

**Example 2:**
```
Input: offsets = [0, 16, 32, 48], targetBase = 48
Output: [1, 2]
Explanation: 16 + 32 = 48. The corresponding indices are 1 and 2.
```

#### **Constraints**
- `2 ≤ offsets.length ≤ 10^5`
- `-10^9 ≤ offsets[i] ≤ 10^9`
- `-10^9 ≤ targetBase ≤ 10^9`
- Exactly one solution exists.

#### **C++ Function Signature**
```cpp
#include <vector>

class Solution {
public:
    /**
     * Resolves two symbol offsets that sum to a target base address.
     *
     * @param offsets    Vector of unresolved symbol offsets from the relocation table.
     * @param targetBase The required combined offset for memory alignment/resolution.
     * @return           A vector of two indices [i, j] such that offsets[i] + offsets[j] == targetBase.
     */
    std::vector<int> resolveRelocationPair(const std::vector<int>& offsets, int targetBase) {
        // Implementation here
    }
};
```
