#include <iostream>
#include <deque>
#include <vector>

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

std::vector<int*> *createPairsV(std::vector<int> const &arr) {
    int i = 0, j = 1;
    std::vector<int*> *pairs = new std::vector<int*>;
    while (j < static_cast<int>(arr.size())) {
        int pair[2] = {arr[i], arr[j]};
        pairs->push_back(pair);
        j += 2;
        i += 2;
    }
    return pairs;
}

void mergeInsertSort(std::vector<int> &arr) {
    std::vector<int*> *pairs = createPairsV(arr);
    (void)pairs;
    
}

int main(int argc, char *argv[]) {
    (void)argv;
    (void)argc;
    std::vector<int> vec;
    std::deque<int> deq;
    int arr[] = {3, 5, 6, 1, 9, 2};
    vec.insert(vec.end(), arr, arr+6);
    deq.insert(deq.end(), arr, arr+6);
    std::vector<int*> *pairs = createPairsV(vec);
    std::vector<int*>::iterator it = pairs->begin();
    std::cout << *it[0] << '\n';

    return 0;
}
