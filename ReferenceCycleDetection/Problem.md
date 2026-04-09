# Reference Cycle Detection

### Problem Description
You are implementing a lightweight garbage collector for a managed runtime. During the static analysis pass, the system must detect reference cycles that prevent objects from being reclaimed and cause memory leaks.

Each heap-allocated object holds exactly one outgoing reference to another object (or `nullptr` if it is terminal). Given a starting object `start`, determine if traversing the reference chain eventually revisits an already-seen object, forming a cycle. If a cycle exists, the collector must flag it; otherwise, the chain terminates safely.

Return `true` if a reference cycle is detected, and `false` otherwise.

### Examples
**Example 1:**
```
Input: start = obj_0, chain: obj_0 → obj_1 → obj_2 → obj_1 → ...
Output: true
Explanation: Following references from obj_0 eventually reaches obj_1 again, forming a cycle.
```

**Example 2:**
```
Input: start = obj_0, chain: obj_0 → obj_1 → obj_2 → nullptr
Output: false
Explanation: The reference chain terminates at a null reference without revisiting any object.
```

### Constraints
- The number of objects in the system is in the range `[0, 10^4]`.
- Each object's reference points to either `nullptr` or a valid object within the system.
- **System Requirement:** The analysis pass must run in `O(1)` auxiliary memory to comply with strict runtime memory budgets during GC preparation.

### C++ Skeleton
```cpp
/**
 * Definition for a heap object in the reference graph.
 * Represents a single node in the object reference chain.
 */
struct HeapObject {
    int id;
    HeapObject* next;
    HeapObject(int val) : id(val), next(nullptr) {}
};

class GarbageCollector {
public:
    /**
     * Analyzes the reference chain starting from `start` to detect cycles.
     *
     * @param start Pointer to the initial object for analysis
     * @return true if a reference cycle exists, false otherwise
     */
    bool hasReferenceCycle(HeapObject* start) {
        // TODO: Implement cycle detection under O(1) auxiliary space constraint
    }
};
```
