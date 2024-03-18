#include <array>
#include <deque>
#include <exception>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "Span.hpp"
#include <iostream>

int main(void) {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp << '\n';
    Span span = Span(1000000);
    span.fillSpan(1000000);
    std::cout << span.shortestSpan() << '\n';
    std::cout << span.longestSpan() << '\n';
    
    return 0;
}
