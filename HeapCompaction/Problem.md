### **Heap Compaction Pass**

**System Context**
In a mark-compact garbage collector, the compaction phase reclaims fragmented heap memory by sliding all live object references to the front of the allocation space. This transformation eliminates external fragmentation, improves cache locality, and enables `O(1)` bump-pointer allocation for future generations. You are implementing the **sliding compaction transformation pass** for a lightweight runtime system.

**Problem Description**
You are given a contiguous memory buffer represented as an integer array `heap`, where:
- `0` denotes a dead/unreachable memory slot (garbage)
- Any non-zero value denotes a live object reference

Transform the array **in-place** such that:
1. All live references are compacted to the beginning of the buffer
2. Their original relative allocation order is strictly preserved (stable compaction)
3. All dead slots (`0`) occupy the remaining trailing positions

The transformation must run in `O(N)` time and use only `O(1)` auxiliary space.

**Examples**

| Input | Output | Explanation |
|-------|--------|-------------|
| `[0, 1, 0, 3, 12]` | `[1, 3, 12, 0, 0]` | Live refs `1, 3, 12` slide forward in original order. Zeros fill the tail. |
| `[0]` | `[0]` | Single dead slot remains unchanged. |
| `[5, 2, 0, 7]` | `[5, 2, 7, 0]` | `5, 2, 7` compact to front. One dead slot pushed to end. |

**Constraints**
- `1 ≤ heap.length ≤ 10^4`
- `-10^4 ≤ heap[i] ≤ 10^4`
- `heap[i] == 0` or `heap[i]` is a valid live object reference
- **Must modify `heap` in-place.** Do not allocate a new buffer or return a modified copy.
- **Stability required:** Relative order of non-zero elements must match their original positions.

**Transformation Contract**
- **Precondition:** `heap` represents a linear memory snapshot with interleaved live (`≠0`) and dead (`0`) slots.
- **Postcondition:** `heap` contains all original live references at indices `[0, k-1]` in original relative order, followed by `heap.length - k` zeros.
- **Complexity Bounds:** `O(N)` time, `O(1)` auxiliary space.

---

### **C++ Scaffolding**

```cpp
#include <vector>

class Solution {
public:
    /**
     * Performs an in-place sliding compaction pass on a simulated heap buffer.
     *
     * @param heap Reference to a vector representing contiguous memory slots.
     *             Modifies the vector in-place to compact live references to the front
     *             and push dead slots (0) to the tail.
     */
    void compactHeap(std::vector<int>& heap) {
        // Implementation goes here
    }
};
```
