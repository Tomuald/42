#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
  private:
    std::string _name;
  public:
    Zombie(void);
    ~Zombie(void);
    void announce(void) const;
    void setName(std::string name);
    std::string getName(void) const;
};

#endif
