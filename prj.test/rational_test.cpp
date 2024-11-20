#include <rational/rational.hpp>
#include <iostream>

int main() {
    Rational n1, n2;

    std::cout << "Enter the first fraction (in a/b format): ";
    std::cin >> n1;
    std::cout << "Enter the second fraction (in a/b format): ";
    std::cin >> n2;

    Rational sum = n1 + n2;
    std::cout << "Summa: " << sum << "\n";

    Rational raz = n1 - n2;
    std::cout << "Difference: " << raz << "\n";

    Rational umn = n1 * n2;
    std::cout << "Product: " << umn << "\n";

    try {
        Rational del = n1 / n2;
        std::cout << "Quotient: " << del << "\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
