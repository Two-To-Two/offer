/**
 * Created by Jinglei Yang on 2/26/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

#include <iostream>
#include "util.h"

/// o(n), o(n), with extra n space to store tmp array
void ReorderOddEven1(int **arr, unsigned int length) {
    if (*arr == nullptr || length == 0 || length == 1) return;

    int *ordered = new int[length];
    int odd_cursor = 0; int even_cursor = length - 1;

    for (int i = 0; i < length; i++) {
        if (((*arr)[i]%2) == 1) {
            ordered[odd_cursor++] = (*arr)[i];
        }
        else ordered[even_cursor++] = (*arr)[i];
    }

    delete[] (*arr); (*arr) = ordered; ordered = nullptr;
}

/// o(n), inplace reorder.
/// bit operation to decide odd/even
void ReorderOddEven2(int *arr, unsigned int length) {
    if (arr == nullptr || length == 0 || length == 1) return;

    int odd_cursor = 0; int even_cursor = length - 1;
    while (odd_cursor < even_cursor) {
        while ( (odd_cursor < even_cursor) && (arr[odd_cursor]&0x1!=0) ) odd_cursor++;
        while ( (odd_cursor < even_cursor) && (arr[even_cursor]&0x1==0) ) even_cursor--;

        if (odd_cursor < even_cursor) exch(arr[odd_cursor], arr[even_cursor]);
    }
}
