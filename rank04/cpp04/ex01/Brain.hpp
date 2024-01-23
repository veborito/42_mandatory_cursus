#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain {
public:
    Brain();
    Brain(Brain const& instance);
    ~Brain();

    Brain&          operator=(Brain const& rhs);

    std::string*    getIdeas() const;
    void            setIdea(std::string idea, unsigned int index);
private:
    std::string* m_ideas;
};

#endif
