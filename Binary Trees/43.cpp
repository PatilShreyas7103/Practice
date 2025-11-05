// 🌳 Longest ZigZag Path in a Binary Tree — Both Approaches
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*------------------------------------------
    ✅ Optimized O(N) Solution (Postorder DFS)
-------------------------------------------*/
class SolutionOptimized {
public:
    pair<int,int> solve(TreeNode* root, int &ans)
    {
        if(!root)
        {
            return {-1,-1};
        }

        auto l = solve(root->left,ans);
        auto r = solve(root->right, ans);

        int leftans = l.second+1;
        int rightans = r.first+1;
        ans = max({ans,leftans,rightans});

        return {leftans,rightans};
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};

/*------------------------------------------
    ⚙️ Brute Force O(N²) Solution
-------------------------------------------*/
class SolutionBrute {
public:
    void fun(TreeNode* root, int dir, int &ans, int len)
    {
        if(!root)
        {
            ans = max(ans, len);
            return;
        }
        len++;
        if(dir)
        {
            fun(root->left,!dir,ans,len);
        }
        else
        {
            fun(root->right,!dir,ans,len);
        }
    }

    void solve(TreeNode* root, int &ans)
    {
        if(root==NULL)
        {
            return;
        }

        solve(root->left,ans);
        // 0 -> L, 1 -> R
        fun(root,0,ans,0);
        fun(root,1,ans,0);
        solve(root->right, ans);
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans-1;
    }
};

/*------------------------------------------
    🧪 Example Usage (for testing)
-------------------------------------------*/
int main() {
    // Construct sample tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->right->right = new TreeNode(1);

    SolutionOptimized opt;
    SolutionBrute brute;

    cout << "Optimized ZigZag Length: " << opt.longestZigZag(root) << endl;
    cout << "Brute Force ZigZag Length: " << brute.longestZigZag(root) << endl;

    return 0;
}