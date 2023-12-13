#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

class PhoneBook {

  public: 
   
    Contact contacts[8];
    int     index;

    PhoneBook( void );
    ~PhoneBook( void );

    void  add( Contact contact );
};

#endif

