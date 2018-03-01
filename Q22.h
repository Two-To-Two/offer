/**
 * Created by Jinglei Yang on 3/1/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */
#include <stack>

bool IsPopOrder (const int *push_arr, const int *pop_arr, int length) {
    if (push_arr == nullptr || pop_arr == nullptr) return false;

    std::stack<int> aux;
    int push_cursor = 0;
    // int pop_cursor = 0;
    for (int pop_cursor = 0; pop_cursor < length; pop_cursor++) {
        if ((!aux.empty() && aux.top() != pop_arr[pop_cursor]) || aux.empty()) {
            while (push_cursor < length) {
                aux.push(push_arr[push_cursor]);
                if (push_arr[push_cursor++] == pop_arr[pop_cursor]) break;
            }
            if (aux.top() != pop_arr[pop_cursor]) return false;
        }
        aux.pop();
    }
    return true;
}