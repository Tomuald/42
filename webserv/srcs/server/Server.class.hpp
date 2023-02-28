#include <string>
#include <netinet/in.h>

class Server {
  public:
    Server(void);
    Server(Server const & src);
    ~Server(void);

    Server & operator=(Server const & rhs);
  private:
    std::string _hostname;
    in_addr_t   _ip_address;
    std::string _root;
    std::string _error_page;
    int         _max_body_size;
    bool        _directory_listing_status;
    std::string _cgi_format[2];
};
