// 🌳 590. N-ary Tree Postorder Traversal

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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // Recursive postorder traversal
    void solve(Node* root, vector<int> &v) {
        if (!root)
            return;

        // Visit all children first
        for (auto child : root->children)
            solve(child, v);

        // Then visit current node
        v.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// 🧪 Example usage
int main() {
    // Example Tree:
    //        1
    //      / | \
    //     3  2  4
    //    / \
    //   5   6
    //
    // Expected Postorder: [5, 6, 3, 2, 4, 1]

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node3, node2, node4});

    Solution sol;
    vector<int> result = sol.postorder(root);

    cout << "Postorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}