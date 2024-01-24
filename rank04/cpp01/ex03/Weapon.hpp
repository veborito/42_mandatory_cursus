#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
private:
    std::string _type;
public:
    Weapon(std::string name);
    ~Weapon();

    std::string const& getType() const;
    void        setType(std::string type);
};

#endif
