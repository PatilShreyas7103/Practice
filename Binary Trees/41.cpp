// 1448. Count Good Nodes in Binary Tree

#include <iostream>
#include <vector>
#include <climits>
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

class Solution {
public:
    void solve(TreeNode* root, int &cnt, int mx) {
        if (root == NULL)
            return;

        if (root->val >= mx) {
            cnt++;
            mx = root->val;
        }

        solve(root->left, cnt, mx);
        solve(root->right, cnt, mx);
    }

    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int mx = INT_MIN;
        solve(root, cnt, mx);
        return cnt;
    }
};

// 🧠 Example usage:
int main() {
    /*
        Example tree:
              3
             / \
            1   4
           /   / \
          3   1   5
        Good nodes = 4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    cout << "Number of good nodes: " << sol.goodNodes(root) << endl;

    return 0;
}