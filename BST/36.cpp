// Construct BST from Preorder Traversal

#include <bits/stdc++.h>
using namespace std;

// Definition of BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Helper function to build BST using preorder traversal
    Node* buildBST(int &idx, vector<int>& pre, int low, int high) {
        if (idx >= pre.size())
            return NULL;

        int val = pre[idx];

        if (val <= low || val >= high)
            return NULL;

        Node* root = new Node(val);
        idx++;

        root->left = buildBST(idx, pre, low, val);
        root->right = buildBST(idx, pre, val, high);

        return root;
    }

    // Main function
    Node* Bst(vector<int>& preorder) {
        int idx = 0;
        return buildBST(idx, preorder, INT_MIN, INT_MAX);
    }
};

// -------- Optional Main for Local Testing --------
int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution sol;
    Node* root = sol.Bst(preorder);

    cout << "BST constructed successfully!" << endl;
    return 0;
}