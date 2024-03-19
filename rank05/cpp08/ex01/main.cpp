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
    Span span = Span(100000);
    span.fillSpan(100000);
    std::cout << span.shortestSpan() << '\n';
    std::cout << span.longestSpan() << '\n';
	try {
		Span s(10);
		s.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} try {
		Span s2(10);
		s2.addNumber(1);
		s2.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} try {
		Span s3(10);
		s3.fillSpan(11);
		std::cout << "Shortest span: " << s3.shortestSpan() << '\n';
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	} try {
		Span s4(2);
		s4.addNumber(1);
		s4.addNumber(1);
		s4.addNumber(1);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
    
    return 0;
}
