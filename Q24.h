/**
 * Created by Jinglei Yang on 3/9/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

int findMidIdx(int sequence[], int min, int max, int value) {
    if (sequence == nullptr) return 0;
    if (min == max) return min;
    int mid = (max+min) * 0.5;
    if (sequence[mid] > value) {
        return findMidIdx(sequence, min, mid, value);
    } else {
        return findMidIdx(sequence, mid+1, max, value);
    }
}

bool checkValidity(int sequence[], int min, int max, int div_idx, int value) {
    for (int i = min; i < div_idx; i++) {
        if (sequence[i] >= value) return false;
    }
    for (int i = div_idx; i < max; i++) {
        if (sequence[i] <= value) return false;
    }
    return true;
}

/// 1. get root node (the last one)
/// 2. divide sequence to left sub-tree and right sub-tree
/// 3. recursively
bool VerifyWquenceOfBST (int sequence[], int min, int max) {
    if (sequence == nullptr) return false;
    if (min == max) return true;
    int root = sequence[max];
    int flag = findMidIdx(sequence, min, max, root);
    if ( !checkValidity(sequence, min, max, flag, root) ) return false;
    if ( !VerifyWquenceOfBST(sequence, min, flag-1) ) return false;
    if ( !VerifyWquenceOfBST(sequence, flag, max-1) ) return false;
    return true;
}