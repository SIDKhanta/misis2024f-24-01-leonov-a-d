#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

struct complex {
    double re{ 0.0 };
    double im{ 0.0 };

    complex() = default;
    complex(double real, double imag) : re(real), im(imag) {}

    complex operator+(const complex& other) const;
    complex& operator+=(const complex& other);

    complex operator-(const complex& other) const;
    complex& operator-=(const complex& other);

    complex operator*(const complex& other) const;
    complex& operator*=(const complex& other);

    complex operator/(const complex& other) const;
    complex& operator/=(const complex& other);

    bool operator==(const complex& other) const;
    bool operator!=(const complex& other) const;

    std::ostream& writeto(std::ostream& os) const;
    std::istream& readfrom(std::istream& is);
};

std::ostream& operator<<(std::ostream& os, const complex& c);
std::istream& operator>>(std::istream& is, complex& c);

#endif
