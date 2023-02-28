#include "Configuration.class.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>

Configuration::Configuration(void) {
  this->_numServers = 0;
}

Configuration::~Configuration(void) {
  if (this->_configuration_file.is_open())
    this->_configuration_file.close();
  delete [] servers;
}

void Configuration::init(const char *path) {
  if (!path)
    return ;
  try {
    this->_configuration_file.open(path);
    if (!this->_configuration_file.is_open())
      throw std::exception();
    else {
      getNumServers();
      this->servers = new Server[this->_numServers];
      parse();
      verify();
    }
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }
}

void Configuration::getNumServers(void) {
  std::string   line;
  bool          inside_server_block;

  while (std::getline(this->_configuration_file, line)) {
    if (line.find("{") != std::string::npos && line.find("server") != std::string::npos) {
      inside_server_block = true;
      this->_numServers++;
      continue;
    }
    if (inside_server_block && line.find("}") != std::string::npos) {
      inside_server_block = false;
    }
  }
  this->_configuration_file.clear();
  this->_configuration_file.seekg(0, std::ios::beg);
}

std::map<std::string, std::string> *Configuration::getServerBlocks(void) {
  std::map<std::string, std::string> *server_blocks;
  std::string   line;
  bool          inside_server_block;
  int           index;

  server_blocks = new std::map<std::string, std::string>[this->_numServers];
  index = 0;
  while (std::getline(this->_configuration_file, line)) {
    if (line.find("{") != std::string::npos && line.find("server") != std::string::npos) {
      inside_server_block = true;
      continue;
    }
    if (inside_server_block && line.find("}") != std::string::npos) {
      inside_server_block = false;
      index++;
    }
    if (inside_server_block) {
      std::string::size_type pos = line.find_first_not_of(" \t");

      if (pos != std::string::npos) {
        std::string newtoken = line.substr(pos);
        std::vector<std::string> tokens;
        std::istringstream iss(newtoken);
        std::string token;
        while (std::getline(iss, token, ' '))
            tokens.push_back(token);
        server_blocks[index].insert(std::make_pair(tokens[0], tokens[1]));
      }
    }
  }
  return (server_blocks);
}

int Configuration::parse(void) {
  // std::map<std::string, void (Configuration::*)(std::string)> settings;
  // std::map<std::string, void (Configuration::*)(std::string)>::iterator it;
  std::string               line;
  std::map<std::string, std::string>  *server_blocks;

  server_blocks = getServerBlocks();

  for (int i = 0; i < this->_numServers; i++) {
    std::map<std::string, std::string>::iterator it;
    for (it = server_blocks[i].begin(); it != server_blocks[i].end(); it++) {
      std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
  }

  delete [] server_blocks;
  this->_configuration_file.close();
  return (0);
}

int Configuration::verify(void) {return (0);}
