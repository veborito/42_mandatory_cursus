#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments.\n";
        return 1;
    }
    RPN::doCalculations(argv[1]);
    return 0;
}
