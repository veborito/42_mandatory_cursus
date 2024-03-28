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

    std::vector<int> const &getVector() const;

    void sort();


   private:
    std::vector<int> m_vector;
    std::deque<int> m_deque;
    std::vector< std::pair<int, int> > m_pairs;
    std::deque< std::pair<int, int> > m_pairsD;
    std::vector<int> m_big;
    std::vector<int> m_small;
    std::deque<int> m_bigD;
    std::deque<int> m_smallD;

    void m_createPairsV();
    void m_createPairsD();
    void m_createBig();
    void m_createBigD();
    void m_createSmall();
    void m_createSmallD();
    void m_insertionSortV();
    void m_insertionSortD();
};

template <typename T>
void print(T &arr);

int binarySearchV(std::vector<int> &arr, int num);
void binaryInsertionSortV(std::vector<int> &arr, std::vector<int> &arr2);
void mergeSortV(std::vector<int> &arr, int start, int end);

int binarySearchD(std::deque<int> &arr, int num);
void binaryInsertionSortD(std::deque<int> &arr, std::deque<int> &arr2);
void mergeSortD(std::deque<int> &arr, int start, int end);

std::ostream &operator<<(std::ostream &o, PmergeMe const &instance);

#endif 
