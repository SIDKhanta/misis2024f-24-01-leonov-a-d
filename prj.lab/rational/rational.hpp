#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <stdexcept>

struct Rational {
    Rational() : p(0), q(1) { }

    Rational(const Rational&) = default;
    Rational(Rational&&) = default;

    Rational(int numerator) : p(numerator), q(1) { }

    Rational(int numerator, int denominator);

    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    ~Rational() = default;

    Rational operator-() const noexcept;

    Rational operator+(const Rational& other) const;
    Rational& operator+=(const Rational& other);

    Rational operator-(const Rational& other) const;
    Rational& operator-=(const Rational& other);

    Rational operator*(const Rational& other) const;
    Rational& operator*=(const Rational& other);

    Rational operator/(const Rational& other) const;
    Rational& operator/=(const Rational& other);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    std::ostream& writeto(std::ostream& os) const;
    std::istream& readfrom(std::istream& is);

private:
    void reduce();
    int gcd(int a, int b) const;

    int p{ 0 };
    int q{ 1 };
};

std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);

#endif
