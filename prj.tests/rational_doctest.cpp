#include <rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"

TEST_CASE("[ration] - ctor") {
    CHECK(ration() == ration(0, 1));         
    CHECK(ration(3) == ration(3, 1));        
    CHECK(ration(4, 2) == ration(2, 1));     
    CHECK(ration(-4, -2) == ration(2, 1));   
    CHECK(ration(-4, 2) == ration(-2, 1));   
    CHECK(ration(0, 5) == ration(0, 1));     
}

TEST_CASE("[ration] - arithmetic operations") {
    ration r1(1, 2);
    ration r2(1, 3);

    CHECK(r1 + r2 == ration(5, 6));           
    CHECK(r1 - r2 == ration(1, 6));           
    CHECK(r1 * r2 == ration(1, 6));           
    CHECK(r1 / r2 == ration(3, 2));           
}

TEST_CASE("[ration] - compound assignment operators") {
    ration r2(1, 3);

    ration r1(1, 2);   
    r1 += r2;
    CHECK(r1 == ration(5, 6));

    r1 = ration(5, 6);
    r1 -= r2;
    CHECK(r1 == ration(1, 2));

    r1 = ration(1, 2); 
    r1 *= r2;
    CHECK(r1 == ration(1, 6));

    r1 = ration(1, 2); 
    r1 /= r2;
    CHECK(r1 == ration(3, 2));
}
