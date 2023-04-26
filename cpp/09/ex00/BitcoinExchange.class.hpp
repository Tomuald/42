#ifndef BITCOINEXCHANGE_HPP_
# define BITCOINEXCHANGE_HPP_

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <string>
# include <ctime>
# include <algorithm>
# include <iomanip>

class BitcoinExchange {
public:
  BitcoinExchange(void);
  BitcoinExchange(std::ifstream & database);
  BitcoinExchange(BitcoinExchange const & src);
  ~BitcoinExchange(void);

  std::multimap<std::string, std::string> parse(std::ifstream & input);
  std::string compare(std::string key, std::string value);
  std::pair<std::string, std::string> findKey(std::string key);

  bool isFloat(const std::string value) const;
  bool isInt(const std::string value) const;

  BitcoinExchange& operator=(BitcoinExchange const & rhs);

private:
  std::multimap<std::string, std::string> _database;
};

std::ostream & operator<<(std::ostream & o, BitcoinExchange const & i);
#endif // BITCOINEXCHANGE_HPP_
