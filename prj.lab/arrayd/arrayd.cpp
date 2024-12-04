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

ptrdiff_t ArrayD::Size() const {
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

void ArrayD::Remove(ptrdiff_t index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (ptrdiff_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
    if (size < capacity / 4) { 
        resize(capacity / 2);
    }
}

void ArrayD::Insert(ptrdiff_t index, double value) {
    if (index < 0 || index > size) { 
        throw std::out_of_range("Index out of range");
    }
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2); 
    }
    for (ptrdiff_t i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

void ArrayD::Resize(ptrdiff_t newSize) {
    if (newSize < 0) {
        throw std::invalid_argument("New size must be non-negative");
    }
    if (newSize > capacity) {
        resize(newSize); 
    }
    if (newSize < size) {
        size = newSize; 
    }
    else {
        for (ptrdiff_t i = size; i < newSize; ++i) {
            data[i] = 0.0; 
        }
        size = newSize;
    }
}

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
    if (this != &rhs) {
        Resize(rhs.size_);
        std::memcpy(data_, rhs.data_, size_ * sizeof(*data_));
    }
    return *this;
}