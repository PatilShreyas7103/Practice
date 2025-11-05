// 🌳 LeetCode 501: Find Mode in Binary Search Tree
// Includes both Brute Force (map-based) and Optimized (inorder traversal) approaches

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

// ------------------ Tree Definition ------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ----------------------------------------------------
// 🐢 BRUTE FORCE APPROACH — Using map<int, int>
// Time: O(n log n), Space: O(n)
class BruteForceSolution {
public:
    void inorder(TreeNode* root, map<int,int> &mp) {
        if (!root) return;
        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        inorder(root, mp);

        int maxFreq = 0;
        for (auto &it : mp)
            maxFreq = max(maxFreq, it.second);

        vector<int> ans;
        for (auto &it : mp)
            if (it.second == maxFreq)
                ans.push_back(it.first);

        return ans;
    }
};

// ----------------------------------------------------
// ⚡ OPTIMIZED APPROACH — Inorder Traversal (O(n) Time, O(1) Space)
class OptimizedSolution {
public:
    int currVal = 0, currCount = 0, maxCount = 0;
    vector<int> modes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        handleValue(root->val);
        inorder(root->right);
    }

    void handleValue(int val) {
        if (val != currVal) {
            currVal = val;
            currCount = 0;
        }
        currCount++;

        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.push_back(val);
        } 
        else if (currCount == maxCount) {
            modes.push_back(val);
        }
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};

// ----------------------------------------------------
// 🧪 MAIN FUNCTION (For Testing Both Approaches)
int main() {
    // Building sample BST: [1, null, 2, 2]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    // 🔹 Brute Force Result
    BruteForceSolution brute;
    vector<int> bruteRes = brute.findMode(root);
    cout << "Brute Force Result: ";
    for (int x : bruteRes) cout << x << " ";
    cout << endl;

    // 🔹 Optimized Result
    OptimizedSolution opt;
    vector<int> optRes = opt.findMode(root);
    cout << "Optimized Result: ";
    for (int x : optRes) cout << x << " ";
    cout << endl;

    return 0;
}