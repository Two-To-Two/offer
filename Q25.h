/**
 * Created by Jinglei Yang on 3/10/18.
 * jinglei.yang.96@gmail.com
 * Copyright © 2018 Jinglei Yang. All rights reserved.
 */
#include <iostream>
#include <stack>

struct BinaryTreeNode {
    int _value;
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;
};

/// 1. push into stack
/// 2. check sum
/// 3. if satisfy, print
/// 4. if child not null, push
/// 5. else pop

void FindPath(BinaryTreeNode *root, int expectedSum, std::stack<BinaryTreeNode*>myStack);

void FindPath(BinaryTreeNode *root, int expectedSum) {
    std::stack<BinaryTreeNode *> myStack;
    FindPath(root, expectedSum, myStack);
}

/// Assumption: path always starts at root node
/// TODO: use vector to replace stack
void FindPath(BinaryTreeNode *root, int expectedSum, std::stack<BinaryTreeNode*>myStack) {
    if (root == nullptr) return;
    myStack.push(root);

    if (myStack.top()->_value == expectedSum) {
        // print path
        std::stack<BinaryTreeNode*> tmp = myStack;
        std::stack<int> printStack;
        while (!tmp.empty()) {
            printStack.push(tmp.top()->_value);
            tmp.pop();
        }
        while (!printStack.empty()) {
            std::cout << printStack.top() << ",";
            printStack.pop();
        }
        std::cout << std::endl;
    }

    if (myStack.top()->_left != nullptr)
        FindPath(myStack.top()->_left, expectedSum - root->_value, myStack);
    if (myStack.top()->_right != nullptr)
        FindPath(myStack.top()->_right, expectedSum - root->_value, myStack);

    myStack.pop();
    return;
}
