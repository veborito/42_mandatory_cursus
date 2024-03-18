#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T >
typename T::iterator easyfind(T &container, int number) {
    typename T::iterator it = std::find(container.begin(), container.end(), number);
    if (it == container.end())
        throw std::out_of_range("Object not found");
    return it;
}

#endif
