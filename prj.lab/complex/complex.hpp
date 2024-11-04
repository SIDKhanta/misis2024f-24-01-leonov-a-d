#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

struct complex {
    complex() = default;
    
    complex(const complex&) = default;

    complex(complex&&) = default;

    explicit complex(const double real) : re(real) { }

    complex(double real, double imag) : re(real), im(imag) {}

    complex& operator=(const complex&) = default;

    complex& operator=(complex&&) = default;

    ~complex() = default;

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

    double re{ 0.0 };
    double im{ 0.0 };
};

std::ostream& operator<<(std::ostream& os, const complex& c);
std::istream& operator>>(std::istream& is, complex& c);

#endif
