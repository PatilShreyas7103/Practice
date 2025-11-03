// Preorder Traversal of a Binary Tree (Recursive and Iterative Implementations)
#include <iostream>
#include <vector>
#include <stack>
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
    // Recursive implementation
    void preorderRecursive(TreeNode* root, vector<int> &v) {
        if (root == nullptr) return;
        v.push_back(root->val);
        preorderRecursive(root->left, v);
        preorderRecursive(root->right, v);
    }

    vector<int> preorderTraversalRecursive(TreeNode* root) {
        vector<int> ans;
        preorderRecursive(root, ans);
        return ans;
    }

    // Iterative implementation
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        if (root == nullptr)
            return ans;

        st.push(root);

        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            ans.push_back(t->val);

            if (t->right)
                st.push(t->right);
            if (t->left)
                st.push(t->left);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Create example binary tree:
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Test recursive implementation
    vector<int> resultRecursive = sol.preorderTraversalRecursive(root);
    cout << "Recursive Preorder Traversal: ";
    for (int val : resultRecursive) cout << val << " ";
    cout << "\n";

    // Test iterative implementation
    vector<int> resultIterative = sol.preorderTraversalIterative(root);
    cout << "Iterative Preorder Traversal: ";
    for (int val : resultIterative) cout << val << " ";
    cout << "\n";

    return 0;
}