#include "ration.hpp"
#include <stdexcept>
#include <windows.h>  
#include <cstdlib>    

ration::ration(int numerator, int denominator) : p(numerator), q(denominator) {
    try {
        if (q == 0) throw std::invalid_argument("Denominator cannot be zero");
        reduce();
    }
    catch (const std::invalid_argument& e) {
        MessageBox(NULL, e.what(), "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);  
    }
}

int ration::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void ration::reduce() {
    int divisor = gcd(p, q);
    p /= divisor;
    q /= divisor;
    if (q < 0) {
        p = -p;
        q = -q;
    }
}

ration ration::operator+(const ration& other) const {
    return ration(p * other.q + other.p * q, q * other.q);
}

ration& ration::operator+=(const ration& other) {
    p = p * other.q + other.p * q;
    q *= other.q;
    reduce();
    return *this;
}

ration ration::operator-(const ration& other) const {
    return ration(p * other.q - other.p * q, q * other.q);
}

ration& ration::operator-=(const ration& other) {
    p = p * other.q - other.p * q;
    q *= other.q;
    reduce();
    return *this;
}

ration ration::operator*(const ration& other) const {
    return ration(p * other.p, q * other.q);
}

ration& ration::operator*=(const ration& other) {
    p *= other.p;
    q *= other.q;
    reduce();
    return *this;
}

ration ration::operator/(const ration& other) const {
    try {
        if (other.p == 0) throw std::invalid_argument("Division by zero");
        return ration(p * other.q, q * other.p);
    }
    catch (const std::invalid_argument& e) {
        MessageBox(NULL, e.what(), "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);  
    }
}

ration& ration::operator/=(const ration& other) {
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

bool ration::operator==(const ration& other) const {
    return (p == other.p) && (q == other.q);
}

bool ration::operator!=(const ration& other) const {
    return !(*this == other);
}

std::ostream& ration::writeto(std::ostream& os) const {
    os << p << "/" << q;
    return os;
}

std::istream& ration::readfrom(std::istream& is) {
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

std::ostream& operator<<(std::ostream& os, const ration& r) {
    return r.writeto(os);
}

std::istream& operator>>(std::istream& is, ration& r) {
    return r.readfrom(is);
}