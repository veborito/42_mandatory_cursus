#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <stdexcept>
#include <iostream>

template <typename T>
Array<T>::Array() {
    this->arr_size = 0;
    this->arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), arr_size(n) {}

template <typename T>
Array<T>::~Array() {
    delete[] this->arr;
}

template <typename T>
Array<T>::Array(Array<T> const& instance) {
    this->arr = new T(instance.arr_size);
    for (int i = 0; i < static_cast<int>(instance.arr_size); i++) {
        this->arr[i] = instance.arr[i];
    }
    this->arr_size = instance.size();
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs) {
	delete[] this->arr;
	this->arr = new T(rhs.arr_size);
    for (int i = 0; i < static_cast<int>(rhs.arr_size); i++) {
        this->arr[i] = rhs.arr[i];
    }
    this->arr_size = rhs.size();
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int idx) {
    if (idx >= arr_size)
        throw std::out_of_range("index");
    return this->arr[idx];
}

template <typename T>
unsigned int Array<T>::size() const { return this->arr_size; }

#endif