// 🌳 Question: Left View of Binary Tree

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Solution class
class Solution {
public:
    vector<int> leftView(Node *root) {
        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        map<int, int> mp;
        int lev = 0;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                // Only store first (leftmost) node at each level
                if (mp.find(lev) == mp.end()) {
                    mp[lev] = node->data;
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            lev++;
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// Main function for testing
int main() {
    /*
          1
         / \
        2   3
       / \   \
      4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> res = sol.leftView(root);

    cout << "Left View: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}