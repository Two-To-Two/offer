/**
 * Created by Jinglei Yang on 3/10/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

struct BinaryTreeNode {
    int _value;
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;
};

BinaryTreeNode *ConvertLeft(BinaryTreeNode *root);
BinaryTreeNode *ConvertRight(BinaryTreeNode *root);

BinaryTreeNode *ConvertLeft(BinaryTreeNode *root) {
    if (root == nullptr) return nullptr;
    if (root->_left != nullptr) root->_left = ConvertLeft(root->_left);
    if (root->_right != nullptr) root->_right = ConvertRight(root->_right);
    if (root->_left != nullptr) root->_left->_right = root;
    if (root->_right != nullptr) root->_right->_left = root;

    BinaryTreeNode *tail = root;
    while (tail->_right != nullptr) tail = tail->_right;
    return tail;
}

BinaryTreeNode *ConvertRight(BinaryTreeNode *root) {
    if (root == nullptr) return nullptr;
    if (root->_left != nullptr) root->_left = ConvertLeft(root->_left);
    if (root->_right != nullptr) root->_right = ConvertRight(root->_right);
    if (root->_left != nullptr) root->_left->_right = root;
    if (root->_right != nullptr) root->_right->_left = root;

    BinaryTreeNode *head = root;
    while (head->_left != nullptr) head = head->_left;
    return head;
}

/// 1. recurse
/// 2.
BinaryTreeNode* Convert(BinaryTreeNode *root) {
    if (root == nullptr) return nullptr;
    root->_left = ConvertLeft(root->_left);
    root->_right = ConvertRight(root->_right);
    if (root->_left != nullptr) root->_left->_right = root;
    if (root->_right != nullptr) root->_right->_left = root;

    BinaryTreeNode *head = root;
    while (head->_left != nullptr) head = head->_left;
    return head;
}
