// ✅ Question: Maximum Sum BST in Binary Tree (LeetCode 1373)
// ✅ Approach: DFS + Postorder traversal (O(N) time, O(H) space)

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
    struct NodeInfo {
        bool isBST;
        int minVal, maxVal, sum;
    };

    NodeInfo dfs(TreeNode* root, int &maxSum) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};

        NodeInfo left = dfs(root->left, maxSum);
        NodeInfo right = dfs(root->right, maxSum);

        // Check if subtree rooted at 'root' is BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            return {true, min(root->val, left.minVal), max(root->val, right.maxVal), currSum};
        }

        // Not a BST
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        dfs(root, maxSum);
        return maxSum;
    }
};

// ---------------- Helper: Build Tree ----------------
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// ---------------- Main Function ----------------
int main() {
    /*
        Example Tree:
              1
             / \
            4   3
           / \ / \
          2  4 2  5
               \
                4
        Expected Output: 20
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    Solution sol;
    cout << "Maximum Sum BST: " << sol.maxSumBST(root) << endl;

    return 0;
}