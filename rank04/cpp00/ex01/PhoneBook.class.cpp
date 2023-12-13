#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook( Contact *rep_contacts ) : contacts(rep_contacts) {

  std::cout << "Constructor called" << std::endl;
  this->index = 0;
  return;
}

PhoneBook::~PhoneBook( void ) {
  std::cout << "Destructor called" << std::endl; 
  return;
}

void PhoneBook::add( Contact contact ) {

  if (this->index == 7)
  {
    std::cout << "Le répértoire est complet: "<< std::endl 
      << this->contacts[7].first_name << std::endl << "remplacé par :"
      << std::endl << contact.first_name << std::endl;
    this->contacts[this->index] = contact;
    return;
  }
  this->contacts[this->index] = contact;
  this->index += 1;
  std::cout << "Contact added" << std::endl;
  return;
}
