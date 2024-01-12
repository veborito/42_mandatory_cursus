#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>

class Zombie {
public:
    Zombie(std::string name);
    ~Zombie();

    void annonce() const;
private:
    std::string _name;
};

#endif
