#include <iostream>
#include <exception>

int Min(int *arr, int length) {
    if (arr == nullptr || length <= 0) return NULL;

    if (arr[0] < arr[length-1] || length == 1) return arr[0];

    int before = length-1;
    int after = 0;
    int flag = arr[length-1];

    do {
        int mid = (before+after) / 2;
        if (arr[mid] < flag) before = mid;
        else after = mid;
    } while (before != (after+1));

    return arr[before];
}
