#include "PmergeMe.hpp"

#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(std::vector<int> vector)
            : m_vector(vector), 
              m_deque(vector.begin(), vector.end()) {}
PmergeMe::PmergeMe(PmergeMe const &instance) { *this = instance; }
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    (void)rhs;
    return *this;
}

std::vector<int> const &PmergeMe::getVector() const {
    return this->m_big;
}

void PmergeMe::sort() {
    clock_t start_1 = clock();
    this->m_insertionSortV();
    clock_t end_1 = clock();
    clock_t start_2 = clock();
    this->m_insertionSortD();
    clock_t end_2 = clock();
    std::cout << "After: ";
    print(this->m_big);
    std::cout << '\n';
    double time_taken = static_cast<double>(end_1 - start_1) 
                        / static_cast<double>(CLOCKS_PER_SEC);
    double time_taken_2 = static_cast<double>(end_2 - start_2)
                          / static_cast<double>(CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << this->m_big.size() 
              << " elements with std::vector : "
              << std::fixed << std::left << std::setw(10) << std::setfill('0')
              << time_taken << std::setprecision(8)  << " sec\n";
    std::cout << "Time to process a range of " << this->m_big.size()
              << " elements with std::deque  : "
              << std::fixed << std::setw(10) << std::setfill('0')
              << time_taken_2 << std::setprecision(8) << " sec\n";
}

void PmergeMe::m_createPairsD() {
    int i = 0, j = 1;
    while (j < static_cast<int>(this->m_deque.size())) {
        if (this->m_deque[i] < this->m_deque[j])
            this->m_pairsD.push_back(std::make_pair(this->m_deque[i],
                                                    this->m_deque[j]));
        else
            this->m_pairsD.push_back(std::make_pair(this->m_vector[j],
                                                    this->m_deque[i]));
        j += 2;
        i += 2;
    }
}

void PmergeMe::m_createBigD() {
    for (std::deque< std::pair<int, int> >::iterator it = this->m_pairsD.begin();
            it != this->m_pairsD.end(); it++)
        this->m_bigD.push_back(it->second);
}

void PmergeMe::m_createSmallD() {
    for (std::deque< std::pair<int, int> >::iterator it = this->m_pairsD.begin();
            it != this->m_pairsD.end(); it++)
        this->m_smallD.push_back(it->first);
}

void PmergeMe::m_insertionSortD() {
    bool odd = this->m_deque.size() % 2 != 0;
    int num = odd ? this->m_deque.back() : -1;
    this->m_createPairsD();
    this->m_createBigD();
    this->m_createSmallD();
    if (num != -1)
        this->m_smallD.push_back(num);
    mergeSortD(this->m_bigD, 0, this->m_bigD.size() - 1);
    binaryInsertionSortD(this->m_bigD, this->m_smallD);
}

int binarySearchD(std::deque<int> &arr, int num) {
    int left = 0;
    int right = arr.size() - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] > num)
            right = mid - 1;
        else
           left = mid + 1;
    }
    return (num > arr[left]) ? left + 1 : left;
}

void binaryInsertionSortD(std::deque<int> &arr, std::deque<int> &arr2) {
    int pos;
    int tot_size = arr.size() + arr2.size();
    for (int i = 0; i < static_cast<int>(arr2.size()); i++) {
        pos = binarySearchD(arr, arr2[i]);
        if (pos == tot_size)
            pos = tot_size - 1; 
        arr.insert(arr.begin() + pos, arr2[i]);
    }
}

void mergeSortD(std::deque<int> &arr, int start, int end) {
    if (start >= end)
        return ;
    int mid = (end + start) / 2;
    mergeSortD(arr, start, mid);
    mergeSortD(arr, mid + 1, end);
    int const leftArrSize = mid - start + 1;
    int const rightArrSize = end - mid;
    int *leftArr = new int[mid - start + 1];
    int *rightArr = new int[end - mid];
    for (int i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[start + i];
    for (int i = 0; i < rightArrSize; i++)
        rightArr[i] = arr[mid + 1 + i];
    int indexRight = 0, indexLeft = 0;
    while (indexRight < rightArrSize && indexLeft < leftArrSize) {
        if (leftArr[indexLeft] < rightArr[indexRight])
            arr[start] = leftArr[indexLeft++];
        else
            arr[start] = rightArr[indexRight++];
        start++;
    }
    for (int i = indexLeft; i < leftArrSize; i++)
        arr[start++] = leftArr[i];
    for (int i = indexRight; i < rightArrSize; i++)
        arr[start++] = rightArr[i];
    delete[] leftArr;
    delete[] rightArr;
}

void PmergeMe::m_createPairsV() {
    int i = 0, j = 1;
    while (j < static_cast<int>(this->m_vector.size())) {
        if (this->m_vector[i] < this->m_vector[j])
            this->m_pairs.push_back(std::make_pair(this->m_vector[i],
                                                   this->m_vector[j]));
        else
            this->m_pairs.push_back(std::make_pair(this->m_vector[j],
                                                   this->m_vector[i]));
        j += 2;
        i += 2;
    }
}

void PmergeMe::m_createBig() {
    for (std::vector< std::pair<int, int> >::iterator it = this->m_pairs.begin();
            it != this->m_pairs.end(); it++)
        this->m_big.push_back(it->second);
}

void PmergeMe::m_createSmall() {
    for (std::vector< std::pair<int, int> >::iterator it = this->m_pairs.begin();
            it != this->m_pairs.end(); it++)
        this->m_small.push_back(it->first);
}

void PmergeMe::m_insertionSortV() {
    bool odd = this->m_vector.size() % 2 != 0;
    int num = odd ? this->m_vector.back() : -1;
    this->m_createPairsV();
    this->m_createBig();
    this->m_createSmall();
    if (num != -1)
        this->m_small.push_back(num);
    mergeSortV(this->m_big, 0, this->m_big.size() - 1);
    binaryInsertionSortV(this->m_big, this->m_small);
}

int binarySearchV(std::vector<int> &arr, int num) {
    int left = 0;
    int right = arr.size() - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] > num)
            right = mid - 1;
        else
           left = mid + 1;
    }
    return (num > arr[left]) ? left + 1 : left;
}

void binaryInsertionSortV(std::vector<int> &arr, std::vector<int> &arr2) {
    int pos;
    int tot_size = arr.size() + arr2.size();
    for (int i = 0; i < static_cast<int>(arr2.size()); i++) {
        pos = binarySearchV(arr, arr2[i]);
        if (pos == tot_size)
            pos = tot_size - 1; 
        arr.insert(arr.begin() + pos, arr2[i]);
    }
}

void mergeSortV(std::vector<int> &arr, int start, int end) {
    if (start >= end)
        return ;
    int mid = (end + start) / 2;
    mergeSortV(arr, start, mid);
    mergeSortV(arr, mid + 1, end);
    int const leftArrSize = mid - start + 1;
    int const rightArrSize = end - mid;
    int *leftArr = new int[mid - start + 1];
    int *rightArr = new int[end - mid];
    for (int i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[start + i];
    for (int i = 0; i < rightArrSize; i++)
        rightArr[i] = arr[mid + 1 + i];
    int indexRight = 0, indexLeft = 0;
    while (indexRight < rightArrSize && indexLeft < leftArrSize) {
        if (leftArr[indexLeft] < rightArr[indexRight])
            arr[start] = leftArr[indexLeft++];
        else
            arr[start] = rightArr[indexRight++];
        start++;
    }
    for (int i = indexLeft; i < leftArrSize; i++)
        arr[start++] = leftArr[i];
    for (int i = indexRight; i < rightArrSize; i++)
        arr[start++] = rightArr[i];
    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
void print(T &arr) {
    int arrSize = arr.size();
    for (int i = 0; i < arrSize; i++) {
        if (i + 1 == arrSize)
            std::cout << arr[i];
        else
            std::cout << arr[i] << ' ';
    }
}

std::ostream &operator<<(std::ostream &o, PmergeMe const &instance) {
    (void)instance;
    o << "fill me";
    return o;
}
