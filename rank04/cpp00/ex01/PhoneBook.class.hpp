#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

class PhoneBook {

  public: 
   
    Contact *contacts;
    int     index;

    PhoneBook( Contact *rep_contacts );
    ~PhoneBook( void );

    void  add( Contact contact );
};

#endif

