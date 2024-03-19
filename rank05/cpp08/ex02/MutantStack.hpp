#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template < typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T> {
   public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const & instance) : std::stack<T>(instance) {}
	~MutantStack() {}

	MutantStack<T> &operator=(MutantStack<T> const & rhs) { std::stack<T>::operator=(rhs); return *this; }
	
	typedef typename container::iterator iterator;
    typedef typename container::reverse_iterator reverse_iterator;
	iterator begin(){ return this->c.begin(); };
	iterator end(){ return this->c.end(); };
    reverse_iterator rbegin() { return this->c.rbegin(); };
    reverse_iterator rend() { return this->c.rend(); };
};

#endif
