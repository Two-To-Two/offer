/**
 * Created by Jinglei Yang on 3/1/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

struct BinaryTreeNode {
    int _value;
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;
};

/// Recursively swap children
/// Terminate condition: no child
/// Note: only one child

void swapChildren(BinaryTreeNode *root) {
    if (root == nullptr) return;
    BinaryTreeNode *tmp = nullptr;
    tmp = root->_left;
    root->_left = root->_right;
    root->_right = tmp;
}

void MirrorTree(BinaryTreeNode *root) {
    if (root == nullptr) return;
    swapChildren(root);
    MirrorTree(root->_left);
    MirrorTree(root->_right);
}
