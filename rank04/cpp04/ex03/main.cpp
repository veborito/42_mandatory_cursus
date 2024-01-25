#include <iostream>
#include <string>

int main() {
    std::string     string = "HI THIS IS BRAIN";
    std::string*    stringPTR = &string;
    std::string&    stringREF = string;

    std::cout << "Adress of string: " << &string << "\nAdress of stringPTR: "
              << stringPTR << "\nAdress of stringREF: " << &stringREF << "\n\n";

    std::cout << "string: " << string << "\nstringPTR: "
              << *stringPTR << "\nstringREF: " << stringREF << '\n';
    return 0;
}
