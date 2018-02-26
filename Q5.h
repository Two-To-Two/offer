#include <iostream>

struct ListNode {
    int _value;
    ListNode *_next;
};

void addToTail(ListNode **head, int value) {    // since we want to modify the value of pointer, thus pass ** instead of *
    ListNode *node = new ListNode();
    node->_value = value;
    node->_next = nullptr;
    if (*head == nullptr)
        *head = node;
    else {
        ListNode *tmp = *head;
        while (tmp->_next != nullptr) {
            tmp = tmp->_next;
        }
        tmp->_next = node;
    }
}

void deleteNode(ListNode **head, int value) {
    if (head == nullptr || *head == nullptr) return;

    ListNode *cursor = *head;
    if ((*head)->_value == value) {
        *head = (*head)->_next;
    }else {
        ListNode *fhead = *head;
        while (fhead->_next != nullptr && fhead->_next->_value != value) {
            fhead = fhead->_next;
        }
        cursor = fhead->_next;
        fhead->_next = fhead->_next->_next;
    }

    if (cursor != nullptr) {
        delete cursor;  // free memory
        cursor = nullptr;   // handle dangling ptr
    }
    return;
}

void printListReverse(ListNode *head) {
    if (head != nullptr) {
        if (head->_next != nullptr) {
            printListReverse(head->_next);
        }
        std::cout << head->_value << std::endl;
    }
}