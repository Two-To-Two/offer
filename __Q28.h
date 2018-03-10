/**
 * Created by Jinglei Yang on 3/10/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */
#include <cstring>
#include <cstdio>

void Permutation(char *str, int flag);

void Permutation(char *str) {
    if (str == nullptr) return;
    Permutation(str, 0);
}

void Permutation(char *str, int flag) {
    if (flag == (strlen(str)-1)) {
        printf("%s\n", str);
        return;
    }

    for (int i = flag; i < strlen(str); i++) {
        char tmp = str[flag];
        str[flag] = str[i];
        str[i] = tmp;

        Permutation(str, flag+1);

        tmp = str[i];
        str[i] = str[flag];
        str[flag] = tmp;
    }
}
