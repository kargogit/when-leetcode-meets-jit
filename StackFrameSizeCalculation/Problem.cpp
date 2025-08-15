### Problem: Maximum Scope Depth (Stack Frame Size Calculation)

#### Description
During the **Frame Allocation** phase of a compiler's backend, the exact stack frame size for a function is determined by analyzing the maximum nesting depth of its lexical scopes or activation records.

You are given a rooted tree representing a program's scope hierarchy. Each node corresponds to a scope, and its children represent immediately nested sub-scopes. Compute the maximum depth of this tree:
- The root scope is at depth `1`
- Each additional level of nesting increments the depth by `1`
- If the input tree is empty, return `0`

The returned integer directly dictates the minimum contiguous stack memory required for safe execution during code generation.

#### Examples
**Example 1:**
```
Input:
      Scope(1)
       /   \
  Scope(2) Scope(3)
            |
        Scope(4)

Output: 3
Explanation: The deepest path is 1 → 3 → 4, which has 3 levels of nesting.
```

**Example 2:**
```
Input: Scope(5)  (single node, no children)
Output: 1
Explanation: The root itself constitutes depth 1.
```

**Example 3:**
```
Input: nullptr
Output: 0
Explanation: Empty scope tree requires no frame allocation.
```

#### Constraints
- The number of nodes in the tree is in the range `[0, 10^4]`
- Each node may have zero or more children (N-ary tree structure)
- The input is guaranteed to be a valid, acyclic scope hierarchy
- Time Limit: Standard (O(N) expected)
- Space Limit: Standard (O(H) call stack expected)

#### C++ Skeleton
```cpp
#include <vector>
#include <algorithm>

// Represents a lexical scope or activation record in the AST
struct ScopeNode {
    int id;
    std::vector<ScopeNode*> children;

    ScopeNode() : id(0) {}
    explicit ScopeNode(int _id) : id(_id) {}
    ScopeNode(int _id, std::vector<ScopeNode*> _children)
        : id(_id), children(std::move(_children)) {}
};

class Solution {
public:
    /**
     * PATCG Phase: Program Analysis -> Frame Allocation
     * Computes the maximum nesting depth of scopes to determine
     * the exact stack frame size required for code generation.
     *
     * @param root Pointer to the root scope node (may be nullptr)
     * @return Maximum scope depth (integer >= 0)
     */
    int calculateFrameSize(ScopeNode* root) {
        // Implement your solution here
    }
};
```

#### PATCG Context Mapping
- **Analysis Phase:** Traverse the Abstract Syntax Tree (AST) / Scope Graph
- **Transformation/Generation Phase:** Use computed depth to emit exact `.cfi_*` directives or LLVM stack allocation metadata
- **Complexity Target:** `O(N)` Time, `O(H)` Space (where `N` = total scopes, `H` = max depth)
