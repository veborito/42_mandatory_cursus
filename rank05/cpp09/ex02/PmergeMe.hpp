#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe {
   public:
    PmergeMe();
    PmergeMe(PmergeMe const &instance);
    ~PmergeMe();

    PmergeMe &operator=(PmergeMe const &rhs);
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &instance);

#endif 
