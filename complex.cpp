#include <iostream>

struct complex {
    double re{ 0.0 };
    double im{ 0.0 };

    complex() = default;
    complex(double real, double imag) : re(real), im(imag) {}

    complex operator+(const complex& other) const {
        return complex(re + other.re, im + other.im);
    }
    complex& operator+=(const complex& other) {
        re += other.re; im += other.im;
        return *this;
    }

    complex operator-(const complex& other) const {
        return complex(re - other.re, im - other.im);
    }
    complex& operator-=(const complex& other) {
        re -= other.re; im -= other.im;
        return *this;
    }

    complex operator*(const complex& other) const {
        return complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }
    complex& operator*=(const complex& other) {
        double tempRe = re * other.re - im * other.im;
        im = re * other.im + im * other.re; re = tempRe;
        return *this;
    }

    complex operator/(const complex& other) const {
        double denom = other.re * other.re + other.im * other.im;
        if (denom == 0) {
            std::cerr << "Ошибка, деление на 0";
            return complex();
        }
        return complex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
    }
    complex& operator/=(const complex& other) {
        double denominator = other.re * other.re + other.im * other.im;
        double tempRe = (re * other.re + im * other.im) / denominator;
        im = (im * other.re - re * other.im) / denominator; re = tempRe;
        return *this;
    }

    bool operator==(const complex& other) const {
        return (re == other.re) && (im == other.im);
    }

    bool operator!=(const complex& other) const {
        return (re != other.re) || (im != other.im);
    }

    std::ostream& writeto(std::ostream& os) const {
        os << "(" << re << "+" << im << "i)";
        return os;
    }
    std::istream& readfrom(std::istream& is) {
        is >> re >> im;
        return is;
    }
};

std::ostream& operator<<(std::ostream& os, const complex& c) {
    return c.writeto(os);
}

std::istream& operator>>(std::istream& is, complex& c) {
    return c.readfrom(is);
    return c.readfrom(is);
}

int main() {
    complex n1, n2;

    std::cin >> n1;
    std::cin >> n2;

    complex sum = n1 + n2;
    std::cout << sum << "\n";

    complex raz = n1 - n2;
    std::cout << raz << "\n";

    complex umn = n1 * n2;
    std::cout << umn << "\n";

    complex del = n1 / n2;
    std::cout << del;

    return 0;
}