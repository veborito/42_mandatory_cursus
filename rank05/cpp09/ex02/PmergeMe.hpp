#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

class PmergeMe {
   public:
    PmergeMe();
    PmergeMe(std::vector<int> vec);
    PmergeMe(PmergeMe const &instance);
    ~PmergeMe();

    PmergeMe &operator=(PmergeMe const &rhs);

    void m_createPairsV();
    void m_createPairsD();
    void m_createBig();
    void m_createBigD();
    void m_createSmall();
    void m_createSmallD();
    void insertionSortV();
    void insertionSortD();

   private:
    std::vector<int> m_vector;
    std::deque<int> m_deque;
    std::vector< std::pair<int, int> > m_pairs;
    std::deque< std::pair<int, int> > m_pairsD;
    std::vector<int> m_big;
    std::vector<int> m_small;
    std::vector<int> m_bigD;
    std::vector<int> m_smallD;
};

template <typename T>
void print(T &arr);
template <typename T>
int binarySearch(T &arr, int num);
template <typename T>
void insert(T &arr, T &arr2);
template <typename T>
void insertionSort(T &arr);
template <typename T>
void mergeSort(T &arr, int start, int end);
std::ostream &operator<<(std::ostream &o, PmergeMe const &instance);

#endif 
