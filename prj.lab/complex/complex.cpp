#include "complex.hpp"

complex complex::operator+(const complex& other) const {
    return complex(re + other.re, im + other.im);
}

complex& complex::operator+=(const complex& other) {
    re += other.re; im += other.im;
    return *this;
}

complex complex::operator-(const complex& other) const {
    return complex(re - other.re, im - other.im);
}

complex& complex::operator-=(const complex& other) {
    re -= other.re; im -= other.im;
    return *this;
}

complex complex::operator*(const complex& other) const {
    return complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

complex& complex::operator*=(const complex& other) {
    double tempRe = re * other.re - im * other.im;
    im = re * other.im + im * other.re; re = tempRe;
    return *this;
}

complex complex::operator/(const complex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0) {
        std::cerr << "Деление на 0!!";
        return complex();
    }
    return complex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
}

complex& complex::operator/=(const complex& other) {
    double denominator = other.re * other.re + other.im * other.im;
    double tempRe = (re * other.re + im * other.im) / denominator;
    im = (im * other.re - re * other.im) / denominator; re = tempRe;
    return *this;
}

bool complex::operator==(const complex& other) const {
    return (re == other.re) && (im == other.im);
}

bool complex::operator!=(const complex& other) const {
    return (re != other.re) || (im != other.im);
}

std::ostream& complex::writeto(std::ostream& os) const {
    os << "(" << re << "+" << im << "i)";
    return os;
}

std::istream& complex::readfrom(std::istream& is) {
    is >> re >> im;
    return is;
}

std::ostream& operator<<(std::ostream& os, const complex& c) {
    return c.writeto(os);
}

std::istream& operator>>(std::istream& is, complex& c) {
    return c.readfrom(is);
}
