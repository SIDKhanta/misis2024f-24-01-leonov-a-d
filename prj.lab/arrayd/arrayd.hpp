#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstddef> 

class ArrayD {
private:
    double* data_ = 0;
    ptrdiff_t size_ = 0;
    ptrdiff_t capacity_ = 0;

    void resize(ptrdiff_t newCapacity);

public:
    ArrayD();
    explicit ArrayD(ptrdiff_t initialCapacity);
    ~ArrayD();

    ArrayD& operator=(const ArrayD&);

    void pushBack(double value);
    void popBack();
    double get(ptrdiff_t index) const;
    void set(ptrdiff_t index, double value);
    ptrdiff_t Size() const;
    ptrdiff_t getCapacity() const;
    bool isEmpty() const;
    void clear();

    double& operator[](ptrdiff_t index);
    const double& operator[](ptrdiff_t index) const;

    void Remove(ptrdiff_t index);
    void Insert(ptrdiff_t index, double value);
    void Resize(ptrdiff_t newSize);
};

#endif