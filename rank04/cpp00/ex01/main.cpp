#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>

bool processCommand(PhoneBook *phoneBook) {
    std::cout << "Entrez une commande (ADD, SEARCH, EXIT): ";
    std::string command;
    std::getline(std::cin, command);
    if (command == "ADD")
        phoneBook->add();
    else if (command == "SEARCH")
        phoneBook->search();
    else if (command == "EXIT")
        return (false);
    else
        std::cerr << "Oops mauvaise manip !\n";
    return (true);
}

int main() {
    std::cout << "Starting program\n";
    PhoneBook   phoneBook;
    bool        access = true; 
    while (access)
        access = processCommand(&phoneBook);
    return 0;
}
