### **Construct Balanced Binary Jump Table**

**Description**
During the assembly emission phase of a compiler, dense `switch/case` statements are often lowered into a **binary jump table** to optimize branch prediction and guarantee logarithmic dispatch performance. Given a strictly increasing array of unique case labels, construct a height-balanced Binary Search Tree (BST) that represents the optimal dispatch layout for code generation.

Each node in the tree represents a runtime comparison against a case value. Traversing left corresponds to evaluating smaller case labels, while traversing right corresponds to larger ones. To minimize worst-case jump depth and ensure predictable instruction pipelining, the resulting tree must be height-balanced (the height difference between the left and right subtrees of every node must not exceed 1).

**Examples**
**Example 1:**
Input: `caseValues = [-10, -3, 0, 5, 9]`
Output: `[0, -3, 9, -10, null, 5]`
*Explanation:* The root dispatch point is `0`. The left subtree `[-10, -3]` and right subtree `[5, 9]` are arranged to maintain strict height balance, enabling O(log N) jump resolution during execution.

**Example 2:**
Input: `caseValues = [1, 3]`
Output: `[3, 1]` *(or `[1, null, 3]`)*
*Explanation:* Either value can serve as the root dispatch node. Both valid outputs maintain a maximum height difference of 1 and preserve BST ordering for correct switch routing.

**Constraints**
- `0 <= caseValues.length <= 10^4`
- `-10^4 <= caseValues[i] <= 10^4`
- `caseValues` is sorted in strictly ascending order.
- All case values are unique.
- If `caseValues` is empty, return `nullptr`.

**C++ Skeleton**
```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Transforms a sorted array of switch-case labels into a height-balanced
     * binary jump table (BST) for optimal O(log N) assembly dispatch.
     *
     * @param caseValues Strictly increasing array of switch case constants.
     * @return TreeNode* Root of the height-balanced binary jump table.
     */
    TreeNode* buildBinaryJumpTable(vector<int>& caseValues) {

    }
};
```
