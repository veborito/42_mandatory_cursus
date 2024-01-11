#include "Contact.class.hpp"
//#include <iostream>

Contact::Contact() {
    //std::cout << "Contact object created\n";
}

Contact::~Contact() {
    //std::cout << "Contact object destroyed\n";
}

void Contact::setContact(std::string firstName, std::string lastName,
                         std::string nickName, std::string phone, 
                         std::string secret) {
    this->_firstName = firstName;
    this->_lastName = lastName;
    this->_nickName = nickName;
    this->_phone = phone;
    this->_secret = secret;
}

std::string Contact::getFirstName() const {
    return this->_firstName;
}

std::string Contact::getLastName() const {
    return this->_lastName;
}

std::string Contact::getNickName() const {
    return this->_nickName;
}

std::string Contact::getPhone() const {
    return this->_phone;
}

std::string Contact::getSecret() const {
    return this->_secret;
}
