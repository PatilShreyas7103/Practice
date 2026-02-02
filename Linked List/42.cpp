// Convert Binary Tree to Doubly Linked List (Inorder)

#include <bits/stdc++.h>
using namespace std;

// Definition of tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* prev;   // keeps track of previously visited node

    // Reverse inorder traversal (Right -> Root -> Left)
    void solve(Node* root) {
        if (!root) return;

        solve(root->right);

        root->right = prev;
        if (prev)
            prev->left = root;

        prev = root;

        solve(root->left);
    }

    // Function to convert Binary Tree to DLL
    Node* bToDLL(Node* root) {
        if (!root) return NULL;

        prev = NULL;
        solve(root);

        // prev will point to head of DLL
        prev->left = NULL;
        return prev;
    }
};