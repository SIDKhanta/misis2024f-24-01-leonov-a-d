#ifndef RATION_HPP
#define RATION_HPP

#include <iostream>
#include <stdexcept>

struct ration {
    ration() : p(0), q(1) { }  

    ration(const ration&) = default;
    ration(ration&&) = default;

    ration(int numerator) : p(numerator), q(1) { } 

    ration(int numerator, int denominator);

    ration& operator=(const ration&) = default;
    ration& operator=(ration&&) = default;

    ~ration() = default;

    ration operator+(const ration& other) const;
    ration& operator+=(const ration& other);

    ration operator-(const ration& other) const;
    ration& operator-=(const ration& other);

    ration operator*(const ration& other) const;
    ration& operator*=(const ration& other);

    ration operator/(const ration& other) const;
    ration& operator/=(const ration& other);

    bool operator==(const ration& other) const;
    bool operator!=(const ration& other) const;

    std::ostream& writeto(std::ostream& os) const;
    std::istream& readfrom(std::istream& is);

private:
    void reduce();  
    int gcd(int a, int b) const;  

    int p{ 0 };  
    int q{ 1 };  
};

std::ostream& operator<<(std::ostream& os, const ration& r);
std::istream& operator>>(std::istream& is, ration& r);

#endif
