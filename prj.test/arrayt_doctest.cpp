#include <arrayt/arrayt.hpp>
#include <string>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("ArrayT - int type") {
    ArrayT<int> arr(5);
    CHECK(arr.Size() == 5);
    for (std::ptrdiff_t i = 0; i < arr.Size(); ++i) {
        CHECK(arr[i] == 0);
    }

    arr[0] = 10;
    arr[1] = 20;

    arr.Insert(1, 15);

    CHECK(arr.Size() == 6);
    CHECK(arr[0] == 10);
    CHECK(arr[1] == 15);
    CHECK(arr[2] == 20);

    arr.Remove(1);

    CHECK(arr.Size() == 5);
    CHECK(arr[0] == 10);
    CHECK(arr[1] == 20);
}

TEST_CASE("ArrayT - double type") {
    ArrayT<double> arr(3);
    CHECK(arr.Size() == 3);
    for (std::ptrdiff_t i = 0; i < arr.Size(); ++i) {
        CHECK(arr[i] == 0.0);
    }

    arr[0] = 1.5;
    arr[1] = 2.5;

    arr.Insert(1, 3.5);

    CHECK(arr.Size() == 4);
    CHECK(arr[0] == 1.5);
    CHECK(arr[1] == 3.5);
    CHECK(arr[2] == 2.5);

    arr.Remove(2);

    CHECK(arr.Size() == 3);
}

TEST_CASE("ArrayT - std::string type") {
    ArrayT<std::string> arr(2);
    CHECK(arr.Size() == 2);

    arr[0] = "Hello";
    arr[1] = "World";

    arr.Insert(1, "Beautiful");

    CHECK(arr.Size() == 3);
    CHECK(arr[0] == "Hello");
    CHECK(arr[1] == "Beautiful");
    CHECK(arr[2] == "World");

    arr.Remove(0);

    CHECK(arr.Size() == 2);
    CHECK(arr[0] == "Beautiful");
}

TEST_CASE("ArrayT - Out of Range Access") {
    ArrayT<int> arr(3);

    CHECK_THROWS_AS(arr[-1], std::out_of_range);
    CHECK_THROWS_AS(arr[3], std::out_of_range);

    CHECK_THROWS_AS(arr.Insert(-1, 5), std::out_of_range);
    CHECK_THROWS_AS(arr.Insert(4, 5), std::out_of_range);

    CHECK_THROWS_AS(arr.Remove(-1), std::out_of_range);
    CHECK_THROWS_AS(arr.Remove(3), std::out_of_range);
}