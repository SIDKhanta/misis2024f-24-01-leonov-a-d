#include <complex/complex.hpp>
#include <iostream>

Complex Complex::operator-() const { return Complex(-re, -im); }

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }


Complex& Complex::operator+=(const Complex& rhs) noexcept { return *this; }
Complex& Complex::operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

Complex& Complex::operator-=(const Complex& rhs) noexcept { return *this; }
Complex& Complex::operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

Complex& Complex::operator*=(const Complex& rhs) noexcept { return *this; }
Complex& Complex::operator*=(const double rhs) noexcept { return *this; }

Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }

Complex& Complex::operator/=(const Complex& rhs) { return *this; }
Complex& Complex::operator/=(const double rhs) { return *this; }

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