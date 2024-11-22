#include <rational/rational.hpp>
#include <stdexcept>
#include <windows.h>
#include <cstdlib>

Rational Rational::operator-() const noexcept { return Rational(-p, q); }

Rational::Rational(int numerator, int denominator) : p(numerator), q(denominator) {
    try {
        if (q == 0) throw std::invalid_argument("Denominator cannot be zero");
        reduce();
    }
    catch (const std::invalid_argument& e) {
        MessageBox(NULL, e.what(), "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }
}

int Rational::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Rational::reduce() {
    int divisor = gcd(p, q);
    p /= divisor;
    q /= divisor;
    if (q < 0) {
        p = -p;
        q = -q;
    }
}

Rational Rational::operator+(const Rational& other) const {
    return Rational(p * other.q + other.p * q, q * other.q);
}

Rational& Rational::operator+=(const Rational& other) {
    p = p * other.q + other.p * q;
    q *= other.q;
    reduce();
    return *this;
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(p * other.q - other.p * q, q * other.q);
}

Rational& Rational::operator-=(const Rational& other) {
    p = p * other.q - other.p * q;
    q *= other.q;
    reduce();
    return *this;
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(p * other.p, q * other.q);
}

Rational& Rational::operator*=(const Rational& other) {
    p *= other.p;
    q *= other.q;
    reduce();
    return *this;
}

Rational Rational::operator/(const Rational& other) const {
    try {
        if (other.p == 0) throw std::invalid_argument("Division by zero");
        return Rational(p * other.q, q * other.p);
    }
    catch (const std::invalid_argument& e) {
        MessageBox(NULL, e.what(), "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }
}

Rational& Rational::operator/=(const Rational& other) {
    try {
        if (other.p == 0) throw std::invalid_argument("Division by zero");
        p *= other.q;
        q *= other.p;
        reduce();
        return *this;
    }
    catch (const std::invalid_argument& e) {
        MessageBox(NULL, e.what(), "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }
}

bool Rational::operator==(const Rational& other) const {
    return (p == other.p) && (q == other.q);
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

std::ostream& Rational::writeto(std::ostream& os) const {
    os << p << "/" << q;
    return os;
}

std::istream& Rational::readfrom(std::istream& is) {
    char sep;
    is >> p >> sep >> q;
    try {
        if (q == 0) throw std::invalid_argument("Denominator cannot be zero");
        reduce();
    }
    catch (const std::invalid_argument& e) {
        MessageBox(NULL, e.what(), "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    return r.writeto(os);
}

std::istream& operator>>(std::istream& is, Rational& r) {
    return r.readfrom(is);
}
