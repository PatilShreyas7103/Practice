// 🧩 Find All Cousins of a Given Node in a Binary Tree

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> findCousins(TreeNode* root, int B) {
    if (!root || root->val == B) return {}; // root can't have cousins

    queue<TreeNode*> q;
    q.push(root);
    bool found = false;
    vector<int> ans;

    while (!q.empty()) {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            auto node = q.front();
            q.pop();

            // Check if node's children contain B
            if ((node->left && node->left->val == B) ||
                (node->right && node->right->val == B)) {
                found = true;
                // skip pushing this node's children — they are siblings
                continue;
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (found) break; // next level nodes (in queue) are cousins
    }

    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
}

// 🧪 Example usage
int main() {
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
         /
        8

    Cousins of 8 → [6, 7]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);

    int B = 8;
    vector<int> res = findCousins(root, B);

    if (res.empty())
        cout << "No cousins found\n";
    else {
        cout << "Cousins of " << B << ": ";
        for (int x : res) cout << x << " ";
        cout << endl;
    }

    return 0;
}