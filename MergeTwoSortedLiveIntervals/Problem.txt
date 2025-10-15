### Merge Live-Interval Lists at CFG Join Point

**Problem Description**

During Control Flow Graph (CFG) construction and register allocation, a compiler tracks the active lifespan of variables using *live intervals*. When two execution paths (Basic Blocks) converge at a join point, the compiler must merge their respective live-interval lists into a single chronological sequence to accurately allocate registers.

You are given the heads of two singly linked lists, `blockA` and `blockB`. Each node represents a live interval and contains a `start_idx` (the instruction index where the variable becomes live) and an `end_idx`. Both lists are strictly sorted in **non-decreasing order** based on their `start_idx`.

Your task is to merge the two lists into a single linked list sorted by `start_idx`. The merge should be done **in-place** by splicing together the nodes of the first two lists (i.e., you must rewire the `next` pointers of the existing nodes, without allocating new ones).

*(Note: Do **not** combine or merge overlapping intervals. Simply interleave the nodes into one sorted chain.)*

Return the *head of the merged linked list*.

---

### Examples

**Example 1:**

**Input:**
`blockA` = `[1, 4] -> [5, 9] -> [10, 12]`
`blockB` = `[2, 6] -> [5, 8] -> [14, 20]`

**Output:**
`[1, 4] -> [2, 6] -> [5, 9] -> [5, 8] -> [10, 12] -> [14, 20]`

**Explanation:**
The nodes are spliced together in ascending order of their `start_idx`. For the intervals with the exact same `start_idx` (e.g., `[5, 9]` and `[5, 8]`), their relative order does not matter.

**Example 2:**

**Input:**
`blockA` = `[]`
`blockB` = `[]`

**Output:**
`[]`

**Example 3:**

**Input:**
`blockA` = `[]`
`blockB` = `[0, 5]`

**Output:**
`[0, 5]`

---

### Constraints

* The number of nodes in both lists is in the range `[0, 50]`.
* `0 <= Node.start_idx <= Node.end_idx <= 10^5`
* Both `blockA` and `blockB` are sorted in **non-decreasing order** by `start_idx`.
* **Follow-up:** Can you solve this in $O(N+M)$ time and $O(1)$ auxiliary space?

---

### C++ Skeleton

```cpp
/**
 * Definition for a live interval node.
 * struct IntervalNode {
 *     int start_idx;
 *     int end_idx;
 *     IntervalNode *next;
 *     IntervalNode() : start_idx(0), end_idx(0), next(nullptr) {}
 *     IntervalNode(int s, int e) : start_idx(s), end_idx(e), next(nullptr) {}
 *     IntervalNode(int s, int e, IntervalNode *next) : start_idx(s), end_idx(e), next(next) {}
 * };
 */

class CompilerCFG {
public:
    IntervalNode* mergeLiveIntervalLists(IntervalNode* blockA, IntervalNode* blockB) {
        // Your code here

    }
};
```
