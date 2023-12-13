#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

Contact create_contact( String name, String last_name, String nick_name, 
    String phone_number , String darkest_secret )
{
  Contact contact(name, last_name, nick_name, phone_number, darkest_secret);

  return contact;
}

int main( void )
{
  PhoneBook repertoire;
  std::string    buff;
  String    name;
  String    last_name;
  String    nick_name;
  String    phone_number;
  String    darkest_secret;

  std::cin >> buff;
  while (!buff.compare("EXIT"))
  {
    if (buff.compare("ADD"))
    {
      std::cout << "Fisrt Name: "; 
      std::cin >> name;
      std::cout << "Last Name: "; 
      std::cin >> last_name;
      std::cout << " Nickname: "; 
      std::cin >> nick_name;
      std::cout << "Phone Number: "; 
      std::cin >> phone_number;
      std::cout << "Darkest secret: "; 
      std::cin >> darkest_secret;
      repertoire.add(create_contact(name, last_name, nick_name, phone_number, darkest_secret));
    }
  }

  std::cout << "Dans la fonction main" << std::endl;
  return (0);
}

