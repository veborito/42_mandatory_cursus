#include "Harl.hpp"
#include <sstream>
#include <string>
#include <iostream>

void tests(int numOfTests, std::string tests) {
    std::string* cases = new std::string [numOfTests];
    std::stringstream s(tests);
    int i = 0;
    while(std::getline(s, cases[i], ' ') and i < numOfTests)
        i++;
    Harl harl;
    for(int i = 0; i < numOfTests; ++i) {
        std::cout << i << ' ';
        harl.complain(cases[i]);
    }
}

int main() {
    tests(5, "SALAM INFO DEBUG WARNING ERROR .");
    Harl empty;
    std::cout << "Empty string test: ";
    empty.complain("");
    return 0;
}
