#include <iostream>

struct BinaryTreeNode;
bool findElement(int *arr, int length, int value, int &idx);
/// TODO
void printTree(BinaryTreeNode *root);

struct BinaryTreeNode {
    int _value;
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;

    BinaryTreeNode() = default;
    explicit BinaryTreeNode(const BinaryTreeNode &other) {
        _value = other._value;
        _left = nullptr; _right = nullptr;
    }
};

BinaryTreeNode* buildTree(int *preorder, int *midorder, int length) {
    if (preorder == nullptr || midorder == nullptr || length <= 0) return nullptr;
    /// 1. find root node from preorder
    /// 2. find left sub-tree and right sub-tree
    /// 3. build tree recursively
    BinaryTreeNode *root = new BinaryTreeNode();
    root->_value = preorder[0];
    root->_left = root->_right = nullptr;
    if (length == 1) {
        // terminate
        std::cout << "root is " << root->_value << std::endl;
        std::cout << "reach bottom, terminate." << std::endl;
        return root;
    } else {
        // recursively build
        int root_idx = 0;
        findElement(midorder, length, preorder[0], root_idx);
        std::cout << "root index is: " << root_idx << std::endl;
        int *left_preorder = new int[root_idx]; int *left_midorder = new int[root_idx];
        int *right_preorder = new int[length - root_idx - 1]; int *right_midorder = new int[length - root_idx - 1];
        for (int i = 0; i < root_idx; i++) {
            left_preorder[i] = preorder[i+1];
            left_midorder[i] = midorder[i];
        }
        std::cout << "left_preorder: " << std::endl;
        for (int i = 0; i < root_idx; i++) { std::cout << left_preorder[i] << std::endl; }
        std::cout << "left_midorder: " << std::endl;
        for (int i = 0; i < root_idx; i++) { std::cout << left_midorder[i] << std::endl; }

        for (int i = 0; i < (length-root_idx-1); i++) {
            right_preorder[i] = preorder[root_idx+1+i];
            right_midorder[i] = midorder[root_idx+1+i];
        }
        std::cout << "right_preorder: " << std::endl;
        for (int i = 0; i < (length-root_idx-1); i++) { std::cout << right_preorder[i] << std::endl; }
        std::cout << "right_midorder: " << std::endl;
        for (int i = 0; i < (length-root_idx-1); i++) { std::cout << right_midorder[i] << std::endl; }

        root->_left = buildTree(left_preorder, left_midorder, root_idx);
        root->_right = buildTree(right_preorder, right_midorder, (length-root_idx-1));
        return root;
    }
}

bool findElement(int *arr, int length, int value, int &idx) {
    if (arr == nullptr) return false;
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            idx = i;
            return true;
        }
    }
    return false;
}

void printTree(BinaryTreeNode *root) {}