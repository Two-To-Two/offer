#include <iostream>
#include <queue>

template <typename T>
class CStack {
public:
    CStack() = default;
    ~CStack();

private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};