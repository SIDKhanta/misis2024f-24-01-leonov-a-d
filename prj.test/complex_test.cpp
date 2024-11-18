#include <complex/complex.hpp>
#include <iostream>

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