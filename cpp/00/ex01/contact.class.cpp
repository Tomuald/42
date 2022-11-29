#include "contact.class.hpp"

Contact::Contact(void) {
  return ;
}

Contact::~Contact(void) {
  return ;
}

std::string Contact::getFirstName(void) {
  return (this->first_name);
}

std::string Contact::getLastName(void) {
  return (this->last_name);
}

std::string Contact::getNickname(void) {
  return (this->nickname);
}

std::string Contact::getNumber(void) {
  return (this->phone_number);
}

std::string Contact::getSecret(void) {
  return (this->secret);
}

void Contact::setFirstName(std::string _input) {
  this->first_name = _input;
}
void Contact::setLastName(std::string _input) {
  this->last_name = _input;
}

void Contact::setNickname(std::string _input) {
  this->nickname = _input;
}

void Contact::setNumber(std::string _input) {
  this->phone_number = _input;
}
void Contact::setSecret(std::string _input) {
  this->secret = _input;
}
