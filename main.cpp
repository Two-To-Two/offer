#include <iostream>
#include "Q22.h"

int main() {
    int push_arr[] = {1,2,3,4,5};
    int pop_arr[] = {4,3,5,1,2};

    std::cout << IsPopOrder(push_arr, pop_arr, 5) << std::endl;
}