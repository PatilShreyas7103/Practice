// 🔹 Question: Right Side View of Binary Tree (LeetCode)

// ✅ Includes
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

// ✅ Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// ✅ Solution Class
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if (root == NULL) {
            return ans;
        }

        map<int, int> mp;
        int lev = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                mp[lev] = node->val; // stores the last (rightmost) node at each level

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            lev++;
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// ✅ Example Usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}