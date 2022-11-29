#include "phonebook.class.hpp"
#include "contact.class.hpp"

#include <sstream>

Phonebook::Phonebook(void) {
  this->num_contacts = 0;
  std::cout << "Usage: ADD, SEARCH, EXIT" << std::endl;
  return ;
}

Phonebook::~Phonebook(void) {
  return ;
}

void Phonebook::add(void) {
  std::string _input;
  if (this->num_contacts == 8)
    this->num_contacts = 0;
  while (_input.empty()) {
    std::cout << "Enter first_name" << std::endl;
    std::getline(std::cin, _input);
    this->contacts[num_contacts].setFirstName(_input);
  }
  _input.clear();
  while (_input.empty()) {
    std::cout << "Enter last_name" << std::endl;
    std::getline(std::cin, _input);
    this->contacts[num_contacts].setLastName(_input);
  }
  _input.clear();
  while (_input.empty()) {
    std::cout << "Enter nickname" << std::endl;
    std::getline(std::cin, _input);
    this->contacts[num_contacts].setNickname(_input);
  }
  _input.clear();
  while (_input.empty()) {
    std::cout << "Enter phone number" << std::endl;
    std::getline(std::cin, _input);
    this->contacts[num_contacts].setNumber(_input);
  }
  _input.clear();
  while (_input.empty()) {
    std::cout << "Enter secret" << std::endl;
    std::getline(std::cin, _input);
    this->contacts[num_contacts].setSecret(_input);
  }
  _input.clear();
  std::cout << "Contact added." << std::endl;
  std::cout << "Use: ADD, SEARCH, or EXIT" << std::endl;
  this->num_contacts++;
  return ;
}

void Phonebook::search(void) {
  int i;
  std::string index;
  int _index;

  i = 0;
  if (this->num_contacts == 0) {
    std::cout << "Empty Phonebook. Choose another option." << std::endl;
    return ;
  }
  std::cout << "|" << std::setfill(' ') << std::setw(10) << "Index" << "|";
  std::cout << std::setfill(' ') << std::setw(10) << "First Name" << "|";
  std::cout << std::setfill(' ') << std::setw(10) << "Last Name" << "|";
  std::cout << std::setfill(' ') << std::setw(10) << "Nickname" << "|" << std::endl;
  while (i < 8)
  {
    std::cout << "|" << std::setfill(' ') << std::setw(10) << i << "|";
    if (this->contacts[i].getFirstName().size() < 10)
      std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].getFirstName() << "|";
    else
      std::cout << std::setw(9) << this->contacts[i].getFirstName().substr(0, 9) << "." << "|";
    if (this->contacts[i].getLastName().size() < 10)
      std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].getLastName() << "|";
    else
      std::cout << std::setw(9) << this->contacts[i].getLastName().substr(0, 9) << "." << "|";
    if (this->contacts[i].getNickname().size() < 10)
      std::cout << std::setfill(' ') << std::setw(10) << this->contacts[i].getNickname() << "|" << std::endl;
    else
      std::cout << std::setw(9) << this->contacts[i].getNickname().substr(0, 9) << "." << "|" << std::endl;;
    i++;
  }
  std::cout << "Which index would you like to see?" << std::endl;
  while (1) {
    std::getline(std::cin, index);
    if ((std::istringstream(index) >> _index).fail() || (_index < 0 || _index > 7))
      std::cerr << "Invalid Input. Choose between 0-7" << std::endl;
    else {
      std::cout << "First Name: " << this->contacts[_index].getFirstName() << std::endl;
      std::cout << "Last Name: " << this->contacts[_index].getLastName() << std::endl;
      std::cout << "Nickname: " << this->contacts[_index].getNickname() << std::endl;
      std::cout << "Phone Number: " << this->contacts[_index].getNumber() << std::endl;
      std::cout << "Secret: " << this->contacts[_index].getSecret() << std::endl;
      std::cout << "Use: ADD, SEARCH, or EXIT" << std::endl;
      break ;
    }
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
