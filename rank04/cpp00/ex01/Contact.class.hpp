#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <string>

class Contact {

  public:

   String first_name;
   String last_name;
   String nick_name;
   String phone_number;
   String darkest_secret;

   Contact( String f_name, String l_name, String n_name,
       String p_num, String secret );
   ~Contact( void );
};

#endif // !CON
