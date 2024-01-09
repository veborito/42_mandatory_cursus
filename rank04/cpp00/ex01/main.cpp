#include "PhoneBook.class.hpp"
#include <iostream>

void    addToPhoneBook(PhoneBook *phoneBook) {
    std::cout << "First Name: ";
    std::string firstName;
    getline(std::cin >> std::ws, firstName);
    std::cout << "Las Name: ";
    std::string lastName;
    getline(std::cin >> std::ws, lastName);
    std::cout << "Nickname: ";
    std::string nickName;
    getline(std::cin >> std::ws, nickName);
    std::cout << "Phone Number: ";
    std::string phone;
    getline(std::cin >> std::ws, phone);
    std::cout << "Darkest secret: ";
    std::string secret;
    getline(std::cin >> std::ws, secret);
    phoneBook->addContact(firstName, lastName, nickName, phone, secret);
}

int main() {
    std::cout << "Starting program\n";
    PhoneBook   phoneBook(0);
    std::string command;
    while (true) {
        std::cout << "Entrez une commande (ADD, SEARCH, EXIT): ";
        getline(std::cin >> std::ws, command);
        if (command == "ADD")
            addToPhoneBook(&phoneBook);
        else if (command == "SEARCH")
            std::cout << "Rien pour l'instant\n";
        else if (command == "EXIT")
            break;
        else
            std::cerr << "Oops mauvaise manip !\n";
        command.clear();
    }
    Contact p = phoneBook.getContact(0);
    std::cout << p.getFirstName() << '\n';
    Contact q = phoneBook.getContact(1);
    std::cout << q.getFirstName() << '\n';

    Contact last = phoneBook.getContact(7);
    std::cout << last.getFirstName() << '\n';
    return 0;
}
