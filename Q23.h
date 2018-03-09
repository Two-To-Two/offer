/**
 * Created by Jinglei Yang on 3/9/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */
#include <iostream>
#include <queue>

struct BinaryTreeNode {
    int _value;
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;
};

/// Assumption: every node except the leaf nodes have two children.
/// 1. push root node to queue
/// 2. while (queue not empty)
///         for nodes in queue
///             print value
///             push children in queue
///             pop this node
void PrintFromTopToBottom(BinaryTreeNode *root) {
    if (root == nullptr) return;
    std::queue<BinaryTreeNode*> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()) {
        BinaryTreeNode *top = myQueue.front();
        std::cout << top->_value << std::endl;
        if (top->_left != nullptr) myQueue.push(top->_left);
        if (top->_right != nullptr) myQueue.push(top->_right);
        myQueue.pop();
    }
}
