#include "arrayd.hpp"

dynarr::dynarr() : data(nullptr), size(0), capacity(0) {}

dynarr::dynarr(ptrdiff_t initialCapacity)
    : data(new double[initialCapacity]), size(0), capacity(initialCapacity) {}

dynarr::~dynarr() {
    delete[] data;
}

void dynarr::resize(ptrdiff_t newCapacity) {
    double* newData = new double[newCapacity];
    for (ptrdiff_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void dynarr::pushBack(double value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

void dynarr::popBack() {
    if (size == 0) {
        throw std::out_of_range("Array is empty");
    }
    size--;
}

double dynarr::get(ptrdiff_t index) const {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void dynarr::set(ptrdiff_t index, double value) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

ptrdiff_t dynarr::getSize() const {
    return size;
}

ptrdiff_t dynarr::getCapacity() const {
    return capacity;
}

bool dynarr::isEmpty() const {
    return size == 0;
}

void dynarr::clear() {
    size = 0;
}

double& dynarr::operator[](ptrdiff_t index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const double& dynarr::operator[](ptrdiff_t index) const {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
