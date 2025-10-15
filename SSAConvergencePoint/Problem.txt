### **Execution Path Convergence (Phi-Node Insertion)**

**Context:**
During the construction of Static Single Assignment (SSA) form in modern compilers (like LLVM), the compiler tracks variable assignments across different execution paths. When two distinct execution branches (e.g., the `if` and `else` blocks) converge back into a shared execution sequence, the compiler must insert a **$\Phi$-node** (Phi-node) at the exact basic block where the paths meet to reconcile the variable's state.

**Problem:**
You are given the heads of two execution paths, `pathA` and `pathB`, represented as singly linked lists of `BasicBlock` nodes. These paths represent two separate traces through a Control Flow Graph (CFG) that eventually merge into a shared execution tail.

Write a function to find and return the exact `BasicBlock` where the two execution paths converge. If the two paths are completely disjoint and never converge, return `null`.

**Requirements:**
*   **Time Complexity:** $O(N + M)$ where $N$ and $M$ are the lengths of the two paths.
*   **Space Complexity:** $O(1)$ strictly (you cannot use hash maps or sets to store visited nodes).
*   **Immutability:** The structure of the CFG (the linked lists) must remain perfectly intact after the function returns.

---

### **Examples**

**Example 1:**
```text
Input:
pathA: [Block 1] -> [Block 2] \
                               -> [Block 5] -> [Block 6]
pathB: [Block 3] -> [Block 4] /

Output: Reference to [Block 5]
Explanation: The execution paths A and B converge at BasicBlock 5. This is where the compiler should insert the Phi-node.
```

**Example 2:**
```text
Input:
pathA: [Block 1] -> [Block 2]
pathB: [Block 3] -> [Block 4]

Output: null
Explanation: The two execution paths run in parallel and never share a common basic block. No Phi-node insertion is required.
```

---

### **Constraints**
*   The number of nodes of `pathA` is $N$.
*   The number of nodes of `pathB` is $M$.
*   $0 \le N, M \le 3 \times 10^4$
*   `1 <= Node.blockId <= 10^5`
*   There are no cycles anywhere in the provided execution paths.

---

### **C++ Scaffolding**

```cpp
/**
 * Definition for a Basic Block in a Control Flow Graph.
 * struct BasicBlock {
 *     int blockId;
 *     BasicBlock *next;
 *     BasicBlock(int x) : blockId(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * Finds the convergence point of two execution paths.
     *
     * @param pathA Head of the first execution path.
     * @param pathB Head of the second execution path.
     * @return Pointer to the converging BasicBlock, or nullptr if none exists.
     */
    BasicBlock* getConvergenceBlock(BasicBlock* pathA, BasicBlock* pathB) {
        // Your code here

    }
};
```
