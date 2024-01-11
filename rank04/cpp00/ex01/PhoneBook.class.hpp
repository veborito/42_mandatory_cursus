#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"
#include <string>

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

    Contact     getContact(int index) const; // pour debug
    int         getNbContacts() const; // nombre de contact dans le repo !
    void        add();
    void        search() const;
private:
    Contact     _contacts[8];
    int         _nbContacts;

    std::string _fillContactInfo() const;
    void        _addContact(std::string firstName,std::string lastName,
                            std::string nickName, std::string phone,
                            std::string secret);

    bool        _processInput() const;
};

#endif
