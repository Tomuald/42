#include <iostream>
#include <fstream>
#include <string>

void replaceOcc(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2) {
  std::string line;
  size_t pos = 0;

  if (s1.empty()) {
    std::cerr << "s1 is empty. Cannot replace." << std::endl;
    return ;
  }
  while (std::getline(ifs, line, '\0')) {
    pos = line.find(s1);
    while (pos != std::string::npos) {
      line.erase(pos, s1.size());
      line.insert(pos, s2);
      pos = line.find(s1, pos + s2.size());
    }
    ofs << line;
  }
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
    replaceOcc(ifs, ofs, (std::string)argv[2], (std::string)argv[3]);
    ifs.close();
    ofs.close();
  }
  else {
    std::cout << "Cannot open files." << std::endl;
  }
  return (0);
}
