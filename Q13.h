/**
 * Created by Jinglei Yang on 2/26/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

struct ListNode {
    int _value;
    ListNode *_next;
};

/// ASSUMPTION: deleted node is always in list!
void DeleteNode(ListNode **head, ListNode *toDelete) {
    if (!head || !toDelete) return;

    if (toDelete->_next != nullptr) {
        // also include deleted node is head node, but list has multiple nodes.
        ListNode *toDeleteNext = toDelete->_next;
        toDelete->_value = toDelete->_next->_value;
        toDelete->_next = toDelete->_next->_next;
        delete toDeleteNext;
        toDeleteNext = nullptr;
    }
    else if (*head == toDelete) {
        delete toDelete;
        toDelete = nullptr;
        *head = nullptr;
    }
    else {
        ListNode *tmp = *head;
        while (tmp->_next != toDelete) {
            tmp = tmp->_next;
        }

        tmp->_next = nullptr;
        delete toDelete;
        toDelete = nullptr;
    }
}