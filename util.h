/**
 * Created by Jinglei Yang on 2/26/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */
#ifndef ALG_UTIL_H
#define ALG_UTIL_H

template <typename T>
void exch(T &a, T &b) {
    if (a == b) return;
    T tmp = a;
    a = b;
    b = tmp;
}

#endif //ALG_UTIL_H
