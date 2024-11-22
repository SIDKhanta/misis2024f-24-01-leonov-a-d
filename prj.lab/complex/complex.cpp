#include <complex/complex.hpp>
#include <iostream>

Complex Complex::operator-() const { return Complex(-re, -im); }

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex& Complex::operator+=(const Complex& other) {
    re += other.re; im += other.im;
    return *this;
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex& Complex::operator-=(const Complex& other) {
    re -= other.re; im -= other.im;
    return *this;
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

Complex& Complex::operator*=(const Complex& other) {
    double tempRe = re * other.re - im * other.im;
    im = re * other.im + im * other.re; re = tempRe;
    return *this;
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0) {
        std::cerr << "Division by zero";
        return Complex();
    }
    return Complex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.re * other.re + other.im * other.im;
    double tempRe = (re * other.re + im * other.im) / denominator;
    im = (im * other.re - re * other.im) / denominator; re = tempRe;
    return *this;
}

bool Complex::operator==(const Complex& other) const {
    return (re == other.re) && (im == other.im);
}

bool Complex::operator!=(const Complex& other) const {
    return (re != other.re) || (im != other.im);
}

std::ostream& Complex::writeto(std::ostream& os) const {
    os << "(" << re << "+" << im << "i)";
    return os;
}

std::istream& Complex::readfrom(std::istream& is) {
    is >> re >> im;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return c.writeto(os);
}

std::istream& operator>>(std::istream& is, Complex& c) {
    return c.readfrom(is);
}
