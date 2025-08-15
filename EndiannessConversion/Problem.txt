**Reverse Bits**

**Description**
Given a 32‑bit unsigned integer `n`, reverse the order of its bits (the most‑significant bit becomes the least‑significant bit, the second‑most‑significant becomes the second‑least‑significant, and so on) and return the resulting integer.

**Function signature (example)**
```cpp
uint32_t reverseBits(uint32_t n);
```

**Example 1**
*Input*: `n = 0b00000010100101000001111010011100` (decimal 43261596)
*Output*: `964176192`
*Binary*: `0b00111001011110000010100101000000`

**Example 2**
*Input*: `n = 0b11111111111111111111111111111101` (decimal 4294967293)
*Output*: `3221225471`
*Binary*: `0b10111111111111111111111111111111`

**Constraints**
- `0 ≤ n < 2³²` (the input fits in an unsigned 32‑bit integer).
- The result also fits in an unsigned 32‑bit integer.

**Complexity**
- Time: **O(1)** – only a fixed number of bitwise operations, independent of input size.
- Space: **O(1)** – only a constant amount of extra memory.

**Note**
You may implement the reversal using only bit‑wise shift and mask operations; the use of built‑in reverse utilities or loops over the 32 bits is acceptable as long as the overall runtime stays constant.
