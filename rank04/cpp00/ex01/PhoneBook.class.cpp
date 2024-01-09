#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    std::cout << "PhoneBook object created\n";
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook object destroyed\n";
}

void PhoneBook::bar() {
    std::cout << "completement barjo ce code\n";
}
