#include "dynarr.hpp"

dynarr::dynarr() : data(nullptr), size(0), capacity(0) {}

dynarr::dynarr(size_t initialCapacity)
    : data(new int[initialCapacity]), size(0), capacity(initialCapacity) {}

dynarr::~dynarr() {
    delete[] data;
}

void dynarr::resize(size_t newCapacity) {
    int* newData = new int[newCapacity];
    for (size_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void dynarr::pushBack(int value) {
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

int dynarr::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void dynarr::set(size_t index, int value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

size_t dynarr::getSize() const {
    return size;
}

size_t dynarr::getCapacity() const {
    return capacity;
}

bool dynarr::isEmpty() const {
    return size == 0;
}

void dynarr::clear() {
    size = 0;
}

int& dynarr::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int& dynarr::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
