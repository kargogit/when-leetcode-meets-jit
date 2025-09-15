### **Valid Syntax Boundaries**

**Problem Context:**
During the syntax analysis phase of a compiler frontend, the parser must validate structural boundaries before constructing the Abstract Syntax Tree (AST). You are tasked with writing a validation module that ensures source code scopes, macro nestings, and functional boundaries are properly opened and closed.

**Description:**
Given a string `tokens` containing exclusively the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the stream of syntactic tokens is valid.

The syntactic structures are considered valid if:
1. Open boundaries must be closed by the exact same type of closing boundary.
    * `(` pairs with `)` representing function/expression boundaries.
    * `{` pairs with `}` representing block scope boundaries.
    * `[` pairs with `]` representing array/macro boundaries.
2. Open boundaries must be closed in the exact correct order (inner-most scopes must be closed before outer scopes).
3. Every closing boundary must have a corresponding, unclosed open boundary of the same type.

**Example 1:**
```text
Input: tokens = "()"
Output: true
Explanation: The function boundary is properly opened and closed.
```

**Example 2:**
```text
Input: tokens = "{([])}"
Output: true
Explanation: The block scope '{' contains a function '()' which contains an array '[]'. All scopes are closed in the exact reverse order they were opened.
```

**Example 3:**
```text
Input: tokens = "{(})"
Output: false
Explanation: The function boundary ')' attempts to close before the inner block scope '}' is closed.
```

**Example 4:**
```text
Input: tokens = "[]}"
Output: false
Explanation: There is an unmatched closing block scope '}'.
```

**Constraints:**
* `1 <= tokens.length <= 10^4`
* `tokens` consists of parentheses only: `'()[]{}'`.

---

### **C++ Function Signature / Skeleton**

```cpp
#include <string>

class CompilerFrontend {
public:
    /**
     * Validates if the sequence of syntactic tokens represents correctly nested boundaries.
     *
     * @param tokens A string of parenthesis/bracket characters representing scopes.
     * @return true if the scopes are perfectly valid, false otherwise.
     */
    bool isValidSyntax(std::string tokens) {
        // TODO: Implement the parser validation logic here

        return false;
    }
};
```
