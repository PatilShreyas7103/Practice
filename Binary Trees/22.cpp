// Question: Check for Children Sum Property

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

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

class Solution {
public:
    bool solve(Node* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }

        bool l = solve(root->left);
        bool r = solve(root->right);

        if (!l || !r) {
            return false;
        }

        int val1 = 0, val2 = 0;
        if (root->left) {
            val1 = root->left->data;
        }
        if (root->right) {
            val2 = root->right->data;
        }

        return (root->data == (val1 + val2));
    }

    int isSumProperty(Node* root) {
        if (root == nullptr) {
            return 1;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        return solve(root);
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    Solution sol;
    cout << "Does the tree satisfy the Children Sum Property? "
         << (sol.isSumProperty(root) ? "Yes" : "No") << endl;

    return 0;
}