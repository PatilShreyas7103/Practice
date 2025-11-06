// 🧩 Question: Print all nodes at distance k from the root
// ✅ Includes both DFS (recursive) and BFS (level order) approaches

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
    // ---------- DFS / Recursive approach ----------
    void dfsHelper(Node* root, int k, int depth, vector<int> &ans) {
        if (!root) return;

        if (depth == k) {
            ans.push_back(root->data);
            return;
        }

        dfsHelper(root->left, k, depth + 1, ans);
        dfsHelper(root->right, k, depth + 1, ans);
    }

    vector<int> KdistanceDFS(Node* root, int k) {
        vector<int> ans;
        dfsHelper(root, k, 0, ans); // start depth = 0
        return ans;
    }

    // ---------- BFS / Level Order approach ----------
    vector<int> KdistanceBFS(Node* root, int k) {
        vector<int> ans;
        if (!root) return ans;

        queue<pair<Node*, int>> q; // (node, current level)
        q.push({root, 0});

        while (!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == k) {
                ans.push_back(node->data);
            }

            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }

        return ans;
    }
};

// ---------- Driver code for testing ----------
int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4  5  6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    int k = 2;

    vector<int> dfsResult = sol.KdistanceDFS(root, k);
    vector<int> bfsResult = sol.KdistanceBFS(root, k);

    cout << "Nodes at distance " << k << " (DFS): ";
    for (int val : dfsResult) cout << val << " ";
    cout << endl;

    cout << "Nodes at distance " << k << " (BFS): ";
    for (int val : bfsResult) cout << val << " ";
    cout << endl;

    return 0;
}