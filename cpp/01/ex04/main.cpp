#include <iostream>
#include <fstream>
#include <string>

std::string replaceLine(std::string line, std::string s1, std::string s2) {
  size_t pos;
  std::string newstring;

  pos = line.find(s1);
  if (pos == std::string::npos)
    return (line);
  else {
    while (pos != std::string::npos) {
      newstring = line.erase(pos, s1.size()).insert(pos, s2);
      pos = line.find(s1);
    }
  }
  return (newstring);
}

int main(int argc, char **argv) {
  std::ifstream ifs;
  std::ofstream ofs;

  if (argc < 4) {
    std::cerr << "ERROR: Usage: ./program <filename> <s1> <s2>" << std::endl;
    return (1);
  }
  ifs.open(argv[1]);
  ofs.open((std::string)argv[1] + ".replace");
  if (ifs.is_open() && ofs.is_open()) {
    std::string line;
    while (std::getline(ifs, line))
      ofs << replaceLine(line, argv[2], argv[3]) << std::endl;
    ifs.close();
    ofs.close();
  }
  else {
    std::cout << "Cannot open files." << std::endl;
  }
  return (0);
}
