// 🌳 LeetCode 437: Path Sum III — Two Approaches (Brute Force & Optimized)
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

// --------------------- Tree Node Definition ---------------------
struct TreeNode {
    long long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// --------------------- Approach 1: Brute Force ---------------------
class Solution1 {
public:
    void fun(TreeNode* root, long long t, long long sum, long long &cnt) {
        if (root == NULL) return;

        sum += root->val;
        if (sum == t) cnt++;

        fun(root->left, t, sum, cnt);
        fun(root->right, t, sum, cnt);
    }

    void solve(TreeNode* root, long long t, long long &cnt) {
        if (root == NULL) return;

        solve(root->left, t, cnt);
        fun(root, t, 0, cnt);
        solve(root->right, t, cnt);
    }

    int pathSum(TreeNode* root, int t) {
        long long cnt = 0;
        solve(root, t, cnt);
        return cnt;
    }
};

// --------------------- Approach 2: Optimized (Prefix Sum + DFS) ---------------------
class Solution2 {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; // base case: one way to have sum = 0
        return dfs(root, 0, targetSum, prefixSumCount);
    }

    int dfs(TreeNode* node, long long currSum, int target, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;

        currSum += node->val;
        int count = 0;

        // Check if there exists a prefix sum that forms target
        if (prefixSumCount.count(currSum - target)) {
            count += prefixSumCount[currSum - target];
        }

        prefixSumCount[currSum]++;

        // Explore left and right subtrees
        count += dfs(node->left, currSum, target, prefixSumCount);
        count += dfs(node->right, currSum, target, prefixSumCount);

        // Backtrack
        prefixSumCount[currSum]--;

        return count;
    }
};

// --------------------- Example Usage ---------------------
int main() {
    /*
        Example Tree:
                10
               /  \
              5   -3
             / \    \
            3   2    11
           / \   \
          3  -2   1
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int target = 8;

    Solution1 s1;
    Solution2 s2;

    cout << "Brute Force Count: " << s1.pathSum(root, target) << endl;
    cout << "Optimized Count:   " << s2.pathSum(root, target) << endl;

    return 0;
}