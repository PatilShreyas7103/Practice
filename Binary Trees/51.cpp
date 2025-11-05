// 🌳 Question: Diagonal Traversal of a Binary Tree

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

// 🌿 Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// 🌱 Solution Class
class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            while (node) {
                // Push left child to queue
                if (node->left)
                    q.push(node->left);

                // Add current node’s data
                ans.push_back(node->data);

                // Move to the right child
                node = node->right;
            }
        }

        return ans;
    }
};

// 🌴 Driver Code
int main() {
    /*
              8
             / \
            3   10
           / \    \
          1   6    14
             / \   /
            4   7 13
    */

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    Solution obj;
    vector<int> result = obj.diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}