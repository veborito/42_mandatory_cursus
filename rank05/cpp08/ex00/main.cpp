#include <exception>
#include <forward_list>
#include <iostream>
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <vector>
#include "easyfind.hpp"
#include <iterator>

int main(void) {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::list<int> liste;
    std::vector<int> vector;
    std::forward_list<int> fliste;
    std::deque<int> dq; 

    liste.push_back(10);
    liste.push_back(1);
    liste.push_back(0);
    liste.push_back(4);
    liste.push_back(44);

    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);

    fliste.push_front(1);
    fliste.push_front(3);
    fliste.push_front(2);
    fliste.push_front(3);

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    try {
        std::cout << *easyfind< std::array<int, 5> >(arr, 3) << '\n';
        std::cout << *easyfind< std::array<int, 5> >(arr, 6) << '\n';
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    } try {
        std::cout << *easyfind< std::list<int> >(liste, 0) << '\n';
        std::cout << *easyfind< std::vector<int> >(vector, 4) << '\n';
        std::cout << *easyfind< std::forward_list<int> >(fliste, 3) << '\n';
        std::cout << *easyfind< std::deque<int> >(dq, 1) << '\n';
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
