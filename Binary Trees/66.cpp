// Min Distance Between Two Given Nodes of a Binary Tree

#include <bits/stdc++.h>
using namespace std;

/*
Approach (Brief):
1. Find the Lowest Common Ancestor (LCA) of nodes a and b.
2. Compute distance from LCA to node a.
3. Compute distance from LCA to node b.
4. Answer = distance(a) + distance(b).
*/

// Binary Tree Node definition
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
    // Find Lowest Common Ancestor
    Node* LCA(Node* root, int a, int b) {
        if (!root) return NULL;

        if (root->data == a || root->data == b)
            return root;

        Node* left = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);

        if (left && right) return root;
        return left ? left : right;
    }

    // Find distance from root to target node
    int distance(Node* root, int k) {
        if (!root) return -1;
        if (root->data == k) return 0;

        int left = distance(root->left, k);
        if (left != -1) return left + 1;

        int right = distance(root->right, k);
        if (right != -1) return right + 1;

        return -1;
    }

    // Main function
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);

        int d1 = distance(lca, a);
        int d2 = distance(lca, b);

        return d1 + d2;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack
*/