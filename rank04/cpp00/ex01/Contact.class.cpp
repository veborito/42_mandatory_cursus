#include "Contact.class.hpp"

Contact::Contact( String f_name, String l_name, String n_name, String p_num, String secret ) : 
  first_name(f_name),
  last_name(l_name),
  nick_name(n_name),
  phone_number(p_num),
  darkest_secret(secret) {

  std::cout << "Contact init" << std::endl;
  std::cout << "Fist Name: " << this->first_name << std::endl;
  std::cout << "Last Name: " << this->last_name << std::endl;
  std::cout << "Nickname: "<< this->nick_name << std::endl;
  std::cout << "Phone number: "<< this->phone_number << std::endl;
  std::cout << "Darkest Secret: "<< this->darkest_secret << std::endl;
  return;
}

Contact::~Contact( void ) {

  std::cout << "Contact lost" << std::endl;
  return;
}

