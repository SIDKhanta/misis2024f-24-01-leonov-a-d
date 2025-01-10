#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>

struct Complex {
    double re = 0.0;
    double im = 0.0;
    Complex();
    Complex(const double real);
    Complex(const double real, const double imaginary);

    Complex& operator=(const Complex&) = default;
    ~Complex() = default;

    bool operator==(const Complex& a) const noexcept;
    bool operator!=(const Complex& a) const noexcept;
    Complex operator-() const noexcept;

    Complex& operator+=(const Complex& a);
    Complex& operator-=(const Complex& a);
    Complex& operator*=(const Complex& a);
    Complex& operator/=(const Complex& a);

    Complex& operator+=(const double b);
    Complex& operator-=(const double b);
    Complex& operator*=(const double b);
    Complex& operator/=(const double b);

    std::ostream& output(std::ostream& out);
    std::istream& input(std::istream& in);

    static const char leftbr{ '{' };
    static const char sep{ ',' };
    static const char rightbr{ '}' };
};

Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);

Complex operator+(const Complex& a, const double b);
Complex operator-(const Complex& a, const double b);
Complex operator*(const Complex& a, const double b);
Complex operator/(const Complex& a, const double b);

Complex operator+(const double b, const Complex& a);
Complex operator-(const double b, const Complex& a);
Complex operator*(const double b, const Complex& a);
Complex operator/(const double b, const Complex& a);

inline std::ostream& operator<<(std::ostream& out, Complex& a) {
    return a.output(out);
}

inline std::istream& operator>>(std::istream& in, Complex& a) {
    return a.input(in);
}

#endif