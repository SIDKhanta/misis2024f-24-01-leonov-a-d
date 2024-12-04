#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

struct Complex {
    Complex() = default;

    Complex(const Complex&) = default;

    Complex(Complex&&) = default;

    explicit Complex(const double real) : re(real) {}

    Complex(double real, double imag) : re(real), im(imag) {}

    Complex& operator=(const Complex&) = default;

    Complex& operator=(Complex&&) = default;

    ~Complex() = default;

    Complex operator-() const;

    Complex& operator+=(const Complex& rhs) noexcept;
    Complex& operator+=(const double rhs) noexcept;

    Complex& operator-=(const Complex& rhs) noexcept;
    Complex& operator-=(const double rhs) noexcept;

    Complex& operator*=(const Complex& rhs) noexcept;
    Complex& operator*=(const double rhs) noexcept;

    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    std::ostream& writeto(std::ostream& os) const;
    std::istream& readfrom(std::istream& is);

    double re{ 0.0 };
    double im{ 0.0 };
};

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator+(const Complex& lhs, const double rhs) noexcept;
Complex operator+(const double lhs, const Complex& rhs) noexcept;

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator-(const Complex& lhs, const double rhs) noexcept;
Complex operator-(const double lhs, const Complex& rhs) noexcept;

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;

Complex operator*(const Complex& lhs, const double rhs) noexcept;

Complex operator*(const double lhs, const Complex& rhs) noexcept;

Complex operator/(const Complex& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const double rhs);

Complex operator/(const double lhs, const Complex& rhs);

std::ostream& operator<<(std::ostream& os, const Complex& c);
std::istream& operator>>(std::istream& is, Complex& c);

#endif
