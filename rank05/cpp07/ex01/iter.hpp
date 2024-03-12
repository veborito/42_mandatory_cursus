#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T const &x) {
    std::cout << x << ' ';
}

template <typename T, typename Func>
void iter(T *arr, size_t len, Func fun) {
    for (int i = 0; i < static_cast<int>(len); i++) {
        fun(arr[i]);
    }
}

#endif
