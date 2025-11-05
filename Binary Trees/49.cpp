// 🚀 Question: Given a binary tree, find its reverse level order traversal.

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

// Binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// 🌳 Function to return reverse level order traversal of a tree
vector<int> reverseLevelOrder(Node *root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        ans.push_back(curr->data);

        // Push right before left (so that left comes first when reversed)
        if (curr->right)
            q.push(curr->right);
        if (curr->left)
            q.push(curr->left);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// 🧠 Driver code
int main() {
    /*
        Example Tree:
               1
             /   \
            2     3
           / \   / \
          4  5  6  7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = reverseLevelOrder(root);

    cout << "Reverse Level Order Traversal: ";
    for (int val : result)
        cout << val << " ";

    cout << endl;
    return 0;
}