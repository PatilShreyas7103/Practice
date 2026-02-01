// BST with Dead End

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- In a BST, every node lies in a valid range (low, high).
- Root starts with range [1, +∞] because all values > 0.
- For each node:
  - Left subtree → range [low, node->val - 1]
  - Right subtree → range [node->val + 1, high]
- If at any leaf node, low == high → no new value can be inserted → dead end.
*/

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    bool solve(Node* root, int low, int high) {
        if (!root) return false;

        // Dead end condition
        if (low == high) return true;

        return solve(root->left, low, root->data - 1) ||
               solve(root->right, root->data + 1, high);
    }

    bool isDeadEnd(Node *root) {
        return solve(root, 1, INT_MAX);
    }
};

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);

    Solution sol;
    cout << sol.isDeadEnd(root) << endl;  // Expected: 1 (true)

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack, h = height of BST
*/