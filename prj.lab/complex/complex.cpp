#include <complex/complex.hpp>
#include <iostream>

Complex Complex::operator-() const { return Complex(-re, -im); }

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex& Complex::operator+=(const Complex& other) {
    re += other.re;
    im += other.im;
    return *this;
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex& Complex::operator-=(const Complex& other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

Complex& Complex::operator*=(const Complex& other) {
    double tempRe = re * other.re - im * other.im;
    im = re * other.im + im * other.re;
    re = tempRe;
    return *this;
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.re * other.re + other.im * other.im;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    double tempRe = (re * other.re + im * other.im) / denominator;
    im = (im * other.re - re * other.im) / denominator;
    re = tempRe;
    return *this;
}

bool Complex::operator==(const Complex& other) const {
    return (re == other.re) && (im == other.im);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
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

Complex operator+(const Complex& c, double scalar) {
    return Complex(c.re + scalar, c.im);
}

Complex operator+(double scalar, const Complex& c) {
    return Complex(c.re + scalar, c.im);
}

Complex operator-(const Complex& c, double scalar) {
    return Complex(c.re - scalar, c.im);
}

Complex operator-(double scalar, const Complex& c) {
    return Complex(scalar - c.re, -c.im);
}

Complex operator*(const Complex& c, double scalar) {
    return Complex(c.re * scalar, c.im * scalar);
}

Complex operator*(double scalar, const Complex& c) {
    return Complex(c.re * scalar, c.im * scalar);
}

Complex operator/(const Complex& c, double scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex(c.re / scalar, c.im / scalar);
}

Complex operator/(double scalar, const Complex& c) {
    double denom = c.re * c.re + c.im * c.im;
    if (denom == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex(scalar * c.re / denom, -scalar * c.im / denom);
}
