#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"
#include <string>

class PhoneBook {
public:
    PhoneBook(int nb);
    ~PhoneBook();

    Contact     getContact(int index) const;
    int         getNbContacts() const;
    void        add();
private:
    Contact     _contacts[8];
    int         _nbContacts;

    std::string _fillContactInfo() const;
    void        _addContact(std::string firstName,std::string lastName,
                            std::string nickName, std::string phone,
                            std::string secret);

};

#endif
