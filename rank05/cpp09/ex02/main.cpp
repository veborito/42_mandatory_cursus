#include <deque>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    (void)argv;
    (void)argc;
    std::vector<int> vec;
    std::deque<int> deq;
    int arr[] = {3, 5, 9, 1, 6, 2, 0};
    vec.insert(vec.end(), arr, arr+7);
    deq.insert(deq.end(), arr, arr+7);
    PmergeMe s(vec);
    s.sort();
    return 0;
}
