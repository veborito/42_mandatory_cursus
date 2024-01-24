#include "Harl.hpp"
#include <string>
#include <iostream>

int main() {
    Harl harl;
    std::string mess;
    while (true) {
        std::cout << "Make Harl complain (DEBUG, INFO, ERROR, WARNING, (q to quit): ";
        getline(std::cin>>std::ws, mess);
        if (mess == "q")
            break;
        harl.complain(mess);
    }
    return 0;
}
