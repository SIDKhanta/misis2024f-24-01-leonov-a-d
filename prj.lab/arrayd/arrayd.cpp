#include <arrayd/arrayd.hpp>

ArrayD::ArrayD(const ArrayD& src)
    : capacity_(src.size_), size_(src.size_), data_(nullptr) {
    if (size_ > 0) {
        data_ = new double[size_];
        std::memcpy(data_, src.data_, size_ * sizeof(*data_));
    }
}

ArrayD::ArrayD(const std::ptrdiff_t size)
    : capacity_(size), size_(size) {
    if (size <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_ = new double[capacity_]();
}

ArrayD::~ArrayD() {
    delete[] data_;
}

ArrayD& ArrayD::operator=(const ArrayD& rhs) {
    if (this != &rhs) {
        ArrayD temp(rhs);
        std::swap(data_, temp.data_);
        capacity_ = temp.capacity_;
        size_ = temp.size_;
    }
    return *this;
}

double ArrayD::operator[](const std::ptrdiff_t idx) const {
    if (idx < 0 || idx >= size_) {
        throw std::out_of_range("ArrayD::operator[] - index out of range");
    }
    return data_[idx];
}

double& ArrayD::operator[](const std::ptrdiff_t idx) {
    if (idx < 0 || idx >= size_) {
        throw std::out_of_range("ArrayD::operator[] - index out of range");
    }
    return data_[idx];
}

void ArrayD::Resize(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("ArrayD::Resize - non positive size");
    }

    if (size > capacity_) {
        double* new_data = new double[size]();
        if (data_) {
            std::memcpy(new_data, data_, size_ * sizeof(double));
            delete[] data_;
        }
        data_ = new_data;
        capacity_ = size;
    }
    else if (size < size_) {

    }
    else if (size > size_) {
        std::memset(data_ + size_, 0, (size - size_) * sizeof(double));
    }

    size_ = size;
}

void ArrayD::Remove(const std::ptrdiff_t idx) {
    if (idx < 0 || idx >= size_) {
        throw std::out_of_range("ArrayD::Remove - index out of range");
    }

    if (idx != size_ - 1) {
        std::memmove(data_ + idx, data_ + idx + 1, (size_ - idx - 1) * sizeof(double));
    }

    Resize(size_ - 1);
}

void ArrayD::Insert(const std::ptrdiff_t idx, const double val) {
    if (idx < 0 || idx > size_) {
        throw std::out_of_range("ArrayD::Insert - index out of range");
    }

    Resize(size_ + 1);

    if (idx != size_ - 1) {
        std::memmove(data_ + idx + 1, data_ + idx, (size_ - idx - 1) * sizeof(double));
    }

    data_[idx] = val;
}