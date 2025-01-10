#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <queuea/queuea.hpp>

TEST_CASE("Basic functionality of QueueA") {
    QueueA queue;

    CHECK(queue.IsEmpty());

    queue.Push(42);
    CHECK_FALSE(queue.IsEmpty());
    CHECK(queue.Top() == 42);

    queue.Push(99);
    CHECK(queue.Top() == 42);

    queue.Pop();
    CHECK(queue.Top() == 99);

    queue.Pop();
    CHECK(queue.IsEmpty());
}

TEST_CASE("Popping from an empty queue") {
    QueueA queue;

    CHECK_NOTHROW(queue.Pop());
}

