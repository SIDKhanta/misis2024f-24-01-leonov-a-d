#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstddef> 
#include <memory>

template<class T>
class ArrayT {
private:
    std::unique_ptr<T[]> data_;
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;

    void resize(ptrdiff_t newCapacity);

public:
    ArrayT();
    explicit ArrayT(ptrdiff_t initialCapacity);
    ~ArrayT();

    ArrayT& operator=(const ArrayT&);

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

template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& src) : data_.reset(new T[capacity_]{ T() }), capacity_(scr.size_), size_(capacity_) {}

template<class T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size)
    : capacity_(size)
    , size_(size) {
    if (size_ <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_.reset(new T[size]{ T() });
}

template<class T>
ArrayT<T>::~ArrayT() {
    delete[] data_;
}

template<class T>
void ArrayT<T>::resize(ptrdiff_t newcapacity_) {
    double* newdata_ = new double[newcapacity_];
    for (ptrdiff_t i = 0; i < size_; i++) {
        newdata_[i] = data_[i];
    }
    delete[] data_;
    data_ = newdata_;
    capacity_ = newcapacity_;
}

void ArrayT::pushBack(double value) {
    if (size_ == capacity_) {
        resize(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
}

void ArrayT::popBack() {
    if (size_ == 0) {
        throw std::out_of_range("Array is empty");
    }
    size_--;
}

double ArrayT::get(ptrdiff_t index) const {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

void ArrayT::set(ptrdiff_t index, double value) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    data_[index] = value;
}

ptrdiff_t ArrayT::Size() const {
    return size_;
}

ptrdiff_t ArrayT::getCapacity() const {
    return capacity_;
}

bool ArrayT::isEmpty() const {
    return size_ == 0;
}

void ArrayT::clear() {
    size_ = 0;
}

double& ArrayT::operator[](ptrdiff_t index) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

const double& ArrayT::operator[](ptrdiff_t index) const {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

void ArrayT::Remove(ptrdiff_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    for (ptrdiff_t i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }
    size_--;
    if (size_ < capacity_ / 4) {
        resize(capacity_ / 2);
    }
}

void ArrayT::Insert(ptrdiff_t index, double value) {
    if (index < 0 || index > size_) {
        throw std::out_of_range("Index out of range");
    }
    if (size_ == capacity_) {
        resize(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    for (ptrdiff_t i = size_; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    data_[index] = value;
    size_++;
}

void ArrayT::Resize(ptrdiff_t newsize_) {
    if (newsize_ < 0) {
        throw std::invalid_argument("New size_ must be non-negative");
    }
    if (newsize_ > capacity_) {
        resize(newsize_);
    }
    if (newsize_ < size_) {
        size_ = newsize_;
    }
    else {
        for (ptrdiff_t i = size_; i < newsize_; ++i) {
            data_[i] = 0.0;
        }
        size_ = newsize_;
    }
}

ArrayT& ArrayT::operator=(const ArrayT& rhs) {
    if (this != &rhs) {
        Resize(rhs.size_);
        std::memcpy(data_, rhs.data_, size_ * sizeof(*data_));
    }
    return *this;
}
#endif