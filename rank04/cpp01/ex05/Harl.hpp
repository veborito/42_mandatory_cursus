#ifndef HARL_H
#define HARL_H
#include <string>

class Harl {
private:
    void _debug() const;
    void _info() const;
    void _warning() const;
    void _error() const;
public:
    Harl();
    ~Harl();

    void complain(std::string level) const;
};

#endif
