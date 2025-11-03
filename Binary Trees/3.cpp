// 💡 Question: Binary Tree Postorder Traversal (Recursive and Iterative Implementations)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    // Recursive implementation (LRN: Left -> Right -> Node)
    void postorderRecursive(TreeNode* root, vector<int> &v) {
        if (root == nullptr) return;

        postorderRecursive(root->left, v);   // Left subtree
        postorderRecursive(root->right, v);  // Right subtree
        v.push_back(root->val);              // Node
    }

    vector<int> postorderTraversalRecursive(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        postorderRecursive(root, ans);
        return ans;
    }

    // Iterative implementation using stack and reverse
    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        // Using stack and reverse approach
        // 1. Push root
        // 2. Push left
        // 3. Push right
        // 4. Reverse the result
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            ans.push_back(t->val);

            // Push left first, then right
            // (After reverse, right will be processed before left)
            if (t->left) st.push(t->left);
            if (t->right) st.push(t->right);
        }

        // Reverse to get postorder (LRN) from (NRL)
        reverse(ans.begin(), ans.end());
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
    // Expected postorder traversal: 3 2 1
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Test recursive implementation
    vector<int> resultRecursive = sol.postorderTraversalRecursive(root);
    cout << "Recursive Postorder Traversal: ";
    for (int val : resultRecursive) cout << val << " ";
    cout << "\n";

    // Test iterative implementation
    vector<int> resultIterative = sol.postorderTraversalIterative(root);
    cout << "Iterative Postorder Traversal: ";
    for (int val : resultIterative) cout << val << " ";
    cout << "\n";

    return 0;
}