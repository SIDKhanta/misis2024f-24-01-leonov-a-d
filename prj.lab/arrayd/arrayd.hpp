#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstddef> // Äëÿ ptrdiff_t

class ArrayD {
private:
    double* data = 0;
    ptrdiff_t size = 0;
    ptrdiff_t capacity = 0;

    void resize(ptrdiff_t newCapacity);

public:
    ArrayD();
    explicit ArrayD(ptrdiff_t initialCapacity);
    ~ArrayD();

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
