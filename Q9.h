#include <iostream>

int fibonacci1(int n) {
    if (n < 0) return NULL; // TODO
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci1(n-1) + fibonacci1(n-2);
}

int fibonacci2(int n) {
    if (n < 0) return NULL; //TODO
    if (n == 0) return 0;
    if (n == 1) return 1;

    int n_2 = 0;
    int sum = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = sum;
        sum = sum + n_2;
        n_2 = tmp;
    }
    return sum;
}