#include <iostream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &instance) { *this = instance; }
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    (void)rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &o, PmergeMe const &instance) {
    (void)instance;
    o << "fill me";
    return o;
}
