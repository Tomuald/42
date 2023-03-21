#include <string>
#include <sstream>

std::string generateResponse(std::string command, std::string code, std::string msg) {
  if (command.empty() || code.empty() || msg.empty()) {
    return ("FAIL\r\n");
  }
  std::stringstream response;
  response << ":localhost" << " " << code << " " << command << " :" << msg << "\r\n";
  return (response.str());
}
