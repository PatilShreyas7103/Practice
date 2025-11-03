// ✅ Question: Construct BST from Preorder Traversal
// ✅ Includes two solutions: 
//    1. Recursive Insertion (O(n²))
//    2. Optimized Bound-Based Recursion (O(n))
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

// ----------------------------------------------
// Definition for a binary tree node
// ----------------------------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// -------------------------------------------------
// ✅ Solution 1: Recursive Insertion (O(n²))
// -------------------------------------------------
class Solution1 {
public:
    TreeNode* solve(TreeNode* root, int k) {
        if(root == NULL) {
            return new TreeNode(k);
        }
        if(k < root->val) {
            root->left = solve(root->left, k);
        } else {
            root->right = solve(root->right, k);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = NULL;
        for(int i = 0; i < pre.size(); i++) {
            root = solve(root, pre[i]);
        }
        return root;
    }
};

// -------------------------------------------------
// ✅ Solution 2: Bound-Based Recursion (O(n))
// -------------------------------------------------
class Solution2 {
public:
    TreeNode* solve(vector<int>& pre, int& idx, int n, long long mn, long long mx) {
        if(idx >= n) return NULL;
        
        if(pre[idx] > mn && pre[idx] < mx) {
            TreeNode* node = new TreeNode(pre[idx++]);
            node->left = solve(pre, idx, n, mn, node->val);
            node->right = solve(pre, idx, n, node->val, mx);
            return node;
        }
        return NULL;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        int idx = 0;
        int n = pre.size();
        return solve(pre, idx, n, LLONG_MIN, LLONG_MAX);
    }
};

// -------------------------------------------------
// 🧪 Example Usage (for VS Code testing)
// -------------------------------------------------
int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution1 s1;
    Solution2 s2;

    TreeNode* root1 = s1.bstFromPreorder(preorder);
    TreeNode* root2 = s2.bstFromPreorder(preorder);

    cout << "BST constructed successfully using both methods ✅" << endl;
    return 0;
}