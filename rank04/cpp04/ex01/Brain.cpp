#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() {
    std::cout << "Brain constructor called\n";
    this->m_ideas = new std::string[100];
    for(int i = 0; i < 100; ++i)
        this->m_ideas[i] = "empty";
}

Brain::Brain(Brain const& instance) {
    std::cout << "Brain copy constructor called\n";
    this->m_ideas = new std::string[100];
    if (instance.m_ideas) {
        for(int i = 0; i < 100; ++i)
            this->m_ideas[i] = instance.m_ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called\n";
    delete[] this->m_ideas;
}

Brain& Brain::operator=(Brain const& rhs) {
    delete[] this->m_ideas;
    this->m_ideas = new std::string[100];
    if (rhs.m_ideas) {
        for(int i = 0; i < 100; ++i)
            this->m_ideas[i] = rhs.m_ideas[i];
    }
    return *this;
}

std::string* Brain::getIdeas() const {
    return this->m_ideas;
}

void Brain::setIdea(std::string idea, unsigned int index) {
    this->m_ideas[index] = idea;
}
