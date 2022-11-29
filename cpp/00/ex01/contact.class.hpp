#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {
  public:
    Contact(void);
    ~Contact(void);

    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getNumber(void);
    std::string getSecret(void);

    void setFirstName(std::string _input);
    void setLastName(std::string _input);
    void setNickname(std::string _input);
    void setNumber(std::string _input);
    void setSecret(std::string _input);
  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;
};

#endif
