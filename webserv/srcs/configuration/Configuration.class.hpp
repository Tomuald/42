#include <fstream>
#include <map>

#include "../server/Server.class.hpp"

class Configuration {
  public:
    Configuration(void);
    Configuration(Configuration const & src);
    ~Configuration(void);

    void init(const char *path);
    Configuration & operator=(Configuration const & rhs);
  private:
  // attributes
    std::fstream    _configuration_file;
    int             _numServers;
    Server          *servers;


  // functions
    int parse(void);
    int verify(void);
    void getNumServers(void);
    std::map<std::string, std::string> *getServerBlocks(void);
};

std::ostream & operator<<(std::ostream & o, Configuration & i);
