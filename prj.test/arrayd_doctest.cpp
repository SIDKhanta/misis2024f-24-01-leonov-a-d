#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <arrayd/arrayd.hpp>

TEST_SUITE("dynarr") {
    TEST_CASE("Default constructor creates an empty array") {
        dynarr arr;
        CHECK(arr.getSize() == 0);
        CHECK(arr.getCapacity() == 0);
        CHECK(arr.isEmpty());
    }

    TEST_CASE("Constructor with initial capacity initializes correctly") {
        dynarr arr(5);
        CHECK(arr.getSize() == 0);
        CHECK(arr.getCapacity() == 5);
        CHECK(arr.isEmpty());
    }

    TEST_CASE("pushBack adds elements and resizes if needed") {
        dynarr arr;
        arr.pushBack(1.1);
        CHECK(arr.getSize() == 1);
        CHECK(arr[0] == doctest::Approx(1.1));

        arr.pushBack(2.2);
        CHECK(arr.getSize() == 2);
        CHECK(arr[1] == doctest::Approx(2.2));

        arr.pushBack(3.3); 
        CHECK(arr.getSize() == 3);
        CHECK(arr[2] == doctest::Approx(3.3));
    }

    TEST_CASE("popBack removes the last element") {
        dynarr arr;
        arr.pushBack(1.1);
        arr.pushBack(2.2);
        CHECK(arr.getSize() == 2);

        arr.popBack();
        CHECK(arr.getSize() == 1);
        CHECK(arr[0] == doctest::Approx(1.1));

        arr.popBack();
        CHECK(arr.getSize() == 0);
        CHECK(arr.isEmpty());

        CHECK_THROWS_AS(arr.popBack(), std::out_of_range);
    }

    TEST_CASE("get retrieves correct element") {
        dynarr arr(3);
        arr.pushBack(1.1);
        arr.pushBack(2.2);
        arr.pushBack(3.3);

        CHECK(arr.get(0) == doctest::Approx(1.1));
        CHECK(arr.get(1) == doctest::Approx(2.2));
        CHECK(arr.get(2) == doctest::Approx(3.3));

        CHECK_THROWS_AS(arr.get(3), std::out_of_range);
        CHECK_THROWS_AS(arr.get(-1), std::out_of_range);
    }

    TEST_CASE("set updates correct element") {
        dynarr arr(3);
        arr.pushBack(1.1);
        arr.pushBack(2.2);
        arr.pushBack(3.3);

        arr.set(1, 4.4);
        CHECK(arr.get(1) == doctest::Approx(4.4));

        CHECK_THROWS_AS(arr.set(3, 5.5), std::out_of_range);
    }

    TEST_CASE("clear empties the array") {
        dynarr arr(5);
        arr.pushBack(1.1);
        arr.pushBack(2.2);

        arr.clear();
        CHECK(arr.getSize() == 0);
        CHECK(arr.isEmpty());
    }

    TEST_CASE("operator[] provides access to elements") {
        dynarr arr(3);
        arr.pushBack(1.1);
        arr.pushBack(2.2);
        arr.pushBack(3.3);

        CHECK(arr[0] == doctest::Approx(1.1));
        CHECK(arr[1] == doctest::Approx(2.2));
        CHECK(arr[2] == doctest::Approx(3.3));

        arr[1] = 4.4;
        CHECK(arr[1] == doctest::Approx(4.4));

        CHECK_THROWS_AS(arr[3], std::out_of_range);
    }

    TEST_CASE("isEmpty and getSize work correctly") {
        dynarr arr;
        CHECK(arr.isEmpty());
        CHECK(arr.getSize() == 0);

        arr.pushBack(1.1);
        CHECK_FALSE(arr.isEmpty());
        CHECK(arr.getSize() == 1);
    }

    TEST_CASE("Capacity increases dynamically") {
        dynarr arr(1);
        arr.pushBack(1.1);
        CHECK(arr.getCapacity() == 1);

        arr.pushBack(2.2);
        CHECK(arr.getCapacity() == 2);

        arr.pushBack(3.3);
        CHECK(arr.getCapacity() >= 3); 
    }
}
