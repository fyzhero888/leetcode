// find_deepest_node_binarytree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find_max_depth(TreeNode* root, int depth) {
    
    if (!root) {
        return depth;
    }

    ++depth;

    // find left depth
    int left_depth = find_max_depth(root->left, depth);

    // find right depth
    int right_depth = find_max_depth(root->right, depth);


    return left_depth > right_depth ? left_depth : right_depth;
}

int maxDepth(TreeNode* root) {
    int depth = 0;

    return find_max_depth(root, depth);
}

int main()
{
    std::cout << "Hello World!\n";
}


