#include <iostream>
#include <stack>

template <typename T>
class CQueue {
public:
    CQueue() = default;
    ~CQueue();

    void exchangeStack();
    void appendTail(const T &node);
    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

/*
 * 1. always at least one stack empty
 * 2. for appendTail(), append to stack1.
 *      if stack2 not empty
 *          exchange; append;
 *      else append
 * 3. for deleteHead(), pop on stack2
 */
/*
 * IMPROVED:
 * exchangeStack is not necessary if we only need appendTail() and deleteHead().
 * for appendTail, we simply append to stack1, which is always in reverse order.
 * for deleteHead, because stack2's top is always the "oldest" element,
 * when stack2 is not empty, we simply pop;
 * when stack2 is empty, it means elements previously moved to stack2 have all been popped,
 * we move elements in stack1 to stack2, if stack1 is not empty.
 */


template <typename T>
void CQueue<T>::exchangeStack() {
    if (stack1.size() == stack2.size() == 0) return;
    if (stack1.size() == 0) {
        // stack1 -> stack2
        for (int i = 0; i < stack1.size(); i++) {
            T& top = stack1.top();  ///
            stack1.pop();
            stack2.push(top);
        }
    } else {
        // stack2 -> stack1
        for (int i = 0; i < stack2.size(); i++) {
            T top = stack2.top();
            stack2.pop();
            stack1.push(top);
        }
    }
    /// need to check if only one empty?
    return;
}

template <typename T>
void CQueue<T>::appendTail(const T &node) {
    if (stack1.size() == stack2.size() ==0) {
        stack1.push(node);
        return;
    }
    if (stack2.size() != 0) {
        exchangeStack();
    }
    stack1.push(node);
    return;
}

template <typename T>
T CQueue<T>::deleteHead() {
    if (stack1.size() == stack2.size() ==0) {
        return;
    }
    if (stack1.size() != 0) {
        exchangeStack();
    }
    stack2.pop();
}

/// TODO: Q7 ??? o(n) + o(n)
