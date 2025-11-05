// 113.  Path Sum II 
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int target, int sum, vector<int>& path, vector<vector<int>>& res) {
        if (!root) return;

        path.push_back(root->val);
        sum += root->val;

        // If it's a leaf and the sum matches target
        if (!root->left && !root->right && sum == target) {
            res.push_back(path);
        }

        // Recurse left and right
        dfs(root->left, target, sum, path, res);
        dfs(root->right, target, sum, path, res);

        // Backtrack (remove last element before returning)
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, 0, path, res);
        return res;
    }
};