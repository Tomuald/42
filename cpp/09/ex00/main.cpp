#include "BitcoinExchange.class.hpp"

int main(int argc, char *argv[]) {
  (void) argc;
  (void) argv;

  if (argc < 2) {
    std::cerr << "usage: ./btc <input.txt>" << std::endl;
    exit(0);
  }
  std::ifstream database("data.csv");
  if (!database.is_open()) {
    std::cerr << "Invalid database file" << std::endl;
    exit(0);
  }
  BitcoinExchange btc = BitcoinExchange(database);
  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    std::cerr << "invalid input file" << std::endl;
    exit(0);
  }
  std::multimap<std::string, std::string> input_file;
  input_file = btc.parse(input);
  std::multimap<std::string, std::string>::iterator it;
  for (it = input_file.begin(); it != input_file.end(); ++it) {
    std::cout << btc.compare(it->first, it->second) << std::endl;
    //std::cout << it->first << std::endl;
  }
  return 0;
}
