#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void formatString(std::string s) {
    if (s.length() > 10) {
        std::cout << s.substr(0, 9) + '.';
        return;
    }
    std::cout << std::left << std::setw(10) << s;
}

bool isNum(std::string s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

bool processInput(PhoneBook p) {

    std::string input;
    std::cout << '\n' << "Choisi le contact en specifiant un index (0, 1,...)";
    std::getline(std::cin, input);
    if (isNum(input)) {
        int index; 
        index = std::stoi(input);
        std::cout << p.getContact(index).getFirstName() << " | "
                  <<  p.getContact(index).getLastName() << " | "
                  << p.getContact(index).getNickName() << " | "
                  << p.getContact(index).getPhone() << " | "
                  << p.getContact(index).getSecret() << '\n';
        return false;
    }
    std::cout << "This index is not valid\n";
    return true;
}

void search(PhoneBook p) {
    int nbContacts = p.getNbContacts();
    for (int i = 0; i < nbContacts; i++) {
        std::cout << "[" << i << "] ";
        formatString(p.getContact(i).getFirstName());
        std::cout << " | ";
        formatString(p.getContact(i).getLastName());
        std::cout << " | ";
        formatString(p.getContact(i).getNickName());
        std::cout << " | ";
        formatString(p.getContact(i).getPhone());
        std::cout << " | ";
        formatString(p.getContact(i).getSecret());
        std::cout << '\n';
    }
    int access = true;
    while (access) {
        access = processInput(p);
    }
}

bool processCommand(PhoneBook *phoneBook) {
    std::cout << "Entrez une commande (ADD, SEARCH, EXIT): ";
    std::string command;
    std::getline(std::cin, command);
    if (command == "ADD")
        phoneBook->add();
    else if (command == "SEARCH")
            search(*phoneBook);
    else if (command == "EXIT")
        return (false);
    else
        std::cerr << "Oops mauvaise manip !\n";
    return (true);
}


int main() {
    std::cout << "Starting program\n";
    PhoneBook   phoneBook(0);
    bool        access = true; 
    while (access)
        access = processCommand(&phoneBook);
    Contact p = phoneBook.getContact(0);
    std::cout << p.getFirstName() << '\n';
    Contact q = phoneBook.getContact(1);
    std::cout << q.getFirstName() << '\n';
    Contact last = phoneBook.getContact(7);
    std::cout << last.getFirstName() << '\n';
    return 0;
}
