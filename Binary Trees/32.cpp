// Flatten Binary Tree to Linked List - 3 approaches in one file
// - Reverse Preorder (recursive)
// - Iterative (stack)
// - Morris Traversal (O(1) space)

#include <iostream>
using namespace std;

// Shared TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// Approach 1: Reverse Preorder (recursive)
class ReversePreorderSolution {
public:
    void flatten(TreeNode* root) {
        prev = nullptr;
        solve(root);
    }
private:
    TreeNode* prev;
    void solve(TreeNode* node) {
        if (!node) return;
        solve(node->right);
        solve(node->left);
        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
};

// Approach 2: Iterative using stack
#include <stack>
class IterativeStackSolution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            if (!st.empty()) node->right = st.top();
            node->left = nullptr;
        }
    }
};

// Approach 3: Morris-style O(1) space
class MorrisSolution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                while (prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

// Helper: build sample tree used in the originals
TreeNode* buildSample() {
    // Tree:
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}

// Helper: print flattened list (right pointers)
void printFlattened(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        cout << cur->val;
        if (cur->right) cout << " ";
        cur = cur->right;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Reverse Preorder
    {
        TreeNode* root = buildSample();
        ReversePreorderSolution sol;
        sol.flatten(root);
        cout << "Reverse Preorder Flattened: ";
        printFlattened(root);
    }

    // Iterative Stack
    {
        TreeNode* root = buildSample();
        IterativeStackSolution sol;
        sol.flatten(root);
        cout << "Iterative Stack Flattened:   ";
        printFlattened(root);
    }

    // Morris Traversal
    {
        TreeNode* root = buildSample();
        MorrisSolution sol;
        sol.flatten(root);
        cout << "Morris Flattened:           ";
        printFlattened(root);
    }

    return 0;
}
