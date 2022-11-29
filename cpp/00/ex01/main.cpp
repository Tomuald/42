#include "contact.class.hpp"
#include "phonebook.class.hpp"

int main(int argc, char *argv[]) {
  (void) argv;
  if (argc != 1) {
    std::cout << "Usage: ./phonebook" << std::endl;
    return (-1);
  }
  Phonebook phonebook;
  phonebook.loop();
  return (0);
}
