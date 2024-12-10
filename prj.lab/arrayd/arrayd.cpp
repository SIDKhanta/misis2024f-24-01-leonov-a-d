#include <arrayd/arrayd.hpp>

ArrayD::ArrayD() : data_(nullptr), size_(0), capacity_(0) {}

ArrayD::ArrayD(ptrdiff_t initialcapacity_)
    : data_(new double[initialcapacity_]), size_(0), capacity_(initialcapacity_) {}

ArrayD::~ArrayD() {
    delete[] data_;
}

void ArrayD::resize(ptrdiff_t newcapacity_) {
    double* newdata_ = new double[newcapacity_];
    for (ptrdiff_t i = 0; i < size_; i++) {
        newdata_[i] = data_[i];
    }
    delete[] data_;
    data_ = newdata_;
    capacity_ = newcapacity_;
}

void ArrayD::pushBack(double value) {
    if (size_ == capacity_) {
        resize(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
}

void ArrayD::popBack() {
    if (size_ == 0) {
        throw std::out_of_range("Array is empty");
    }
    size_--;
}

double ArrayD::get(ptrdiff_t index) const {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

void ArrayD::set(ptrdiff_t index, double value) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    data_[index] = value;
}

ptrdiff_t ArrayD::Size() const {
    return size_;
}

ptrdiff_t ArrayD::getCapacity() const {
    return capacity_;
}

bool ArrayD::isEmpty() const {
    return size_ == 0;
}

void ArrayD::clear() {
    size_ = 0;
}

double& ArrayD::operator[](ptrdiff_t index) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

const double& ArrayD::operator[](ptrdiff_t index) const {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

void ArrayD::Remove(ptrdiff_t index) {
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

void ArrayD::Insert(ptrdiff_t index, double value) {
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

void ArrayD::Resize(ptrdiff_t newsize_) {
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

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
    if (this != &rhs) {
        Resize(rhs.size_);
        std::memcpy(data_, rhs.data_, size_ * sizeof(*data_));
    }
    return *this;
}