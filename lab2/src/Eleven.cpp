#include "Eleven.h"
#include <algorithm>
#include <cmath>

Eleven::Eleven() : digits(1, 0) {}

Eleven::Eleven(const std::string& str) {
    digits.resize(str.size());
    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (ch >= '0' && ch <= '9') {
            digits[i] = ch - '0';
        } else if (ch == 'A') {
            digits[i] = 10;
        } else {
            throw std::invalid_argument("Invalid character in input string");
        }
    }
    std::reverse(digits.begin(), digits.end());
    trimLeadingZeros();
}

Eleven::Eleven(const Eleven& other) : digits(other.digits) {}

Eleven::Eleven(Eleven&& other) noexcept : digits(std::move(other.digits)) {}

Eleven::~Eleven() {}

Eleven& Eleven::operator=(const Eleven& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

Eleven& Eleven::operator=(Eleven&& other) noexcept {
    if (this != &other) {
        digits = std::move(other.digits);
    }
    return *this;
}

Eleven Eleven::operator+(const Eleven& other) const {
    Eleven result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    result.digits.resize(maxSize + 1, 0);

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < digits.size()) ? digits[i] : 0;
        unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;
        unsigned char sum = digit1 + digit2 + result.digits[i];
        result.digits[i] = sum % 11;
        result.digits[i + 1] = sum / 11;
    }

    result.trimLeadingZeros();
    return result;
}

Eleven Eleven::operator-(const Eleven& other) const {
    if (*this < other) {
        throw std::invalid_argument("Subtraction result is negative");
    }

    Eleven result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    result.digits.resize(maxSize, 0);

    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < digits.size()) ? digits[i] : 0;
        unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;
        if (digit1 < digit2) {
            result.digits[i + 1]--;
            digit1 += 11;
        }
        result.digits[i] = digit1 - digit2;
    }

    result.trimLeadingZeros();
    return result;
}

Eleven& Eleven::operator+=(const Eleven& other) {
    *this = *this + other;
    return *this;
}

Eleven& Eleven::operator-=(const Eleven& other) {
    *this = *this - other;
    return *this;
}

bool Eleven::operator==(const Eleven& other) const {
    return digits == other.digits;
}

bool Eleven::operator!=(const Eleven& other) const {
    return !(*this == other);
}

bool Eleven::operator<(const Eleven& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Eleven::operator>(const Eleven& other) const {
    return other < *this;
}

bool Eleven::operator<=(const Eleven& other) const {
    return !(other < *this);
}

bool Eleven::operator>=(const Eleven& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Eleven& num) {
    for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
        if (*it < 10) {
            os << static_cast<char>('0' + *it);
        } else {
            os << 'A';
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Eleven& num) {
    std::string input;
    is >> input;
    num = Eleven(input);
    return is;
}

void Eleven::normalize() {
    for (size_t i = 0; i < digits.size(); ++i) {
        if (digits[i] >= 11) {
            digits[i + 1] += digits[i] / 11;
            digits[i] %= 11;
        }
    }
    trimLeadingZeros();
}

void Eleven::trimLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}
