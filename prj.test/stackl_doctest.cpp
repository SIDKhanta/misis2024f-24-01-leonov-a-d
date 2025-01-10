#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <stackl/stackl.hpp>

TEST_CASE("Testing StackL ") {
    StackL stack;

    CHECK(stack.IsEmpty());

    stack.Push(42);

    CHECK_FALSE(stack.IsEmpty());
    CHECK(stack.Top() == 42);

    stack.Push(99);

    CHECK(stack.Top() == 99);

    stack.Pop();

    CHECK(stack.Top() == 42);

    stack.Pop();

    CHECK(stack.IsEmpty());
}

TEST_CASE("Testing Pop on empty stack") {
    StackL stack;

    CHECK_NOTHROW(stack.Pop());
}

