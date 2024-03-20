#include <string>

#include "iter.hpp"

template <typename T>
T addOne(T &x) {
    return x++;
}

int main(void) {
    int intArr[5] = {1, 2, 3, 4, 5};
    char charArr[4] = {'a', 'b', 'c', 'd'};
    std::string stringArr[3] = {"Hello", "Boris", "Carmelle"};

    iter<int, void (*)(int const &)>(intArr, 5, print);
    std::cout << '\n';
    iter<char, void (*)(char const &)>(charArr, 4, print);
    std::cout << '\n';
    iter<std::string, void (*)(std::string const &)>(stringArr, 3,
                                                     print<std::string>);
    std::cout << '\n';
    iter<int, int (*)(int &)>(intArr, 5, addOne<int>);
	iter<int, void (*)(int const &)>(intArr, 5, print);
    std::cout << '\n';
    return 0;
}
