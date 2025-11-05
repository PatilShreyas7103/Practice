// 🌳 Find Common Nodes in Two BSTs — All 3 Approaches
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

// ======================================================
// 🧩 Definition for BST Node
// ======================================================
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// ======================================================
// 🥇 1. BRUTE FORCE APPROACH (O(n log m))
// ======================================================
class BruteForceSolution {
public:
    bool findNode(Node* root, int key) {
        if (!root) return false;
        if (key == root->data) return true;
        if (key < root->data) return findNode(root->left, key);
        return findNode(root->right, key);
    }

    void solve(Node* p, Node* q, vector<int>& ans) {
        if (!p) return;
        solve(p->left, q, ans);
        if (findNode(q, p->data)) ans.push_back(p->data);
        solve(p->right, q, ans);
    }

    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> ans;
        solve(r1, r2, ans);
        return ans;
    }
};

// ======================================================
// 🥈 2. INORDER + MERGE APPROACH (O(n + m) space)
// ======================================================
class InorderMergeSolution {
public:
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> v1, v2, ans;
        inorder(r1, v1);
        inorder(r2, v2);

        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] == v2[j]) {
                ans.push_back(v1[i]);
                i++; j++;
            } else if (v1[i] < v2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

// ======================================================
// 🥉 3. STACK-BASED OPTIMIZED APPROACH (O(h1 + h2) space)
// ======================================================
class StackOptimizedSolution {
public:
    vector<int> findCommon(Node* root1, Node* root2) {
        vector<int> res;
        if (!root1 || !root2) return res;

        stack<Node*> s1, s2;
        Node* curr1 = root1;
        Node* curr2 = root2;

        while (true) {
            // Go to leftmost node in both BSTs
            while (curr1) {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            while (curr2) {
                s2.push(curr2);
                curr2 = curr2->left;
            }

            if (s1.empty() || s2.empty()) break;

            curr1 = s1.top();
            curr2 = s2.top();

            if (curr1->data == curr2->data) {
                res.push_back(curr1->data);
                s1.pop();
                s2.pop();
                curr1 = curr1->right;
                curr2 = curr2->right;
            } else if (curr1->data < curr2->data) {
                s1.pop();
                curr1 = curr1->right;
                curr2 = nullptr;
            } else {
                s2.pop();
                curr2 = curr2->right;
                curr1 = nullptr;
            }
        }
        return res;
    }
};

// ======================================================
// 🧠 Helper Functions
// ======================================================
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

// ======================================================
// 🧪 MAIN FUNCTION — for testing all three approaches
// ======================================================
int main() {
    // Construct BST 1
    Node* r1 = nullptr;
    r1 = insertBST(r1, 5);
    r1 = insertBST(r1, 1);
    r1 = insertBST(r1, 10);
    r1 = insertBST(r1, 0);
    r1 = insertBST(r1, 4);
    r1 = insertBST(r1, 7);
    r1 = insertBST(r1, 9);

    // Construct BST 2
    Node* r2 = nullptr;
    r2 = insertBST(r2, 10);
    r2 = insertBST(r2, 7);
    r2 = insertBST(r2, 20);
    r2 = insertBST(r2, 4);
    r2 = insertBST(r2, 9);

    cout << "===== 🌿 COMMON NODES IN TWO BSTs =====" << endl;

    // 1️⃣ Brute Force
    BruteForceSolution brute;
    vector<int> bruteAns = brute.findCommon(r1, r2);
    cout << "Brute Force: ";
    printVector(bruteAns);

    // 2️⃣ Inorder + Merge
    InorderMergeSolution inorder;
    vector<int> inorderAns = inorder.findCommon(r1, r2);
    cout << "Inorder + Merge: ";
    printVector(inorderAns);

    // 3️⃣ Stack Optimized
    StackOptimizedSolution opt;
    vector<int> optAns = opt.findCommon(r1, r2);
    cout << "Stack-Based Optimized: ";
    printVector(optAns);

    return 0;
}