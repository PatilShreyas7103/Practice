// 🌳 Question: Insert into a Binary Search Tree (Iterative + Recursive)

// ✅ Full Working Code
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 🌀 Recursive Approach
TreeNode* insertIntoBSTRecursive(TreeNode* root, int k) {
    if (!root) return new TreeNode(k);

    if (k < root->val)
        root->left = insertIntoBSTRecursive(root->left, k);
    else
        root->right = insertIntoBSTRecursive(root->right, k);

    return root;
}

// ⚙️ Iterative Approach
TreeNode* insertIntoBSTIterative(TreeNode* root, int k) {
    if (!root) return new TreeNode(k);

    TreeNode* curr = root;
    TreeNode* prev = nullptr;

    while (curr) {
        prev = curr;
        if (k < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    TreeNode* newNode = new TreeNode(k);
    if (k < prev->val)
        prev->left = newNode;
    else
        prev->right = newNode;

    return root;
}

// 🔍 Helper function for inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🧠 Driver code (for testing)
int main() {
    TreeNode* root = nullptr;

    // Inserting nodes using iterative function
    root = insertIntoBSTIterative(root, 50);
    root = insertIntoBSTIterative(root, 30);
    root = insertIntoBSTIterative(root, 70);
    root = insertIntoBSTIterative(root, 20);
    root = insertIntoBSTIterative(root, 40);
    root = insertIntoBSTIterative(root, 60);
    root = insertIntoBSTIterative(root, 80);

    cout << "Inorder traversal after iterative insertion: ";
    inorder(root);
    cout << endl;

    // Inserting a node using recursive function
    root = insertIntoBSTRecursive(root, 65);
    cout << "Inorder traversal after recursive insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}