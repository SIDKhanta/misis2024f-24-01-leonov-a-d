#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>

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

    static const char leftbr{ '{' };
    static const char sep{ ',' };
    static const char rightbr{ '}' };
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

Complex operator/(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator/(const Complex& lhs, const double rhs) noexcept;
Complex operator/(const double lhs, const Complex& rhs) noexcept;

inline std::ostream& operator<<(std::ostream& os, Complex& a) {
    return a.writeto(os);
}

inline std::istream& operator>>(std::istream& is, Complex& a) {
    return a.readfrom(is);
}

#endif