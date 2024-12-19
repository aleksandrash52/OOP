#include <iostream>
#include "is_valid_parentheses.h"

int main() {
    std::string input;
    std::cout << "Введите строку скобок: ";
    std::getline(std::cin, input);

    if (is_valid_parentheses(input)) {
        std::cout << "Строка сбалансирована." << std::endl;
    } else {
        std::cout << "Строка несбалансирована." << std::endl;
    }

    return 0;
}
