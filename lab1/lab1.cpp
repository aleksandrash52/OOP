#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& s) {
    std::stack<char> stack;

    for (char ch : s) {
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            if (!stack.empty()) {
                stack.pop();
            } else {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    std::cout << std::boolalpha; // для вывода true/false вместо 1/0
    std::cout << isValidParentheses("()") << std::endl; // сюда вводить любую последовательность скобочек
    return 0;
}
