#include "Eleven.h"

int main() {
    try {
        Eleven num1("1A2"); // 1*11^2 + 10*11^1 + 2*11^0
        Eleven num2("34");  // 3*11^1 + 4*11^0

        Eleven sum = num1 + num2;
        Eleven diff = num1 - num2;

        std::cout << "num1: " << num1;
        std::cout << "num2: " << num2;
        std::cout << "sum: " << sum;
        std::cout << "diff: " << diff;

        std::cout << "num1 == num2: " << (num1 == num2 ? "true" : "false") << std::endl;
        std::cout << "num1 != num2: " << (num1 != num2 ? "true" : "false") << std::endl;
        std::cout << "num1 < num2: " << (num1 < num2 ? "true" : "false") << std::endl;
        std::cout << "num1 > num2: " << (num1 > num2 ? "true" : "false") << std::endl;
        std::cout << "num1 <= num2: " << (num1 <= num2 ? "true" : "false") << std::endl;
        std::cout << "num1 >= num2: " << (num1 >= num2 ? "true" : "false") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
