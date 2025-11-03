// Question: Find maximum and minimum element in a BST

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
#include <utility>
#include <iterator>
#include <sstream>
#include <tuple>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

// Definition for a binary tree node (BST)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value node in a BST
TreeNode* findMax(TreeNode* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Example usage
int main() {
    // Creating a simple BST
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    TreeNode* minNode = findMin(root);
    TreeNode* maxNode = findMax(root);

    cout << "Minimum value in BST: " << (minNode ? minNode->val : -1) << endl;
    cout << "Maximum value in BST: " << (maxNode ? maxNode->val : -1) << endl;

    return 0;
}