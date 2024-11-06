#include <ration/ration.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"

TEST_CASE("[ration] - ctor") {
    CHECK(ration() == ration(0, 1));         // Тест конструктора по умолчанию
    CHECK(ration(3) == ration(3, 1));        // Тест конструктора для целых чисел
    CHECK(ration(4, 2) == ration(2, 1));     // Проверка сокращения дроби
    CHECK(ration(-4, -2) == ration(2, 1));   // Проверка знака
    CHECK(ration(-4, 2) == ration(-2, 1));   // Проверка знака для отрицательных дробей
    CHECK(ration(0, 5) == ration(0, 1));     // Проверка для 0 в числителе
}

TEST_CASE("[ration] - arithmetic operations") {
    ration r1(1, 2);
    ration r2(1, 3);

    CHECK(r1 + r2 == ration(5, 6));           // Проверка сложения
    CHECK(r1 - r2 == ration(1, 6));           // Проверка вычитания
    CHECK(r1 * r2 == ration(1, 6));           // Проверка умножения
    CHECK(r1 / r2 == ration(3, 2));           // Проверка деления
}

TEST_CASE("[ration] - compound assignment operators") {
    ration r1(1, 2);
    ration r2(1, 3);

    r1 += r2;
    CHECK(r1 == ration(5, 6));                // Проверка +=

    r1 -= r2;
    CHECK(r1 == ration(1, 2));                // Проверка -=

    r1 *= r2;
    CHECK(r1 == ration(1, 6));                // Проверка *=

    r1 /= r2;
    CHECK(r1 == ration(3, 2));                // Проверка /=
}
