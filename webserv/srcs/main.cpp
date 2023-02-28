#include "configuration/Configuration.class.hpp"

int main(int argc, char **argv, char **envp) {
  if (argc != 2) {
    return (-1);
  }

  (void) envp;
  // parse the config file
  Configuration config;
  config.init(argv[1]);
  // spin up the webserver
    // do webserver things somewhere else

  // stop the webserver when you're done

  return (0);
}

// document_root /var/www/html
