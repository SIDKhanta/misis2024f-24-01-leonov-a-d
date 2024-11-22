#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

struct Complex {
    Complex() = default;

    Complex(const Complex&) = default;

    Complex(Complex&&) = default;

    explicit Complex(const double real) : re(real) { }

    Complex(double real, double imag) : re(real), im(imag) {}

    Complex& operator=(const Complex&) = default;

    Complex& operator=(Complex&&) = default;

    ~Complex() = default;

    Complex operator-() const;

    Complex operator+(const Complex& other) const;
    Complex& operator+=(const Complex& other);

    Complex operator-(const Complex& other) const;
    Complex& operator-=(const Complex& other);

    Complex operator*(const Complex& other) const;
    Complex& operator*=(const Complex& other);

    Complex operator/(const Complex& other) const;
    Complex& operator/=(const Complex& other);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    std::ostream& writeto(std::ostream& os) const;
    std::istream& readfrom(std::istream& is);

    double re{ 0.0 };
    double im{ 0.0 };
};

std::ostream& operator<<(std::ostream& os, const Complex& c);
std::istream& operator>>(std::istream& is, Complex& c);

#endif
