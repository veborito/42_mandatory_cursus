#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque>

template < typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T> {
   public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const & instance) : std::stack<T>(instance) {}
	virtual ~MutantStack() {}

	MutantStack<T> &operator=(MutantStack<T> const & rhs) { std::stack<T>::operator=(rhs); return *this; }
	
	typedef std::iterator iterator;
	iterator begin(){ return this->c.begin(); };
	iterator end(){ return this->c.end(); };
};

#endif