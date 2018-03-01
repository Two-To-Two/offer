/**
 * Created by Jinglei Yang on 2/27/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */

struct BinaryTreeNode {
    int _value;
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;
};

bool isEqualNode(BinaryTreeNode *node1, BinaryTreeNode *node2) {
    if (node1 == nullptr && node2 == nullptr) return true;
    if (node1 == nullptr || node2 == nullptr) return false;

    if (node1->_value != node2->_value) return false;

    if ( (node1->_left == nullptr || node2->_left == nullptr) && (node1->_left != node2->_left) ) return false;
    if ( (node1->_right == nullptr || node2->_right == nullptr) && (node1->_right != node2->_right) ) return false;

    if ((node1->_left == nullptr && node2->_left== nullptr) || (node1->_left->_value == node2->_left->_value) &&
            ((node1->_right == nullptr && node2->_right == nullptr) || node1->_right->_value == node2->_right->_value) ) return true;
    return false;
}

bool HasSubtree (BinaryTreeNode *root1, BinaryTreeNode *root2) {
    if (isEqualNode(root1, root2)) return true;

    if (root1 != nullptr) {
        if (root1->_left != nullptr && HasSubtree(root1->_left, root2)) return true;
        if (root1->_right != nullptr && HasSubtree(root1->_right, root2)) return true;
    }

    return false;
}