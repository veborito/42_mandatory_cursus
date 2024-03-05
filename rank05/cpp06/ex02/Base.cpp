#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#include "Base.hpp"

Base::~Base() {}

Base *Base::generate() {
    srand(time(NULL));
    int x = rand()%100;
    if (x < 33) {
        std::cout << "generated an A\n";
        return new A();
    } else if (x > 33 and x < 66) {
        std::cout << "generated a B\n";
        return new B();
    } else {
        std::cout << "generated a C\n";
            return new C();
    }
}


void Base::identify(Base *p) {
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);

    if(p == nullptr)
        std::cout << "NULL";
    if (a != nullptr)
        std::cout << "A";
    if (b != nullptr)
        std::cout << "B";
    if (c != nullptr)
        std::cout << "C";
}
void Base::identify(Base &p) {
    try {    
        A a = dynamic_cast<A&>(p);
        std::cout << "A";
        return ;
    } catch (std::exception &e) {}
    try {    
        B b = dynamic_cast<B&>(p);
        std::cout << "B";
        return ;
    } catch (std::exception &e) {}
    try {    
        C c = dynamic_cast<C&>(p);
        std::cout << "C";
        return ;
    } catch (std::exception &e) {}
}
