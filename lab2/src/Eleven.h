#ifndef ELEVEN_H
#define ELEVEN_H

#include "Array.h"
#include <string>
#include <stdexcept>

class Eleven {
public:
    Eleven();
    Eleven(const std::string& str);
    Eleven(const Eleven& other);
    Eleven(Eleven&& other) noexcept;
    ~Eleven();

    Eleven& operator=(const Eleven& other);
    Eleven& operator=(Eleven&& other) noexcept;

    Eleven operator+(const Eleven& other) const;
    Eleven operator-(const Eleven& other) const;
    Eleven& operator+=(const Eleven& other);
    Eleven& operator-=(const Eleven& other);

    bool operator==(const Eleven& other) const;
    bool operator!=(const Eleven& other) const;
    bool operator<(const Eleven& other) const;
    bool operator>(const Eleven& other) const;
    bool operator<=(const Eleven& other) const;
    bool operator>=(const Eleven& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Eleven& num);
    friend std::istream& operator>>(std::istream& is, Eleven& num);

private:
    Array<unsigned char> digits;

    void normalize();
    void trimLeadingZeros();
};

#endif 
