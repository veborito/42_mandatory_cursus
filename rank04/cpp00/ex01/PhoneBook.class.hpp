#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"
#include <string>

class PhoneBook {
public:
    PhoneBook(int nb);
    ~PhoneBook();

    void    addContact(std::string firstName,std::string lastName,
                       std::string nickName, std::string phone,
                       std::string secret);
    Contact getContact(int index) const;
private:
    Contact _contacts[8];
    int     _nbContacts;
};

#endif
