#include <string>

std::string lowerString(std::string str) {
  std::string lowercase;

  for (size_t i = 0; i < str.size(); i++) {
    lowercase.push_back(tolower(str[i]));
  }
  return (lowercase);
}
