/**
 * Created by Jinglei Yang on 2/26/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

struct ListNode {
    int _value;
    ListNode *_next;
};

ListNode* FindKthToTail(ListNode *head, unsigned int k) {
    if (head == nullptr || k == 0) return nullptr;  /// k == 0 IMPORTANT!!!

    ListNode *first = head; ListNode *cursor = head;
    for (int i = 0; i < k-1; i++) {
        if (first->_next != nullptr) first = first->_next;
        else return nullptr;
    }

    while (first->_next != nullptr) {
        first = first->_next;
        cursor = cursor->_next;
    }

    return cursor;
}

ListNode* FindMidNode(ListNode *head) {
    if (head == nullptr) return nullptr;

    ListNode *first = head; ListNode *mid = head;
    bool flag = false;
    while (first->_next != nullptr) {
        first = first->_next;
        if (flag) mid = mid->_next;
        flag = !flag;
    }
    return mid;
}
