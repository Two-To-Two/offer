/**
 * Created by Jinglei Yang on 3/1/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */
#include <stack>
#include <cassert>

/// TODO: what if store pointers in auxiliary stack? (save space)
/// seems illeagle to use T* ???
template <typename T>
class StackWithMin {
public:
    std::stack<T> data;
    std::stack<T> aux;

    void push(const T &value);
    void pop();
    const T& min() const;
};

template <typename T>
void StackWithMin<T>::push(const T &value) {
    data.push(value);
    if (aux.empty()) aux.push(value);
    else {
        if (aux.top() < value) aux.push(aux.top());
        else aux.push(value);
    }
}

template <typename T>
void StackWithMin<T>::pop() {
    if (data.empty()) return;
    data.pop();
    aux.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const {
    assert(data.empty() && aux.empty());
    return aux.top();
}

///////////////////////////////////////////////////
template <typename T>
class StackWithMinUsePtr {
public:
    std::stack<T> _data;
    // std::stack<*T> _aux; /// ILLEAGLE!!!

    void push(T value);
    void pop();
    T min();
};

/*
template <typename T>
void StackWithMinUsePtr<T>::push(T value) {
    _data.push(value);
    if (_aux.empty() || (value < *(_aux.top())) ) {
        T *min = &_data.top(); _aux.push(min);
    }
}

template <typename T>
T StackWithMinUsePtr<T>::min() {
}
*/