// Construct Binary Tree from Preorder and Postorder Traversal

#include <bits/stdc++.h>
using namespace std;

/*
Definition of TreeNode
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();
        return build(0, n - 1, 0, postorder, preorder);
    }

    TreeNode* build(int preStart, int preEnd, int postStart,
                    vector<int>& post, vector<int>& pre) {

        // no elements
        if (preStart > preEnd) return NULL;

        // single node
        if (preStart == preEnd)
            return new TreeNode(pre[preStart]);

        // root is always preorder[preStart]
        TreeNode* root = new TreeNode(pre[preStart]);

        // next preorder element is left subtree root
        int leftRootVal = pre[preStart + 1];

        // find left subtree size from postorder
        int idx = postStart;
        while (post[idx] != leftRootVal) idx++;

        int leftSize = idx - postStart + 1;

        // build left subtree
        root->left = build(preStart + 1,
                           preStart + leftSize,
                           postStart,
                           post, pre);

        // build right subtree
        root->right = build(preStart + leftSize + 1,
                            preEnd,
                            postStart + leftSize,
                            post, pre);

        return root;
    }
};