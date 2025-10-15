### **Problem: K-th Smallest VTable Offset**

**Phase:** Dispatch Table Resolution

#### **Description**
In a Just-In-Time (JIT) compiler, the Virtual Method Table (VTable) for an object is maintained as a **Binary Search Tree (BST)** to efficiently manage dynamic dispatch. Each node in this "method dictionary" tree represents a compiled method, and the tree is strictly ordered by the method's **memory offset**.

During the execution of a hot loop, the runtime system needs to resolve an interface call by querying the method dictionary for the **$k$-th smallest** memory offset to properly route the execution jump.

Given the `root` of a binary search tree representing the VTable method dictionary, and an integer `k`, return the memory offset of the $k$-th smallest method in the tree (1-indexed).

---

#### **Examples**

**Example 1:**
```text
Input: root = [30, 10, 40, null, 20], k = 1
      30
     /  \
   10    40
    \
     20

Output: 10
Explanation: The 1st smallest memory offset in the method dictionary is 10.
```

**Example 2:**
```text
Input: root = [50, 30, 60, 20, 40, null, null, 10], k = 3
           50
          /  \
        30    60
       /  \
     20    40
    /
  10

Output: 30
Explanation: The 3rd smallest memory offset in the method dictionary is 30.
```

---

#### **Constraints**
* The number of method nodes in the tree is `n`.
* `1 <= k <= n <= 10^4`
* `0 <= Node.memory_offset <= 10^5`
* All `Node.memory_offset` values are **unique**.

**Follow-up:** If the JIT compiler frequently hot-swaps methods (resulting in frequent insert and delete operations on the VTable tree) and you need to find the $k$-th smallest offset frequently, how would you optimize the search to run in $O(H)$ time, where $H$ is the height of the tree?

---

#### **C++ Skeleton**

```cpp
/**
 * Definition for a VTable method node.
 */
struct VTableNode {
    int memory_offset;
    VTableNode *left;
    VTableNode *right;

    VTableNode() : memory_offset(0), left(nullptr), right(nullptr) {}
    VTableNode(int x) : memory_offset(x), left(nullptr), right(nullptr) {}
    VTableNode(int x, VTableNode *left, VTableNode *right) : memory_offset(x), left(left), right(right) {}
};

class DispatchTableOptimizer {
public:
    /**
     * Resolves the k-th smallest memory offset from the method dictionary.
     *
     * @param root The root of the VTable binary search tree.
     * @param k The 1-based index of the smallest offset to find.
     * @return The exact memory offset integer.
     */
    int kthSmallestOffset(VTableNode* root, int k) {

    }
};
```
