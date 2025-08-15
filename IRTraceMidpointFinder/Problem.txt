### IR Trace Midpoint Finder

**Description**
During split-phase compilation in a modern JIT engine, an intrusive Intermediate Representation (IR) trace is modeled as a singly linked list of compilation nodes. To enable parallel pipeline execution, the optimizer must identify the exact midpoint of this trace. The system will split the IR trace at this node, assigning the first half to Compilation Thread A and the second half (starting at the midpoint) to Compilation Thread B.

Given the `head` of the IR trace (a singly linked list), return the node that marks the split point. If the trace contains an even number of nodes, return the **second** of the two middle nodes to ensure balanced workload distribution across threads.

---

**Examples**

**Example 1:**
```
Input: head = [1, 3, 5, 7, 9]
Output: 5
Explanation: The IR trace has 5 nodes. The exact middle is the 3rd node (value 5).
Split yields Thread A: [1, 3] and Thread B: [5, 7, 9].
```

**Example 2:**
```
Input: head = [2, 4, 6, 8]
Output: 6
Explanation: The IR trace has 4 nodes. The two middle nodes are 4 and 6.
By convention, return the second one (6) to maintain thread load balance.
```

**Example 3:**
```
Input: head = [42]
Output: 42
Explanation: A single-node trace splits into an empty first half and the node itself as the start of the second half.
```

---

**Constraints**
- `1 <= number of nodes <= 100`
- Node values represent sequential IR instruction IDs (irrelevant to split logic)
- **System Requirement:** Must execute in `O(N)` time and `O(1)` auxiliary space to satisfy JIT phase scheduler limits.
- The original list structure must not be modified or copied.

---

**C++ Skeleton**
```cpp
/**
 * Definition for a singly-linked IR node.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findCompilationMidpoint(ListNode* head) {

    }
};
```

---

**Implementation Notes**
- Return the pointer to the midpoint node only. The caller handles thread dispatch and list partitioning.
- Do not allocate additional data structures (arrays, queues, stacks, etc.) to track node positions or counts.
- Handle edge cases naturally: single-node lists, even-length lists, and standard odd-length lists must all pass without special branching overhead.
