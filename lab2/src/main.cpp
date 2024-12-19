#include <iostream>
#include "Eleven.h"

int main() {
    Eleven num1("1A2"); 
    Eleven num2("34");  

    Eleven sum = num1 + num2;
    Eleven diff = num1 - num2;

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "sum: " << sum << std::endl;
    std::cout << "diff: " << diff << std::endl;

    std::cout << "num1 == num2: " << (num1 == num2 ? "true" : "false") << std::endl;
    std::cout << "num1 != num2: " << (num1 != num2 ? "true" : "false") << std::endl;
    std::cout << "num1 < num2: " << (num1 < num2 ? "true" : "false") << std::endl;
    std::cout << "num1 > num2: " << (num1 > num2 ? "true" : "false") << std::endl;
    std::cout << "num1 <= num2: " << (num1 <= num2 ? "true" : "false") << std::endl;
    std::cout << "num1 >= num2: " << (num1 >= num2 ? "true" : "false") << std::endl;

    return 0;
}
