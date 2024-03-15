#include "Array.hpp"
#include <exception>
#include <iostream>

template <typename T>
Array<T>::Array() : arr(nullptr), arr_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), arr_size(n) {
	for (int i = 0; i < static_cast<int>(n); i++)
		arr[i] = 0;
}

template <typename T>
Array<T>::~Array() {
    delete[] this->arr;
}

template <typename T>
Array<T>::Array(Array<T> const& instance) {
    this->arr = new T[instance.arr_size];
    this->arr_size = instance.size();
	for (int i = 0; i < static_cast<int>(instance.arr_size); i++) {
        (*this)[i] = instance[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs) {
	if (this != &rhs) {
		if (this->arr)
			delete[] this->arr;
		this->arr = new T[rhs.arr_size];
		this->arr_size = rhs.size();
		for (int i = 0; i < static_cast<int>(rhs.arr_size); i++) {
			(*this)[i] = rhs[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](int idx) {
	if (!this->arr)
		throw Array<T>::NullArrayException();
    if (idx < 0 || idx >= static_cast<int>(arr_size))
        throw Array<T>::IndexOutOfRangeException();
    return arr[idx];
}

template <typename T>
T const &Array<T>::operator[](int idx) const {
	if (!this->arr)
		throw Array<T>::NullArrayException();
	if (idx < 0 || idx >= static_cast<int>(arr_size))
        throw Array<T>::IndexOutOfRangeException();
    return this->arr[idx];
}

template <typename T>
unsigned int Array<T>::size() const { return this->arr_size; }

template <typename T>
char const *Array<T>::IndexOutOfRangeException::what() const throw() {
	return "Index out of range";
}

template <typename T>
char const *Array<T>::NullArrayException::what() const throw() {
	return "Can't access Array because it's a nullptr";
}
