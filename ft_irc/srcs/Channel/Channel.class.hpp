#ifndef CHANNEL_CLASS_HPP_
# define CHANNEL_CLASS_HPP_

# include <iostream>
# include <vector>

# include "../Client/Client.class.hpp"
//# include "../Server/Server.class.hpp"


class Channel {
public:
  Channel(void);
  Channel(Channel const & src);
  ~Channel(void);

  Channel& operator=(Channel const & rhs);

  // Getters
  std::string getName(void) const;
  // Checkers
  bool channelExists(std::string name) const;
  // Setters

private:
  std::string _name;
  std::vector<Client> _clientsConnected;
};

std::ostream & operator<<(std::ostream & o, Channel const & i);
#endif // CHANNEL_CLASS_HPP_
