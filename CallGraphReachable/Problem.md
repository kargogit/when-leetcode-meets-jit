# 🔍 Dead Code Reachability Analysis

### 📖 Problem Description
During the **Dead Code Elimination (DCE)** phase of a compiler or JIT optimizer, the system must determine which functions can actually execute starting from the program's entry point. Any function that cannot be reached through a valid call sequence is considered dead code and can be safely stripped from the final binary or intermediate representation.

You are given a program's **call graph** as a 2D integer array `graph`, where `graph[i]` contains a list of functions directly invoked by function `i`. Function `0` is guaranteed to be the program's entry point (`main()`). The graph is directed and may contain cycles.

Return `true` if **every** function in the program is reachable from the entry point through zero or more function calls. Otherwise, return `false`.

---

### 🧪 Examples

**Example 1**
```
Input: graph = [[1,2],[3],[4],[],[]]
Output: true
Explanation: The call chains are 0 → 1 → 3 and 0 → 2 → 4. All 5 functions are reachable from the entry point.
```

**Example 2**
```
Input: graph = [[1],[2],[0,3],[],[5]]
Output: false
Explanation: Functions 0, 1, and 2 form a reachable cycle. Function 3 is reachable from 2. However, functions 4 and 5 are never called from the entry point chain. Dead code exists.
```

**Example 3**
```
Input: graph = [[1,2,3],[2],[1],[]]
Output: true
Explanation: Starting from 0, all outgoing calls eventually visit 1, 2, and 3. Every function is reachable.
```

---

### 📏 Constraints
- `n == graph.size()`
- `2 ≤ n ≤ 10^4`
- `0 ≤ graph[i].size() < n`
- `graph[i]` contains unique integers in the range `[0, n - 1]`
- Function `0` is always the designated entry point
- The graph is directed and may contain cycles or disconnected components

---

### 💻 C++ Function Signature
```cpp
#include <vector>

class Solution {
public:
    /**
     * Determines if all functions in the call graph are reachable from the entry point.
     *
     * @param graph Adjacency list representing direct function calls.
     *              graph[i] = list of functions called by function i.
     * @return true if every function is reachable from node 0, false otherwise.
     */
    bool areAllFunctionsReachable(std::vector<std::vector<int>>& graph) {
        // Implementation goes here
    }
};
```
