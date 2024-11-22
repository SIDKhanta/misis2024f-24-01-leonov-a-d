#include <arrayd/arrayd.hpp>

ArrayD::ArrayD() : data(nullptr), size(0), capacity(0) {}

ArrayD::ArrayD(ptrdiff_t initialCapacity)
    : data(new double[initialCapacity]), size(0), capacity(initialCapacity) {}

ArrayD::~ArrayD() {
    delete[] data;
}

void ArrayD::resize(ptrdiff_t newCapacity) {
    double* newData = new double[newCapacity];
    for (ptrdiff_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void ArrayD::pushBack(double value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

void ArrayD::popBack() {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }
    size--;
}

double ArrayD::get(ptrdiff_t index) const {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void ArrayD::set(ptrdiff_t index, double value) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

ptrdiff_t ArrayD::getSize() const {
    return size;
}

ptrdiff_t ArrayD::getCapacity() const {
    return capacity;
}

bool ArrayD::isEmpty() const {
    return size == 0;
}

void ArrayD::clear() {
    size = 0;
}

double& ArrayD::operator[](ptrdiff_t index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const double& ArrayD::operator[](ptrdiff_t index) const {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
