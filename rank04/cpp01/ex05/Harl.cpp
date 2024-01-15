#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    typedef void (Harl::*Messages)();
    std::string messages[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Messages mess[4] = {&Harl::_debug, &Harl::_info, 
                        &Harl::_warning, &Harl::_error };
    for (int i = 0; i < 4; ++i) {
        if (messages[i] == level) {
            (this->*mess[i])();
            return;
        }
    }
    std::cout << "this level does not exist: so Harl never complains ;) !\n";
}

void Harl::_debug() {
    std::cout << "I love having extra bacon for my"
              << " 7XL-double-cheese-triple-pickle-specialketchup burger."
              << "I really do!\n";
}
void Harl::_info() {
    std::cout << "I cannot believe adding extra bacon costs more money."
              << " You didn’t putenough bacon in my burger!"
              << " If you did, I wouldn’t be asking for more!\n";
}
void Harl::_warning() {
    std::cout << "I think I deserve to have some extra bacon for free."
              << " I’ve been coming for years whereas you started working"
              << " here since last month.\n";
}
void Harl::_error() {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
