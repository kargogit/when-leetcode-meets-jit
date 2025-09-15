#include <iostream>
#include <string>
#include <stack>

class CompilerFrontend {
public:
    bool isValidSyntax(std::string tokens) {
        std::stack<char> open;

        for (char c : tokens) {
            if (c == '(' || c == '{' || c == '[') {
                open.push(c);
            } else {
                if (open.empty()) return false;

                char top = open.top();
                open.pop();

                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }

        return open.empty();
    }
};

int main() {
    CompilerFrontend parser;

    std::cout << std::boolalpha;
    std::cout << parser.isValidSyntax("()")      << "\n"; // true
    std::cout << parser.isValidSyntax("{([])}")  << "\n"; // true
    std::cout << parser.isValidSyntax("{(})")    << "\n"; // false
    std::cout << parser.isValidSyntax("[]}")     << "\n"; // false

    return 0;
}
