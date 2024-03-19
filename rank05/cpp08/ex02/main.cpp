#include <exception>
#include <forward_list>
#include <iostream>
#include <array>
#include "MutantStack.hpp"

int main(void) {
	MutantStack<int> m;
	m.push(1);
	std::cout << m.top();
	MutantStack<int>::iterator it = m.begin();
    return 0;
}
