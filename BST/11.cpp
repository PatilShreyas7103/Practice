// 🌳 Question: Find Predecessor and Successor in a BST
// ✅ Includes both:
// 1️⃣ Brute Force (using inorder traversal)
// 2️⃣ Optimized (iterative O(h) approach without extra space)

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

// -----------------------------------------------------
// Definition of BST Node
// -----------------------------------------------------
class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// -----------------------------------------------------
// 🧩 Solution 1: Brute Force (Inorder Traversal)
// -----------------------------------------------------
class SolutionBruteForce {
public:
    void inorder(vector<Node*>& v, Node* root) {
        if (!root) return;
        inorder(v, root->left);
        v.push_back(root);
        inorder(v, root->right);
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> v, ans(2, NULL);
        inorder(v, root);

        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i]->data == key) {
                if (i > 0) ans[0] = v[i - 1];      // predecessor
                if (i < n - 1) ans[1] = v[i + 1];  // successor
                break;
            }
        }
        return ans;
    }
};

// -----------------------------------------------------
// ⚡ Solution 2: Optimized Iterative (O(h), No Extra Space)
// -----------------------------------------------------
class SolutionOptimized {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* temp = root;

        // Find predecessor
        while (temp) {
            if (temp->data < key) {
                pre = temp;
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        temp = root;
        Node* suc = NULL;

        // Find successor
        while (temp) {
            if (temp->data <= key) {
                temp = temp->right;
            } else {
                suc = temp;
                temp = temp->left;
            }
        }

        return {pre, suc};
    }
};

// -----------------------------------------------------
// 🧠 Utility: Build BST from vector
// -----------------------------------------------------
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// -----------------------------------------------------
// 🧪 Driver Code (Test both approaches)
// -----------------------------------------------------
int main() {
    vector<int> values = {50, 30, 20, 40, 70, 60, 80};
    Node* root = NULL;
    for (int val : values) root = insert(root, val);

    int key = 65;

    SolutionBruteForce brute;
    SolutionOptimized opt;

    auto ans1 = brute.findPreSuc(root, key);
    auto ans2 = opt.findPreSuc(root, key);

    cout << "🔹 Brute Force → Predecessor: "
         << (ans1[0] ? to_string(ans1[0]->data) : "NULL")
         << ", Successor: "
         << (ans1[1] ? to_string(ans1[1]->data) : "NULL") << endl;

    cout << "🔹 Optimized → Predecessor: "
         << (ans2[0] ? to_string(ans2[0]->data) : "NULL")
         << ", Successor: "
         << (ans2[1] ? to_string(ans2[1]->data) : "NULL") << endl;

    return 0;
}