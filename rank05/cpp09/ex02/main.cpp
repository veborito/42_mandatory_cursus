#include <cctype>
#include <deque>
#include <vector>
#include <set>
#include <sys/time.h>

#include "PmergeMe.hpp"

bool isPositivenumber(std::string s) {
    if (s.empty())
        return false;
    for (int i = 0; i < int(s.size()); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: no arguments\n";
        return 1;
    }
    std::vector<int> vec;
    for (int i = 1; i < argc; i++) {
        if (!isPositivenumber(argv[i])) {
            std::cerr << "Error: wrong argument\n";
            return 1;
        }
        vec.push_back(atoi(argv[i]));
    }
    std::set<int> set(vec.begin(), vec.end());
    if (set.size() != vec.size()) {
        std::cerr << "Error: duplicate elements !\n";
        return 1;
    }
    std::cout << "Before : ";
    print(vec);
    std::cout << '\n';
    PmergeMe s(vec);
    s.sort();
    return 0;
}
