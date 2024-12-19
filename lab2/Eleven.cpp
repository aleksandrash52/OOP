#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Eleven {
public:
    // Конструктор по умолчанию
    Eleven() : digits(1, 0) {}

    // Конструктор из строки
    Eleven(const std::string& str) {
        digits.clear();
        for (char ch : str) {
            if (ch >= '0' && ch <= '9') {
                digits.push_back(ch - '0');
            } else if (ch == 'A') {
                digits.push_back(10);
            } else {
                throw std::invalid_argument("Invalid character in input string");
            }
        }
        std::reverse(digits.begin(), digits.end());
    }

    // Метод для вывода числа
    void print() const {
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it < 10) {
                std::cout << static_cast<char>('0' + *it);
            } else {
                std::cout << 'A';
            }
        }
        std::cout << std::endl;
    }

    // Перегрузка оператора сложения
    Eleven operator+(const Eleven& other) const {
        Eleven result;
        size_t max_size = std::max(digits.size(), other.digits.size());
        result.digits.resize(max_size + 1, 0);

        for (size_t i = 0; i < max_size; ++i) {
            unsigned char digit1 = (i < digits.size()) ? digits[i] : 0;
            unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;
            unsigned char sum = digit1 + digit2 + result.digits[i];
            result.digits[i] = sum % 11;
            result.digits[i + 1] = sum / 11;
        }

        // Удалить ведущие нули
        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        return result;
    }

private:
    std::vector<unsigned char> digits;
};

int main() {
    Eleven num1("1A2"); // 1*11^2 + 10*11^1 + 2*11^0
    Eleven num2("34");  // 3*11^1 + 4*11^0

    Eleven sum = num1 + num2;

    std::cout << "num1: ";
    num1.print();

    std::cout << "num2: ";
    num2.print();

    std::cout << "sum: ";
    sum.print();

    return 0;
}
