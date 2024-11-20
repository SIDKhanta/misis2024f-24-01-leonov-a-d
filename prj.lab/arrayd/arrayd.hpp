#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstddef> // Äëÿ ptrdiff_t

class dynarr {
private:
    double* data;
    ptrdiff_t size;
    ptrdiff_t capacity;

    void resize(ptrdiff_t newCapacity);

public:
    dynarr();
    explicit dynarr(ptrdiff_t initialCapacity);
    ~dynarr();

    void pushBack(double value);
    void popBack();
    double get(ptrdiff_t index) const;
    void set(ptrdiff_t index, double value);
    ptrdiff_t getSize() const;
    ptrdiff_t getCapacity() const;
    bool isEmpty() const;
    void clear();

    double& operator[](ptrdiff_t index);
    const double& operator[](ptrdiff_t index) const;
};

#endif
