#include "Span.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

Span::Span() : m_span(nullptr), m_size(0), m_max_size(0) {}
Span::Span(unsigned int N)
    : m_span(new std::vector<int>(N)), m_size(0), m_max_size(N) {}
Span::Span(Span const &instance) { *this = instance; }
Span::~Span() { delete this->m_span; }

Span &Span::operator=(Span const &rhs) {
    (void)rhs;
    return *this;
}

std::vector<int> *Span::getFullSpan() const { return this->m_span; }

void Span::addNumber(int number) {
    if (!this->m_span) throw Span::SmallSpanException();
    this->m_size += 1;
    if (this->m_size > this->m_max_size) throw Span::TooManyElementsException();
    this->m_span->at(this->m_size - 1) = number;
}

unsigned int Span::shortestSpan() {
    if (!this->m_span or this->m_size < 2)
        throw Span::SmallSpanException();
    std::set<int> s;
    copy(this->m_span->begin(), this->m_span->end(),
         std::inserter(s, s.begin()));
    int diff = INT_MAX;
    std::set<int>::iterator it = s.begin();
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
        int first = *it;
        if (++it == s.end()) break;
        int second = *it;
        if (diff > std::abs(second - first)) diff = std::abs(second - first);
    }
    return diff;
}

unsigned int Span::longestSpan() {
    if (!this->m_span or this->m_size < 2)
        throw Span::SmallSpanException();
	std::sort(this->m_span->begin(), this->m_span->end());
    std::vector<int>::reverse_iterator end = this->m_span->rbegin();
    std::vector<int>::iterator start = this->m_span->begin();
    return std::abs(*end - *start);
}

void Span::fillSpan(unsigned int n) {
    if (!this->m_span or n > this->m_max_size)
        throw Span::TooManyElementsException();
	this->m_size = n;
    std::srand(std::time(0));
    std::generate(this->m_span->begin(), this->m_span->end(),
                  randomIntGenerator);
}

char const *Span::TooManyElementsException::what() const throw() {
    return "The span is full !";
}

char const *Span::SmallSpanException::what() const throw() {
    return "The span is empty or too small !";
}

int randomIntGenerator() { return (std::rand() % RAND_MAX) - (RAND_MAX / 2); }

std::ostream &operator<<(std::ostream &o, Span const &instance) {
    o << "Span:";
    for (std::vector<int>::iterator i = instance.getFullSpan()->begin();
         i != instance.getFullSpan()->end(); i++)
        o << ' ' << *i;
    return o;
}
