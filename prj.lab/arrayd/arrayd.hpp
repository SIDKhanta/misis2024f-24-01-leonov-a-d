#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <cstring>
#include <utility>

class ArrayD {
private:
    double* data_ = nullptr;
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;

public:
    ArrayD() = default;
    ArrayD(const ArrayD&);
    ArrayD(const std::ptrdiff_t size);
    ~ArrayD();

    ArrayD& operator=(const ArrayD&);

    [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
    [[nodiscard]] double& operator[](const std::ptrdiff_t idx);
    [[nodiscard]] double operator[](const std::ptrdiff_t idx) const;

    void Insert(const std::ptrdiff_t idx, const double val);
    void Remove(const std::ptrdiff_t idx);
    void Resize(const std::ptrdiff_t size);
};

#endif