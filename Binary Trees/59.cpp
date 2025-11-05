// 🚀 Question: Check if two binary trees are isomorphic

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

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isIsomorphic(Node* root1, Node* root2) {
        // Both roots are NULL — trees are isomorphic
        if (root1 == NULL && root2 == NULL)
            return true;

        // Exactly one is NULL — not isomorphic
        if (root1 == NULL || root2 == NULL)
            return false;

        // Data doesn't match — not isomorphic
        if (root1->data != root2->data)
            return false;

        // Case 1: Subtrees not flipped
        // Case 2: Subtrees flipped
        return (isIsomorphic(root1->left, root2->left) &&
                isIsomorphic(root1->right, root2->right)) ||
               (isIsomorphic(root1->left, root2->right) &&
                isIsomorphic(root1->right, root2->left));
    }
};

// Helper function to build a simple test tree
Node* buildSampleTree1() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

Node* buildSampleTree2() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    return root;
}

int main() {
    Solution obj;

    Node* root1 = buildSampleTree1();
    Node* root2 = buildSampleTree2();

    if (obj.isIsomorphic(root1, root2))
        cout << "The trees are isomorphic 🌳✅" << endl;
    else
        cout << "The trees are not isomorphic ❌" << endl;

    return 0;
}