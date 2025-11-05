// 🚀 Question: Check if a Binary Tree is a Sum Tree

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

// 🌳 Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// 🧠 Solution class
class Solution {
public:
    // Helper function that returns {isSumTree, subtreeSum}
    pair<bool, int> solve(Node* root) {
        if (!root)
            return {true, 0};

        if (!root->left && !root->right)
            return {true, root->data};

        auto l = solve(root->left);
        auto r = solve(root->right);

        bool f = l.first && r.first && (root->data == (l.second + r.second));

        if (f)
            return {true, root->data + l.second + r.second};
        else
            return {false, -1};
    }

    bool isSumTree(Node* root) {
        auto ans = solve(root);
        return ans.first;
    }
};

// 🌲 Helper function to build a sample tree
Node* buildSampleTree() {
    /*
           26
          /  \
         10   3
        / \    \
       4   6    3

    Sum Tree Explanation:
    4 + 6 = 10 ✅
    3 = 3 ✅
    10 + 3 = 13 → 26? ❌
    Actually, full tree sum = (4+6+3) = 13 != 26 ❌
    So this tree is *NOT* a Sum Tree.
    */
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    return root;
}

// 🧾 Driver code
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    Node* root = buildSampleTree();

    if (sol.isSumTree(root))
        cout << "✅ The tree is a Sum Tree\n";
    else
        cout << "❌ The tree is NOT a Sum Tree\n";

    return 0;
}