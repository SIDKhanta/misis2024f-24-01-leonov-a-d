#include <iostream>
#include <sstream>
#include <complex/complex.hpp>

Complex::Complex() {
    re = 0.0;
    im = 0.0;
}

Complex::Complex(const double real) {
    re = real;
    im = 0.0;
}

Complex::Complex(const double real, const double imaginary) {
    re = real;
    im = imaginary;
}

bool Complex::operator==(const Complex& a) const noexcept {
    double eps = 2 * std::numeric_limits<double>::epsilon();
    return ((std::abs(re - a.re) < eps) && (std::abs(im - a.im) < eps));
}

bool Complex::operator!=(const Complex& a) const noexcept {
    return !(*this == a);
}

Complex Complex::operator-() const noexcept {
    return Complex(-re, -im);
}

Complex& Complex::operator+=(const Complex& a) {
    re += a.re;
    im += a.im;
    return *this;
}

Complex& Complex::operator+=(const double a) {
    return operator+=(Complex(a));
}

Complex& Complex::operator-=(const Complex& a) {
    re -= a.re;
    im -= a.im;
    return *this;
}

Complex& Complex::operator-=(const double a) {
    return operator-=(Complex(a));
}

Complex& Complex::operator*=(const Complex& a) {
    double templ = re;
    re = re * a.re - im * a.im;
    im = templ * a.im + a.re * im;
    return *this;
}

Complex& Complex::operator*=(const double a) {
    return operator*=(Complex(a));
}


Complex& Complex::operator/=(const Complex& a) {
    Complex b(0.0);
    if (a != b) {
        double templ = re;
        re = (re * a.re + im * a.im) / ((a.re * a.re) + (a.im * a.im));
        im = ((im * a.re) - (templ * a.im)) / ((a.re * a.re) + (a.im * a.im));
    }
    else {
        throw std::invalid_argument("Division by zero error");
    }
    return *this;
}

Complex& Complex::operator/=(const double a) {
    return operator/=(Complex(a));
}

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a) += b;
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a) -= b;
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a) *= b;
}

Complex operator/(const Complex& a, const Complex& b) {
    return Complex(a) /= b;
}

Complex operator+(const Complex& a, const double b) {
    return Complex(a) += b;
}

Complex operator-(const Complex& a, const double b) {
    return Complex(a) -= b;
}

Complex operator*(const Complex& a, const double b) {
    return Complex(a) *= b;
}

Complex operator/(const Complex& a, const double b) {
    return Complex(a) /= b;
}

Complex operator+(const double b, const Complex& a) {
    return Complex(a) += b;
}

Complex operator-(const double b, const Complex& a) {
    return Complex(b) -= a;
}

Complex operator*(const double b, const Complex& a) {
    return Complex(b) *= a;
}

Complex operator/(const double b, const Complex& a) {
    return Complex(b) /= a;
}


std::istream& Complex::input(std::istream& in) {
    char leftBrace = 0, rightBrace = 0, separator = 0;
    double real = 0.0, imaginary = 0.0;
    in >> leftBrace >> real >> separator >> imaginary >> rightBrace;

    if (in.good()) {
        if ((leftBrace == leftbr) && (separator == sep) && (rightBrace == rightbr)) {
            re = real;
            im = imaginary;
        }
        else {
            in.setstate(std::ios_base::failbit);
        }
    }
    return in;
}

std::ostream& Complex::output(std::ostream& out) {
    out << leftbr << re << sep << im << rightbr;
    return out;
}