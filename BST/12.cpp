// 🌳 Question: Merge Two BSTs into a Sorted List
// ✅ Includes both approaches:
// 1️⃣ Brute Force (inorder + sort)
// 2️⃣ Optimized (inorder + two-pointer merge)

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

// -----------------------------------------------------
// Definition of BST Node
// -----------------------------------------------------
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// -----------------------------------------------------
// 🧩 Solution 1: Brute Force (Inorder + Sort)
// -----------------------------------------------------
class SolutionBruteForce {
public:
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    vector<int> merge(Node* root1, Node* root2) {
        vector<int> a;
        inorder(root1, a);
        vector<int> b;
        inorder(root2, b);

        // Combine both vectors
        for (auto it : b) a.push_back(it);

        // Sort the combined vector
        sort(a.begin(), a.end());
        return a;
    }
};

// -----------------------------------------------------
// ⚡ Solution 2: Optimized (Inorder + Two-Pointer Merge)
// -----------------------------------------------------
class SolutionOptimized {
public:
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    vector<int> merge(Node* root1, Node* root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);

        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        vector<int> ans;

        while (i < m && j < n) {
            if (a[i] < b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }

        while (i < m) ans.push_back(a[i++]);
        while (j < n) ans.push_back(b[j++]);

        return ans;
    }
};

// -----------------------------------------------------
// 🧠 Utility: Insert node into BST
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
    // Build first BST
    Node* root1 = NULL;
    vector<int> vals1 = {10, 5, 1, 7, 40, 50};
    for (int val : vals1) root1 = insert(root1, val);

    // Build second BST
    Node* root2 = NULL;
    vector<int> vals2 = {20, 15, 25, 12, 30};
    for (int val : vals2) root2 = insert(root2, val);

    SolutionBruteForce brute;
    SolutionOptimized opt;

    auto ans1 = brute.merge(root1, root2);
    auto ans2 = opt.merge(root1, root2);

    cout << "🔹 Brute Force → ";
    for (int x : ans1) cout << x << " ";
    cout << "\n";

    cout << "🔹 Optimized → ";
    for (int x : ans2) cout << x << " ";
    cout << "\n";

    return 0;
}