/**
 * Created by Jinglei Yang on 2/27/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

struct ListNode {
    int _value;
    ListNode *_next;
};

ListNode* ReverseList(ListNode *head) {
    if (head == nullptr) return nullptr;
    if (head->_next == nullptr) return head;

    ListNode *first = head->_next; ListNode *second = head;
    head->_next = nullptr;

    while (first->_next != nullptr) {
        ListNode *tmp = first->_next;
        first->_next = second;
        second = first; first = tmp;
    }
    first->_next = second;
    return first;
}

ListNode* ReverseListRecursive(ListNode *current, ListNode *prev) {
    if (current == nullptr) return nullptr;
    if (current->_next != nullptr) {
        ListNode *next = current->_next;
        current->_next = prev;
        return ReverseListRecursive(next, current);
    }
    else {
        return current;
    }
}
