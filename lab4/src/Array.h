#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <memory>

template <typename T>
class Array {
public:
    Array(size_t size = 0);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;
    void resize(size_t newSize);

    void push_back(const T& value);
    void pop_back();

    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;

private:
    std::shared_ptr<T[]> data;
    size_t arraySize;
};

template <typename T>
Array<T>::Array(size_t size) : arraySize(size) {
    data = size ? std::make_shared<T[]>(size) : nullptr;
}

template <typename T>
Array<T>::Array(const Array& other) : arraySize(other.arraySize) {
    data = arraySize ? std::make_shared<T[]>(arraySize) : nullptr;
    for (size_t i = 0; i < arraySize; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>::Array(Array&& other) noexcept : data(std::move(other.data)), arraySize(other.arraySize) {
    other.arraySize = 0;
}

template <typename T>
Array<T>::~Array() {
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        data = arraySize ? std::make_shared<T[]>(arraySize) : nullptr;
        arraySize = other.arraySize;
        for (size_t i = 0; i < arraySize; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        arraySize = other.arraySize;
        other.arraySize = 0;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= arraySize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= arraySize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t Array<T>::size() const {
    return arraySize;
}

template <typename T>
void Array<T>::resize(size_t newSize) {
    std::shared_ptr<T[]> newData = newSize ? std::make_shared<T[]>(newSize) : nullptr;
    size_t copySize = std::min(arraySize, newSize);
    for (size_t i = 0; i < copySize; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
    arraySize = newSize;
}

template <typename T>
void Array<T>::push_back(const T& value) {
    resize(arraySize + 1);
    data[arraySize - 1] = value;
}

template <typename T>
void Array<T>::pop_back() {
    if (arraySize > 0) {
        resize(arraySize - 1);
    }
}

template <typename T>
bool Array<T>::operator==(const Array& other) const {
    if (arraySize != other.arraySize) {
        return false;
    }
    for (size_t i = 0; i < arraySize; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Array<T>::operator!=(const Array& other) const {
    return !(*this == other);
}

#endif 
