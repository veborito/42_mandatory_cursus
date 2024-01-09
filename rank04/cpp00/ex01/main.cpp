#include "PhoneBook.class.hpp"
#include <iostream>

int main() {
    std::cout << "Starting program\n";
    PhoneBook phoneBook;
    phoneBook.foo = 42;
    std::cout << "phoneBook.foo: " << phoneBook.foo << '\n';
    phoneBook.bar();
    return 0;
}
