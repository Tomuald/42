#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "contact.class.hpp"

class Phonebook {
public:
  Phonebook(void);
  ~Phonebook(void);

  void add(void);
  void search(void);
  void exit(void);
  void loop(void);

  int num_contacts;

private:
  Contact contacts[8];
};

#endif
