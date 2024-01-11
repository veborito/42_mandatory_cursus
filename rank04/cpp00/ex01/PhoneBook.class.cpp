#include "PhoneBook.class.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() {
    this->_nbContacts = 0;
    //std::cout << "PhoneBook object created\n";
    //std::cout << this->_nbContacts << '\n';
}

PhoneBook::~PhoneBook() {
    //std::cout << "PhoneBook object destroyed\n";
}

void PhoneBook::_addContact(std::string firstName,std::string lastName,
                           std::string nickName, std::string phone,
                           std::string secret) {
    int index = this->_nbContacts;
    if (index >= 7) {
        this->_contacts[7].setContact(firstName, lastName, nickName, phone,
                                          secret);
        this->_nbContacts = 8;
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

bool PhoneBook::_processInput() const {

    std::string input;
    std::cout << '\n' << "Choisi le contact en specifiant un index (0, 1,...): ";
    std::getline(std::cin, input);
    if (isNum(input)) {
        int index; 
        index = std::stoi(input);
        if (index >= this->_nbContacts or index < 0){
            std::cout << "Cet index n'est pas valid !\n";
            return true;
        }
        std::cout 
            << "First Name: "<< this->getContact(index).getFirstName() << "\n"
            << "Last Name: "<<  this->getContact(index).getLastName() << "\n"
            << "Nick Name: "<< this->getContact(index).getNickName() << "\n"
            << "Phone Number: "<< this->getContact(index).getPhone() << "\n"
            << "Darkest Secret: "<< this->getContact(index).getSecret() << '\n';
        return false;
    }
    std::cout << "Cet index n'est pas valid !\n";
    return true;
}

void PhoneBook::search() const {
    if (this->_nbContacts == 0) {
        std::cout << "Pas de contacts dans le repertoire ! Ajoutez-en :)\n";
        return;
    }
    for (int i = 0; i < this->_nbContacts; i++) {
        std::cout << std::setw(10) << i << " | ";
        formatString(this->getContact(i).getFirstName());
        std::cout << " | ";
        formatString(this->getContact(i).getLastName());
        std::cout << " | ";
        formatString(this->getContact(i).getNickName());
        std::cout << '\n';
    }
    int access = true;
    while (access) {
        access = this->_processInput();
    }
}
