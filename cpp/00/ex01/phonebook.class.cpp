#include "phonebook.class.hpp"
#include "contact.class.hpp"

Phonebook::Phonebook(void) {
  this->num_contacts = 0;
  std::cout << "Usage: ADD, SEARCH, EXIT" << std::endl;
  return ;
}

Phonebook::~Phonebook(void) {
  return ;
}

void Phonebook::add(void) {
  if (this->num_contacts == 8)
    this->num_contacts = 0;
  std::cout << "Enter first_name" << std::endl;
  std::getline(std::cin, this->contacts[num_contacts].first_name);
  std::cout << "Enter last_name" << std::endl;
  std::getline(std::cin, this->contacts[num_contacts].last_name);
  std::cout << "Enter nickname" << std::endl;
  std::getline(std::cin, this->contacts[num_contacts].nickname);
  std::cout << "Enter phone number" << std::endl;
  std::getline(std::cin, this->contacts[num_contacts].phone_number);
  this->num_contacts++;
  return ;
}

void Phonebook::search(void) {
  int i;

  i = 0;
  std::cout << "|" << std::setfill(' ') << std::setw(10) << "Index" << "|";
  std::cout << std::setfill(' ') << std::setw(10) << "First Name" << "|";
  std::cout << std::setfill(' ') << std::setw(10) << "Last Name" << "|";
  std::cout << std::setfill(' ') << std::setw(10) << "Nickname" << "|" << std::endl;
  while (i < this->num_contacts)
  {
    std::cout << "|" << std::setfill(' ') << std::setw(10) << i << "|";
    if (this->contacts[i].first_name.size() < 10)
      std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].first_name << "|";
    else
      std::cout << std::setw(9) << this->contacts[i].first_name.substr(0, 9) << "." << "|";
    if (this->contacts[i].last_name.size() < 10)
      std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].last_name << "|";
    else
      std::cout << std::setw(9) << this->contacts[i].last_name.substr(0, 9) << "." << "|";
    if (this->contacts[i].nickname.size() < 10)
      std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].nickname << "|" << std::endl;
    else
      std::cout << std::setw(9) << this->contacts[i].nickname.substr(0, 9) << "." << "|" << std::endl;;
    i++;
  }
  return ;
}

void Phonebook::exit(void) {
  return ;
}

void Phonebook::loop(void)
{
  std::string command;

  std::cout << "Enter one of the commands above." << std::endl;
  while (true)
  {
    std::getline(std::cin, command);
    if (command == "ADD")
      this->add();
    else if (command == "SEARCH")
      this->search();
    else if (command == "EXIT")
      break ;
    else
      std::cout << "Please choose a valid option" << std::endl;
  }
  return ;
}
