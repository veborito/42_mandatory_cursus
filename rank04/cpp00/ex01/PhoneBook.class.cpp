#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook( void ) {

  std::cout << "Constructor called" << std::endl;
  this->index = 0;
  return;
}

PhoneBook::~PhoneBook( void ) {
  std::cout << "Destructor called" << std::endl; 
  return;
}

PhoneBook::add( Contact contact ) {

  if (this->index == 7)
  {
    std::cout << "Le répértoire est complet: "<< std::endl 
      << this->contacts[7].name << std::endl << "remplacé par :"
      << std::endl << contact.name << std::endl;
    this->contacts[this->index] = contact;
    return;
  }
  this->contacts[this->index] = contact;
  this->index += 1;
  std::cout << "Contact added" << std::endl;
  return;
}
