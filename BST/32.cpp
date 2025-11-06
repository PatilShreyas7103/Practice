// 🌳 Convert a Binary Tree to a Binary Search Tree (BST)
// 🧠 Approach: Inorder Traversal + Sorting
#include <bits/stdc++.h>
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

// Node structure definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // 🧩 Step 1: Store inorder traversal of the binary tree in a vector
    void storeInorder(Node* root, vector<int>& inorderValues) {
        if (!root) return;
        storeInorder(root->left, inorderValues);
        inorderValues.push_back(root->data);
        storeInorder(root->right, inorderValues);
    }

    // 🧩 Step 2: Replace tree nodes' values with sorted inorder values
    void fillInorder(Node* root, vector<int>& inorderValues, int& index) {
        if (!root) return;
        fillInorder(root->left, inorderValues, index);
        root->data = inorderValues[index++];
        fillInorder(root->right, inorderValues, index);
    }

    // 🧩 Step 3: Main function to convert Binary Tree to BST
    Node* convertToBST(Node* root) {
        if (!root) return nullptr;

        // Step 1: Get inorder traversal of original tree
        vector<int> inorderValues;
        storeInorder(root, inorderValues);

        // Step 2: Sort inorder values
        sort(inorderValues.begin(), inorderValues.end());

        // Step 3: Refill sorted values into tree
        int index = 0;
        fillInorder(root, inorderValues, index);

        return root; // Tree is now a BST
    }

    // 🧩 Optional: Display inorder traversal (for testing)
    void printInorder(Node* root) {
        if (!root) return;
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
};

// 🧪 Example driver code for testing in VS Code
int main() {
    /*
            10
           /  \
          30   15
         /      \
        20       5
    */

    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    Solution sol;

    cout << "Inorder of Original Tree: ";
    sol.printInorder(root);
    cout << endl;

    root = sol.convertToBST(root);

    cout << "Inorder of Converted BST: ";
    sol.printInorder(root);
    cout << endl;

    return 0;
}