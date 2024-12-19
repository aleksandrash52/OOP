#ifndef ELEVEN_H
#define ELEVEN_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

class Eleven {
public:
    // Конструкторы
    Eleven();
    Eleven(const std::string& str);

    // Методы
    void print() const;
    Eleven& operator+=(const Eleven& other);
    Eleven& operator-=(const Eleven& other);
    Eleven& operator=(const Eleven& other);

    // Операторы сравнения
    bool operator==(const Eleven& other) const;
    bool operator!=(const Eleven& other) const;
    bool operator<(const Eleven& other) const;
    bool operator>(const Eleven& other) const;
    bool operator<=(const Eleven& other) const;
    bool operator>=(const Eleven& other) const;

private:
    std::vector<unsigned char> digits;

    // Вспомогательные методы
    void normalize();
    void trimLeadingZeros();
};

// Операторы
Eleven operator+(const Eleven& lhs, const Eleven& rhs);
Eleven operator-(const Eleven& lhs, const Eleven& rhs);
std::ostream& operator<<(std::ostream& os, const Eleven& num);

#endif // ELEVEN_H
