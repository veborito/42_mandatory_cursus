#include <iostream>
#include <ostream>
#include <string>
#include "PhoneBook.class.hpp"

Contact create_contact( std::string name, std::string last_name, std::string nick_name, 
    std::string phone_number , std::string darkest_secret )
{
  Contact contact;

  contact.first_name = name;
  contact.last_name = last_name;
  contact.phone_number = phone_number;
  contact.nick_name = nick_name;
  contact.darkest_secret = darkest_secret;
  return contact;
}

int main( void )
{
  Contact     contacts[8];  
  PhoneBook   repertoire(contacts);
  std::string buff;
  std::string name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;

  while (buff.compare("EXIT") != 0)
  {
    std::cout << "type a command : ";
    std::getline(std::cin, buff); 
    if (buff.compare("ADD") == 0)
    {
      std::cout << "Fisrt Name: "; 
      std::getline(std::cin, name);
      std::cout << "Last Name: "; 
      std::getline(std::cin, last_name);
      std::cout << " Nickname: "; 
      std::getline(std::cin, nick_name);
      std::cout << "Phone Number: "; 
      std::getline(std::cin, phone_number);
      std::cout << "Darkest secret: "; 
      std::getline(std::cin, darkest_secret);
      repertoire.add(create_contact(name, last_name, nick_name, phone_number, darkest_secret));
      std::cout << "Premier contact " << repertoire.contacts[0].first_name << std::endl;
    }
  }
  return (0);
}

