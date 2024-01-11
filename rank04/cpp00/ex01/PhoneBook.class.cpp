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

void PhoneBook::_addContact(std::string firstName,std::string lastName,
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

int PhoneBook::getNbContacts () const {
    return this->_nbContacts;
}

std::string PhoneBook::_fillContactInfo() const {
    std::string information;
    getline(std::cin, information);
    while (information.empty()) {
        std::cout << "Les champs vide ne sont pas valides !\n"
                  << "essayez encore : ";
        getline(std::cin, information);
    }
    return information;
}

void PhoneBook::add() {
    std::cout << "First Name: ";
    std::string firstName = this->_fillContactInfo();
    std::cout << "Last Name: ";
    std::string lastName =this->_fillContactInfo();
    std::cout << "Nickname: ";
    std::string nickName =this->_fillContactInfo();
    std::cout << "Phone Number: ";
    std::string phone =this->_fillContactInfo();
    std::cout << "Darkest secret: ";
    std::string secret =this->_fillContactInfo();
    this->_addContact(firstName, lastName, nickName, phone, secret);
}
