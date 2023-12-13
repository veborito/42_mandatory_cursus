#include "Contact.class.hpp"
#include <iostream>

Contact::Contact( void ) {
  std::cout << "Contact init" << std::endl;
  return;
}

Contact::~Contact( void ) {

  std::cout << "Contact lost" << std::endl;
  return;
}

