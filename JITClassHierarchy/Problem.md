### **Lowest Common Superclass (JIT Class Hierarchy)**

You are optimizing a Just-In-Time (JIT) compiler's **Class Hierarchy Analysis (CHA)** module. To accelerate runtime method devirtualization, the compiler indexes the inheritance lattice as a **Type Resolution BST**, where each node represents a compiled class and its `type_id` enforces strict ordering: all nodes in the left subtree have `type_id` values less than the root, and all nodes in the right subtree have greater values.

Given the `root` of this BST and two distinct `TypeNode` pointers `p` and `q` representing active object types at runtime, return the **Lowest Common Superclass (LCS)**. The LCS is the deepest node in the tree that is an ancestor of both `p` and `q`. This node identifies the most specific shared base class required to safely resolve a virtual dispatch and apply devirtualization.

Your implementation must perform a **Divergence Point Walk**, leveraging the BST ordering to traverse from the root downward until the resolution paths to `p` and `q` split. The solution must run in **`O(H)` time** and **`O(1)` auxiliary space**, where `H` is the height of the type tree.

---

#### **Example 1:**
**Input:** `root = [10, 5, 15, 2, 7, 12, 20], p = 2, q = 7`
**Output:** `5`
**Explanation:** Types `2` and `7` diverge at node `5`. Node `5` is the lowest node in the hierarchy that contains both as descendants.

#### **Example 2:**
**Input:** `root = [10, 5, 15], p = 5, q = 15`
**Output:** `10`
**Explanation:** The only shared ancestor is the root type `10`, making it the LCS.

#### **Constraints:**
- The tree contains `[2, 10^4]` type nodes.
- `0 <= type_id <= 10^9`
- All `type_id` values are unique.
- `p` and `q` are guaranteed to exist in the tree.
- `p != q`
- The tree strictly adheres to the BST property.
- You must solve this in `O(H)` time and `O(1)` space.

---

#### **C++ Function Signature:**
```cpp
/**
 * Definition for a Type Resolution Node in the JIT CHA.
 * struct TypeNode {
 *     int type_id;
 *     TypeNode *left;
 *     TypeNode *right;
 *     TypeNode(int x) : type_id(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TypeNode* lowestCommonSuperclass(TypeNode* root, TypeNode* p, TypeNode* q) {

    }
};
```
