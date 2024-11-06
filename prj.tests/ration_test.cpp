#include <ration/ration.hpp>
#include <iostream>

int main() {
    ration n1, n2;

    std::cout << "Введите первую дробь (в формате a/b): ";
    std::cin >> n1;
    std::cout << "Введите вторую дробь (в формате a/b): ";
    std::cin >> n2;

    ration sum = n1 + n2;
    std::cout << "Сумма: " << sum << "\n";

    ration raz = n1 - n2;
    std::cout << "Разность: " << raz << "\n";

    ration umn = n1 * n2;
    std::cout << "Произведение: " << umn << "\n";

    try {
        ration del = n1 / n2;
        std::cout << "Частное: " << del << "\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
