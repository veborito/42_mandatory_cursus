#include "Array.hpp"

template <class T>
Array<T>::Array() {
    this->arr_size = 0;
    this->arr = new T();
}

template <class T>
Array<T>::Array(unsigned int n) : arr_size(n) {
    this->arr = new T(n);
}

template <class T>
Array<T>::~Array() {
    delete this->arr;
}

template <class T>
Array<T>::Array(Array<T> const& instance) {
    delete this->arr;
    this->arr = new T(instance.arr_size);
    for (int i = 0; i < static_cast<int>(instance.arr_size); i++) {
        this->arr = instance.arr[i];
    }
    this->arr_size = instance.size();
}
