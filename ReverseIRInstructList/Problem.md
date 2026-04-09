# Reverse IR Instruction List

### Description
In a compiler's Intermediate Representation (IR), instructions within a basic block are stored as a singly linked list for memory efficiency and constant-time insertion. During backward dataflow analysis or SSA destruction, the transformation pipeline must traverse these instructions in reverse order.

Given the `head` of this intrusive instruction list, reverse the sequence **in-place** by rewiring the forward pointers. Return the new head of the reversed list. The transformation must operate without allocating new instruction nodes or using auxiliary memory proportional to the list length.

### Examples
**Example 1:**
```
Input: head = [10, 20, 30, 40, 50]
Output: [50, 40, 30, 20, 10]
```

**Example 2:**
```
Input: head = [10, 20]
Output: [20, 10]
```

**Example 3:**
```
Input: head = []
Output: []
```

### Constraints
- The number of nodes is in the range `[0, 10^5]`.
- Node values are integers representing instruction opcodes.
- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)` auxiliary space (in-place pointer rewiring only).

### C++ Skeleton
```cpp
/**
 * Definition for an IR instruction node.
 * Represents a single instruction in a basic block's intrusive list.
 */
struct IRInstruction {
    int opcode;
    IRInstruction* next;

    IRInstruction() : opcode(0), next(nullptr) {}
    IRInstruction(int val) : opcode(val), next(nullptr) {}
    IRInstruction(int val, IRInstruction* nxt) : opcode(val), next(nxt) {}
};

class Solution {
public:
    /**
     * Reverses the intrusive IR instruction list in-place for backward traversal.
     *
     * @param head The first instruction in the forward sequence.
     * @return The new head of the reversed instruction list.
     */
    IRInstruction* reverseIRInstructionList(IRInstruction* head) {
        // Implementation goes here
    }
};
```
