#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
   public:
    Span();
    Span(unsigned int N);
    Span(Span const &instance);
    ~Span();

    Span &operator=(Span const &rhs);
    
    std::vector<int> *getFullSpan() const;
    void addNumber(int number);
    void fillSpan(unsigned int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    
    class TooManyElementsException : public std::exception {
        virtual char const *what() const throw();
    };
    class SmallSpanException : public std::exception {
        virtual char const *what() const throw();
    };
   private:
    std::vector<int> *m_span;
    unsigned int m_size;
    unsigned int m_max_size;

};

int randomIntGenerator();
std::ostream &operator<<(std::ostream &o, Span const &instance);

#endif 
