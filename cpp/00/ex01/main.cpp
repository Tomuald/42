#include "contact.class.hpp"
#include "phonebook.class.hpp"

int main(int argc, char *argv[]) {
  (void) argc;
  (void) argv;

  Phonebook phonebook;
  phonebook.loop();
  return 0;
}
