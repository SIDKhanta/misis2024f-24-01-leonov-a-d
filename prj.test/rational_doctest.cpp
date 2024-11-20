#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[Rational] - ctor") {
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational(3) == Rational(3, 1));
    CHECK(Rational(4, 2) == Rational(2, 1));
    CHECK(Rational(-4, -2) == Rational(2, 1));
    CHECK(Rational(-4, 2) == Rational(-2, 1));
    CHECK(Rational(0, 5) == Rational(0, 1));
}

TEST_CASE("[Rational] - arithmetic operations") {
    Rational r1(1, 2);
    Rational r2(1, 3);

    CHECK(r1 + r2 == Rational(5, 6));
    CHECK(r1 - r2 == Rational(1, 6));
    CHECK(r1 * r2 == Rational(1, 6));
    CHECK(r1 / r2 == Rational(3, 2));
}

TEST_CASE("[Rational] - compound assignment operators") {
    Rational r2(1, 3);

    Rational r1(1, 2);
    r1 += r2;
    CHECK(r1 == Rational(5, 6));

    r1 = Rational(5, 6);
    r1 -= r2;
    CHECK(r1 == Rational(1, 2));

    r1 = Rational(1, 2);
    r1 *= r2;
    CHECK(r1 == Rational(1, 6));

    r1 = Rational(1, 2);
    r1 /= r2;
    CHECK(r1 == Rational(3, 2));
}
