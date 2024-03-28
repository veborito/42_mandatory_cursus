#include <vector>
#include <set>
#include <iomanip>

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
    if (argc == 2) {
        clock_t start_1 = clock();

        clock_t end_1 = clock();
        std::vector<int> vector;
        vector.push_back(vec.front());
        clock_t start_2 = clock();
        std::deque<int> deque;
        deque.push_back(vec.front());
        clock_t end_2 = clock();
        std::cout << "After: " << vector.front() << '\n';
        double time_taken = static_cast<double>(end_1 - start_1) 
                            / static_cast<double>(CLOCKS_PER_SEC);
        double time_taken_2 = static_cast<double>(end_2 - start_2)
                              / static_cast<double>(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << 1 
                  << " element with std::vector : "
                  << std::fixed << std::left << std::setw(10) << std::setfill('0')
                  << time_taken << std::setprecision(8)  << " sec\n";
        std::cout << "Time to process a range of " << 1 
                  << " element with std::deque  : "
                  << std::fixed << std::setw(10) << std::setfill('0')
                  << time_taken_2 << std::setprecision(8) << " sec\n";
        return 0;
    }
    PmergeMe s(vec);
    s.sort();
    return 0;
}
