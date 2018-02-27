/**
 * Created by Jinglei Yang on 2/27/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

struct ListNode {
    int _value;
    ListNode *_next;
};

ListNode *minNode(ListNode *node1, ListNode *node2) {
    if (node1 == nullptr || node2 == nullptr) return nullptr;   /// TODO
    if (node1->_value <= node2->_value) return node1;
    else return node2;
}

ListNode* Merge(ListNode *head1, ListNode *head2) {
    if (head1 == nullptr || head2 == nullptr) return nullptr;

    ListNode *merged_head = nullptr;
    ListNode *cursor1 = nullptr; ListNode *cursor2 = nullptr;
    if (head1->_value <= head2->_value) {
        merged_head = head1;
        cursor1 = head1->_next; cursor2 = head2;
    }
    else {
        merged_head = head2;
        cursor1 = head1; cursor2 = head2;
    }

    ListNode *merged_cursor = merged_head;
    while (cursor1->_next == nullptr && cursor2->_next == nullptr) {
        if (cursor1->_next == nullptr) {
            merged_cursor->_next = cursor2;
            cursor2 = cursor2->_next;
        }
        else if (cursor2->_next == nullptr) {
            merged_cursor->_next = cursor1;
            cursor1 = cursor1->_next;
        }
        else {
            if (cursor1->_value <= cursor2->_value) {
                merged_cursor->_next = cursor1; cursor1->_next = cursor1;
            }
            else {
                merged_cursor->_next = cursor2; cursor2->_next = cursor2;
            }
        }
    }
    return merged_head;
}

ListNode* MergeRecursive (ListNode *head1, ListNode *head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    ListNode *merged_head = nullptr;
    if (head1->_value <= head2->_value) {
        merged_head = head1;
        MergeRecursive(head1->_next, head2);
    }
    else {
        merged_head = head2;
        MergeRecursive(head1, head2->_next);
    }
    return merged_head;
}