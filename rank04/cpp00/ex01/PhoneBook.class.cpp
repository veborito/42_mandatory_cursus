#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(int nb) : _nbContacts(nb) {
    std::cout << "PhoneBook object created\n";
    std::cout << this->_nbContacts << '\n';
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook object destroyed\n";
}

void PhoneBook::addContact(std::string firstName,std::string lastName,
                           std::string nickName, std::string phone,
                           std::string secret) {
    int index = this->_nbContacts;
    if (index == 7) {
        this->_contacts[index].setContact(firstName, lastName, nickName, phone,
                                          secret);
        return;
    }
    this->_contacts[index].setContact(firstName, lastName, nickName, phone,
                                      secret);
    this->_nbContacts++;
}

Contact PhoneBook::getContact(int index) const {
    return  this->_contacts[index];
}
