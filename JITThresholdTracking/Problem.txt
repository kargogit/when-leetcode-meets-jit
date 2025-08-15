### JIT Tier-up Threshold Tracking

**Problem Statement**

In a Just-In-Time (JIT) compiler with tiered compilation, methods initially execute in a fast-compiling Baseline tier. If a method becomes heavily used ("hot"), it is promoted (tiered-up) to an Optimizing compiler.

To determine a method's priority for promotion, the runtime profiler takes sequential samples of the method's execution frequency over time. You are given an integer array `frequencies` where `frequencies[i]` represents the sampled execution frequency of a specific method at time interval `i`.

The JIT compiler calculates a **tier-up priority score** based on the largest surge in execution frequency. This is defined as the maximum delta (increase) between an earlier frequency sample and a later frequency sample.

Return *the maximum tier-up priority score you can achieve from this method's frequency history*. If the execution frequency only decreases or remains flat over time, return `0`.

---

### Examples

**Example 1:**
```text
Input: frequencies = [7,1,5,3,6,4]
Output: 5
Explanation: The profiler recorded a frequency of 1 at interval 1, and a frequency of 6 at interval 4.
The maximum delta is 6 - 1 = 5.
Note that 7 - 1 = 6 is not a valid delta because the frequency of 7 occurred before the frequency of 1.
```

**Example 2:**
```text
Input: frequencies = [7,6,4,3,1]
Output: 0
Explanation: The method's execution frequency steadily declined over time. There is no positive delta, so the tier-up priority score is 0.
```

---

### Constraints:

* `1 <= frequencies.length <= 10^5`
* `0 <= frequencies[i] <= 10^4`

---

### C++ Scaffolding

```cpp
#include <vector>

class Solution {
public:
    int maxTierUpDelta(std::vector<int>& frequencies) {
        // Your code here

    }
};
```
