#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

int main() {
    Bureaucrat boris("Boris", 1);
    Bureaucrat carmelle("Carmelle", 150);
    Bureaucrat mily("Mily", 10);

    try {
        Bureaucrat bob("bob", 1000);
        std::cout << "comment va ton pantalon\n";
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        Bureaucrat jack("jack", 0);
        std::cout << "comment va ton pantalon\n";
        std::cout << jack << '\n';
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        boris.incrementGrade();
        std::cout << "comment va ton pantalon\n";
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        carmelle.decrementGrade();
        std::cout << "comment va ton pantalon\n";
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << mily << '\n';
        mily.decrementGrade();
        std::cout << mily << '\n';
        mily.incrementGrade();
        std::cout << mily << '\n';
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
