#include <iostream>
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int executeBytecode(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const std::string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();

                if      (token == "+") stack.push(a + b);
                else if (token == "-") stack.push(a - b);
                else if (token == "*") stack.push(a * b);
                else                   stack.push(a / b);
            } else {
                stack.push(std::stoi(token));
            }
        }

        return stack.top();
    }
};

int main() {
    Solution sol;

    std::vector<std::string> t1 = {"2", "1", "+", "3", "*"};
    std::cout << sol.executeBytecode(t1) << "\n"; // 9

    std::vector<std::string> t2 = {"4", "13", "5", "/", "+"};
    std::cout << sol.executeBytecode(t2) << "\n"; // 6

    std::vector<std::string> t3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << sol.executeBytecode(t3) << "\n"; // 22

    return 0;
}
