#include <complex/complex.hpp>
#include <iostream>

int main() {
    Complex n1, n2;

    std::cin >> n1;
    std::cin >> n2;

    Complex sum = n1 + n2;
    std::cout << sum << "\n";

    Complex raz = n1 - n2;
    std::cout << raz << "\n";

    Complex umn = n1 * n2;
    std::cout << umn << "\n";

    Complex del = n1 / n2;
    std::cout << del;

    return 0;
}