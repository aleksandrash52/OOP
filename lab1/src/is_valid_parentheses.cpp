#include "is_valid_parentheses.h"
#include <stack>

bool is_valid_parentheses(const std::string& s) {
    std::stack<char> stack;

    for (char ch : s) {
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            if (stack.empty()) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}
