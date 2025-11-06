// 🌳 Populate Inorder Successor for All Nodes in a Binary Tree
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
    Node* next; // pointer to inorder successor

    Node(int x) {
        data = x;
        left = right = next = nullptr;
    }
};

class Solution {
private:
    Node* prev = nullptr; // keeps track of previously visited node in reverse inorder

    // Helper function: performs reverse inorder traversal
    void connectInorderSuccessor(Node* root) {
        if (!root) return;

        // Traverse right subtree first (reverse inorder)
        connectInorderSuccessor(root->right);

        // Set current node's next to previously visited node
        root->next = prev;

        // Update prev to current node
        prev = root;

        // Traverse left subtree
        connectInorderSuccessor(root->left);
    }

public:
    // Main function to populate the next pointers
    void populateNext(Node* root) {
        prev = nullptr; // reset before use
        connectInorderSuccessor(root);
    }

    // Utility: print inorder traversal with next pointers
    void printInorderWithNext(Node* root) {
        if (!root) return;
        printInorderWithNext(root->left);
        cout << root->data << " -> ";
        if (root->next)
            cout << root->next->data;
        else
            cout << "NULL";
        cout << endl;
        printInorderWithNext(root->right);
    }
};

// 🧪 Example driver code for testing
int main() {
    /*
            10
           /  \
          8   12
         /
        3
    */

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    Solution sol;

    cout << "Before populating inorder successor:\n";
    sol.printInorderWithNext(root);

    sol.populateNext(root);

    cout << "\nAfter populating inorder successor:\n";
    sol.printInorderWithNext(root);

    return 0;
}