#include <iostream>
#include <iomanip>
#include <string>

void formatString(std::string s) {
    if (s.length() > 10) {
        std::cout << s.substr(0, 9) + '.';
        return;
    }
    std::cout << std::setw(10) << s;
}

bool isNum(std::string s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}
