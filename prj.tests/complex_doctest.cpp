#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"

TEST_CASE("[complex] - ctor") {
	CHECK(complex() == complex(0.0, 0.0));
	CHECK(complex(2.0) == complex(2.0, 0.0));
}