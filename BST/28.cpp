// ✅ Question: Get All Elements in Two Binary Search Trees (LeetCode 1305)
// ✅ Approach: Inorder Traversal + Merge (O(m + n) time, O(m + n) space)

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

// ---------------- TreeNode Definition ----------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---------------- Solution Class ----------------
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        vector<int> v1, v2, ans;
        inorder(r1, v1);
        inorder(r2, v2);

        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] == v2[j]) {
                ans.push_back(v1[i]);
                ans.push_back(v1[i]);                
                i++; j++;
            } else if (v1[i] < v2[j]) {
                ans.push_back(v1[i]);
                i++;
            } else {
                ans.push_back(v2[j]);
                j++;
            }
        }

        while (i < v1.size()) ans.push_back(v1[i++]);
        while (j < v2.size()) ans.push_back(v2[j++]);

        return ans;
    }
};

// ---------------- Helper: Build BST ----------------
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// ---------------- Main Function ----------------
int main() {
    // Example BST 1: [2, 1, 4]
    TreeNode* r1 = nullptr;
    r1 = insertBST(r1, 2);
    r1 = insertBST(r1, 1);
    r1 = insertBST(r1, 4);

    // Example BST 2: [1, 0, 3]
    TreeNode* r2 = nullptr;
    r2 = insertBST(r2, 1);
    r2 = insertBST(r2, 0);
    r2 = insertBST(r2, 3);

    Solution sol;
    vector<int> res = sol.getAllElements(r1, r2);

    cout << "Merged Elements: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}