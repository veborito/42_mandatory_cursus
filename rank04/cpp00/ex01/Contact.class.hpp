#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H
#include <string>

class Contact {
public:
    Contact();
    ~Contact();

    void setContact(std::string firstName,std::string lastName,
                 std::string nickName, std::string phone, std::string secret);
    std::string getFirstName() const;
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phone;
    std::string _secret;
};

#endif
