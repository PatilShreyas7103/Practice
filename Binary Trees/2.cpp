// 💡 Question: Binary Tree Inorder Traversal (Recursive and Iterative Implementations)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    void inorderRecursive(TreeNode* root, vector<int> &v) {
        if (root == nullptr) {
            return;
        }
        // LNR (Left -> Node -> Right)
        inorderRecursive(root->left, v);
        v.push_back(root->val);
        inorderRecursive(root->right, v);
    }

    vector<int> inorderTraversalRecursive(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        inorderRecursive(root, ans);
        return ans;
    }

    // Iterative implementation
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;

        while (true) {
            if (temp != nullptr) {
                st.push(temp);
                temp = temp->left;
            } else {
                if (st.empty()) break;

                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                temp = temp->right;
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Create example binary tree:
    //      1
    //       \
    //        2
    //       /
    //      3
    // Expected inorder traversal: 1 3 2
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Test recursive implementation
    vector<int> resultRecursive = sol.inorderTraversalRecursive(root);
    cout << "Recursive Inorder Traversal: ";
    for (int val : resultRecursive) cout << val << " ";
    cout << "\n";

    // Test iterative implementation
    vector<int> resultIterative = sol.inorderTraversalIterative(root);
    cout << "Iterative Inorder Traversal: ";
    for (int val : resultIterative) cout << val << " ";
    cout << "\n";

    return 0;
}