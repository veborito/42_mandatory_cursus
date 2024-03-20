#include <iostream>
#include <list>
#include <algorithm>
#include "MutantStack.hpp"

int main(void) {
	std::cout << "---- DEFAULT TESTS ----\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
	std::cout << "mstack :\n";
    while (it != ite) {
    	std::cout << *it << std::endl;
    	++it;
    }

	std::cout << "------ SAME TEST FOR LIST ----\n";
	std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << "l top: " << l.back() << std::endl;
    l.pop_back();
    std::cout << "l size: " << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
	std::list<int>::iterator i = l.begin();
    std::list<int>::iterator ie = l.end();
    ++i;
    --i;
	std::cout << "l :\n";
    while (i != ie) {
    	std::cout << *i << std::endl;
    	++i;
    }
	std::stack<int> s(mstack);
	std::cout << "------ NEW TESTS ----\n";
	MutantStack<std::string> sStack;
	sStack.push("Boris");
	sStack.push("carmelle");
	sStack.push("jason");
	sStack.push("sancho");
	sStack.push("jo");
	std::cout << "sStack: \n";
	for (MutantStack<std::string>::reverse_iterator it = sStack.rbegin(); it != sStack.rend(); it++) {
		std::cout << *it << '\n';
	}

	MutantStack<int> iStack;
	iStack.push(2);
    iStack.push(3);
    iStack.push(4);
    iStack.push(5);
	mstack.swap(iStack);
	std::cout << "mstack after swap: \n";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++) {
		std::cout << *it << '\n';
	}
	std::cout << "find: " << *std::find(mstack.begin(), mstack.end(), 4) << '\n';
    return 0;
}
