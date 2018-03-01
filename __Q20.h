/**
 * Created by Jinglei Yang on 3/1/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */
#include <iostream>
#include <algorithm>

/// if m >= n, use m as test, else use n.
/// step = 2
/// if test%2 == 0, terminate condition: test = 2
/// else terminate condition: test = 1
/// for each circle, cnt = 0:
/// print numbers[m-i][cnt, j-1]
/// print numbers[m-cnt-2, (cnt+j-1)][cnt+1, (cnt+i-1)]
/// print numbers[n-cnt-2, n-cnt-2+n-2]
/// cnt++

void PrintMatrixClockwise(int **numbers, int columns, int rows) {
    if (numbers == nullptr || *numbers == nullptr) return;
    int test = std::min(columns, rows);
    int cnt = 0;
    // int m = columns; int n = rows;
    int i = columns; int j = rows;
    while (test > 2) {
        // up
        for (int k = cnt; k < (rows-1); k++) {
            std::cout << numbers[rows-j][k] << " ";
        }
        // right
        for (int k = cnt+1; k < (cnt+1+j-1); k++) {
            std::cout << numbers[k][columns-1-cnt] << " ";
        }
        // bottom
        for (int k = (i-cnt-2); k > (-cnt-1); k--) {
            std::cout << numbers[rows-1-cnt][k] << " ";
        }
        for (int k = j-cnt-2; k >(-cnt); k--) {
            std::cout << numbers[j-cnt-2][cnt] << " ";
        }
        i -= 2; j -= 2;test -= 2;
        cnt ++;
    }

    if (test == 1) {

    }
    else {

    }
}
