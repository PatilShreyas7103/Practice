// 🌳 Build Binary Tree from Inorder and Postorder Traversal

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ✅ Solution Class
class Solution {
public:
    TreeNode* solve(vector<int> &post, int ps, int pe, vector<int> &in, int is, int ie, map<int,int> &mp) {
        if (ps > pe || is > ie)
            return NULL;

        TreeNode* node = new TreeNode(post[pe]);
        int id = mp[post[pe]];
        int l = id - is;

        node->left = solve(post, ps, ps + l - 1, in, is, id - 1, mp);
        node->right = solve(post, ps + l, pe - 1, in, id + 1, ie, mp);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(postorder, 0, n - 1, inorder, 0, n - 1, mp);
    }
};

// 🌿 Helper function to print tree inorder
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// 🌿 Helper function to print tree level-order (for verification)
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            TreeNode* cur = q.front(); q.pop();
            cout << cur->val << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
    }
}

int main() {
    // Example input
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution obj;
    TreeNode* root = obj.buildTree(inorder, postorder);

    cout << "✅ Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << "\n\n🌿 Level order traversal of constructed tree:\n";
    printLevelOrder(root);

    return 0;
}