#include "BitcoinExchange.class.hpp"

BitcoinExchange::BitcoinExchange(void) {
  return ;
}

BitcoinExchange::BitcoinExchange(std::ifstream & database) {
  std::string line;
  while (std::getline(database, line)) {
    size_t pos = line.find(",");
    if (pos == std::string::npos) {
      std::cerr << "invalid database entry" << std::endl;
      exit(0);
    }
    std::string key = line.substr(0, pos);
    key.erase(0, key.find_first_not_of(" \t\n\r"));
    key.erase(key.find_last_not_of(" \t\n\r") + 1);
    std::string value = line.substr(pos + 1, line.length());
    value.erase(0, value.find_first_not_of(" \t\n\r"));
    value.erase(value.find_last_not_of(" \t\n\r") + 1);
    if (key == "date") {
      continue ;
    }
    this->_database.insert(make_pair(key, value));
  }
  database.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
  *this = src;
  return ;
}

BitcoinExchange::~BitcoinExchange(void) { return ; }

std::multimap<std::string, std::string> BitcoinExchange::parse(std::ifstream & input) {
  std::multimap<std::string, std::string> input_file;
  std::string line;
  while (std::getline(input, line)) {
    size_t pos = line.find("|");
    std::string key;
    std::string value;
    if (pos == std::string::npos) {
      key = line.substr(0, pos);
      key.erase(0, key.find_first_not_of(" \t\n\r"));
      key.erase(key.find_last_not_of(" \t\n\r") + 1);
      value = "";
    } else {
      key = line.substr(0, pos);
      key.erase(0, key.find_first_not_of(" \t\n\r"));
      key.erase(key.find_last_not_of(" \t\n\r") + 1);
      value = line.substr(pos + 1, line.length());
      value.erase(0, value.find_first_not_of(" \t\n\r"));
      value.erase(value.find_last_not_of(" \t\n\r") + 1);
    }
    input_file.insert(std::make_pair(key, value));
  }
  return (input_file);
}

std::pair<std::string, std::string> BitcoinExchange::findKey(std::string key) {
  std::multimap<std::string, std::string>::const_iterator it;
  std::pair<std::string, std::string> object;
  std::string lowest_key;
  bool found = false;
  for (it = this->_database.begin(); it != this->_database.end(); ++it) {
    if (it->first == key) {
      return (*it);
    }
    if (it->first < key && (!found || it->first > lowest_key)) {
      lowest_key = it->first;
      object = *it;
      found = true;
    }
  }
  if (found) {
    return (object);
  }
  return (std::make_pair("", ""));
}

std::string BitcoinExchange::compare(std::string key, std::string value) {
  std::string result;
  struct tm tm;
  if (!strptime(key.c_str(), "%Y-%m-%d", &tm)) {
    return ("Error: bad input => " + key);
  } else if (value.find(".") == std::string::npos) {
    int i;
    std::istringstream(value) >> i;
    if (i < 0) {
      return ("Error: not a positive number");
    }
    if (i > 1000) {
      return ("Error: too large a number");
    }
  } else if (value.find(".") != std::string::npos) {
    float f;
    std::istringstream(value) >> f;
    if (f < 0) {
      return ("Error: not a positive number");
    }
    if (f > 1000) {
      return ("Error: too large a number");
    }
  }
  std::pair<std::string, std::string> object;
  object = this->findKey(key);
  if (!object.first.empty()) {
    int numeric_value;
    std::istringstream(value) >> numeric_value;
    std::ostringstream oss;
    if (this->isFloat(object.second)) {
      float multiplier;
      std::istringstream(object.second) >> std::fixed >> std::setprecision(2) >> multiplier;
      oss << numeric_value * multiplier;
    } else if (this->isInt(object.second)) {
      int multiplier;
      std::istringstream(object.second) >> multiplier;
      oss << numeric_value * multiplier;
    } else {
      return ("Something fucked up");
    }
    result = key + " => " + value + " = " + oss.str();
  } else {
    return ("Key was not found");
  }
  return (result);
}

bool BitcoinExchange::isFloat(const std::string value) const {
  if (value.find(".") != std::string::npos) {
    return (true);
  }
  return (false);
}

bool BitcoinExchange::isInt(const std::string value) const {
  if (value.find(".") == std::string::npos) {
    return (true);
  }
  return (false);
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
  if (this != &rhs) {
    this->_database = rhs._database;
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, BitcoinExchange const & i) {
  o << "Print something";
  (void) i;
  return (o);
}
