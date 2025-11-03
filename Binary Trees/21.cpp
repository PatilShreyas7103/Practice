// Question: Width of Binary Tree

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        unsigned long long ans = 0;

        while (!q.empty()) {
            unsigned long long sz = q.size();
            unsigned long long mn = -1, mx = -1;

            for (int i = 0; i < sz; i++) {
                auto id = q.front();
                q.pop();

                if (mn == -1) {
                    mn = id.second;
                }
                mx = id.second;

                TreeNode* node = id.first;
                unsigned long long key = id.second;

                if (node->left) {
                    q.push({node->left, key * 2});
                }
                if (node->right) {
                    q.push({node->right, key * 2 + 1});
                }
            }
            ans = max(ans, mx - mn + 1);
        }

        return ans;
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << "Maximum width of binary tree: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}