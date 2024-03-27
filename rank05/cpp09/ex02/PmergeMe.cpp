#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(std::vector<int> vector) : m_vector(vector) {
}
PmergeMe::PmergeMe(PmergeMe const &instance) { *this = instance; }
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    (void)rhs;
    return *this;
}
void PmergeMe::m_createPairsD() {
    int i = 0, j = 1;
    while (j < static_cast<int>(this->m_deque.size())) {
        if (this->m_deque[i] < this->m_deque[j])
            this->m_pairsD.push_back(std::make_pair(this->m_deque[i], this->m_deque[j]));
        else
            this->m_pairsD.push_back(std::make_pair(this->m_vector[j], this->m_deque[i]));
        j += 2;
        i += 2;
    }
}

void PmergeMe::m_createBigD() {
    for (std::deque< std::pair<int, int> >::iterator it = this->m_pairsD.begin(); it != this->m_pairsD.end(); it++)
        this->m_bigD.push_back(it->second);
}

void PmergeMe::m_createSmallD() {
    for (std::deque< std::pair<int, int> >::iterator it = this->m_pairsD.begin(); it != this->m_pairsD.end(); it++)
        this->m_smallD.push_back(it->first);
}

void PmergeMe::m_createPairsV() {
    int i = 0, j = 1;
    while (j < static_cast<int>(this->m_vector.size())) {
        if (this->m_vector[i] < this->m_vector[j])
            this->m_pairs.push_back(std::make_pair(this->m_vector[i], this->m_vector[j]));
        else
            this->m_pairs.push_back(std::make_pair(this->m_vector[j], this->m_vector[i]));
        j += 2;
        i += 2;
    }
}

void PmergeMe::m_createBig() {
    for (std::vector< std::pair<int, int> >::iterator it = this->m_pairs.begin(); it != this->m_pairs.end(); it++)
        this->m_big.push_back(it->second);
}

void PmergeMe::m_createSmall() {
    for (std::vector< std::pair<int, int> >::iterator it = this->m_pairs.begin(); it != this->m_pairs.end(); it++)
        this->m_small.push_back(it->first);
}

void PmergeMe::insertionSortV() {
    bool odd = this->m_vector.size() % 2 == 0;
    int num = odd ? this->m_vector.back() : -1;
    this->m_createPairsV();
    this->m_createBig();
    this->m_createSmall();
    if (num != -1)
        this->m_small.push_back(num);
    mergeSort(this->m_big, 0, this->m_big.size() - 1);
    std::vector<int> final;
    
    final.insert(final.begin(), this->m_small.begin(), this->m_small.end());
    final.insert(final.begin(), this->m_big.begin(), this->m_big.end());
    insertionSort(final);
    print(final);
    std::cout << '\n';
}

template <typename T>
int binarySearch(T &arr, int num) {
    int size = arr.size();
    int mid = (size - 1) / 2;
    while (mid != 0 or mid < size) {
        if (mid + 1 < size and arr[mid] < num and arr[mid + 1] > num)
            return mid + 1;
        else if (arr[mid] > num)
            mid /= 2;
        else if (mid + 1 < size and arr[mid + 1])
            mid += mid / 2;
    }
    return mid;
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

template <typename T>
void insert(T &arr, T &arr2) {
    int pos;
    for (int i = 0; i < static_cast<int>(arr2); i++) {
        pos = binary_search(arr, arr2[i]);
        arr.insert(arr.begin() + pos, arr[i]);
    }
}

template <typename T>
void insertionSort(T &arr) {
    int i, j, compare_el;
    for (i = 1; i < static_cast<int>(arr.size()); i++) {
        compare_el = arr[i];
        j = i - 1;
        while (j >= 0 and arr[j] > compare_el) {
            std::swap(arr[j + 1], arr[j]);
            j  -= 1;
        }
    }
}

template <typename T>
void mergeSort(T &arr, int start, int end) {
    if (start >= end)
        return ;
    int mid = (end + start) / 2;
    mergeSort<T>(arr, start, mid);
    mergeSort<T>(arr, mid + 1, end);
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

std::ostream &operator<<(std::ostream &o, PmergeMe const &instance) {
    (void)instance;
    o << "fill me";
    return o;
}
