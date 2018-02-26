#include <iostream>
#include <cstdarg>
#include "util.h"

template <typename T>
void findMin(T *arr, int length, T &min, int &idx) {
    if (arr == nullptr || length == 0) return;
    min = arr[0]; idx = 0;
    for (int i = 0; i < length; i++) {
        if (min > arr[i]) {
            min = arr[i]; idx = i;
        }
    }
    return;
}

template <typename T>
void selectionSort(T *arr, int length) {
    if (arr == nullptr || length <= 0) return;

    for (int i = 0; i < length; i++) {
        T min; int min_idx;
        findMin(arr+i, length - i, min, min_idx);
        if (arr[i] > min) {
            exch(arr[i], arr[i+min_idx]);
        }
    }
    return;
}

/// binary find?
template <typename T>
bool findIdxSorted(T *arr, int length, int value, int &idx) {
    for (int i = 0; i < length; i++) {
        if (arr[i] > value) {
            idx = i;
            return true;
        }
    }
    return false;
}

template <typename T>
void insertSort(T *arr, int length) {
    if (arr == nullptr || length <= 0) return;

    for (int i = 0; i < length; i++) {
        int idx;
        if (findIdxSorted(arr, i+1, arr[i], idx)) { // have other solution here
            int tmp = arr[i];
            memcpy(arr+idx+1, arr+idx, sizeof(T) * (i-idx));
            arr[idx] = tmp;
        }
        /*
         * solution2
         * for (j = i; j > 0 && arr[j-1] > temp; j--)
         * {
         *     arr[j] = arr[j-1];
         * }
         */
    }
}

/// TODO
template <typename T>
void shellSort() {}

template <typename T>
void merge(T *arr, int low, int mid, int high) {
    if (arr == nullptr || low < 0 || mid < 0 || low > high) return;

    T *tmp = new T[high-low+1];
    int cnt = 0;
    for (int i = low; i < (high+1); i++) {
        tmp[cnt++] = arr[i];
    }

    // always pick existing smallest number from two sub-array
    int i = 0; int j = mid+1-low;

    for (int n = low; n < (high+1); n++) {
        if (i > (mid-low)) arr[n] = tmp[j++];
        else if (j > (high-low)) arr[n] = tmp[i++];
        else if (tmp[i] < tmp[j]) arr[n] = tmp[i++];
        else arr[n] = tmp[j++];
    }

    delete[] tmp;
}

// NlgN
// top-to-bottom
template <typename T>
void mergeSort(T *arr, int low, int high) {
    if (arr == nullptr || low >= high || low < 0) return;

    int mid = 0.5 * (low + high);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

/// TODO
template <typename T>
T mediumValue(T *arr, int length);
template <typename T>
T mediumValue(T a, ...) {
    T med = a;
    int n;
    va_list params;
    va_start(params, n);
}

template <typename T>
T medium3(T a, T b, T c) {
    T *tmp = new T[3];
    tmp[0] = a; tmp[1] = b; tmp[2] = c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (tmp[j] > tmp[j+1]) exch(tmp[j], tmp[j+1]);
        }
    }
    return tmp[1];
}

template <typename T>
T sumArray(T a, ...) {
    T sum = 0.f;  // ? what for initial value
    int n;
    va_list params;
    va_start(params, n);
    for (int i = 0; i < n; i++) {
        sum += va_arg(params, T);
    }
    va_end(params);
    return sum;
}

template <typename T>
void partition(T *arr, int low, int high, T pivot_idx, int &part_idx) {
    if (arr == nullptr || pivot_idx < 0) return;
    T pivot = arr[pivot_idx];
    part_idx = low;
    exch(arr[pivot_idx], arr[high]);
    for (int i = low; i < (high-1); i++) {
        if (arr[i] <= pivot) exch(arr[i], arr[part_idx++]);
    }
    exch(arr[high], arr[part_idx]);
    return;
}

template <typename T>
void quickSort(T *arr, int low, int high) {
    if (arr == nullptr || low < 0 || high <= low) return;
    if ((high-low) == 1) {
        if (arr[low] > arr[high]) exch(arr[low], arr[high]);
        return;
    }

    int mid =  (low + high) / 2;
    /// 1. select pivot
    T pivot = medium3(arr[low], arr[high], arr[mid]);
    std::cout << "pivot: " << pivot << std::endl;
    int pivot_idx;
    if (pivot == arr[low]) pivot_idx = low; else if (pivot == arr[high]) pivot_idx = high; else pivot_idx = mid;
    std::cout << "pivot index: " << pivot_idx << std::endl;
    /// 2. partition
    int part_idx;
    partition(arr, low, high, pivot_idx, part_idx);
    std::cout << "partition index: " << part_idx << std::endl;
    /// 3. sort sub-array
    quickSort(arr, low, part_idx-1);
    quickSort(arr, part_idx, high);
    return;
}

/// TODO: bottom-to-top merge sort
