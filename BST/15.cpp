// ✅ Recover Binary Search Tree - Brute Force & Optimized Solutions

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------
// Definition for a binary tree node
// -----------------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// -----------------------------
// ✅ 1. Brute Force Solution (O(n) space)
// -----------------------------
class BruteForceSolution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);

        TreeNode* p = nullptr;
        TreeNode* q = nullptr;

        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            if (v[i]->val > v[i + 1]->val) {
                if (!p) p = v[i];
                q = v[i + 1];
            }
        }

        if (p && q) {
            int temp = p->val;
            p->val = q->val;
            q->val = temp;
        }
    }
};

// -----------------------------
// ✅ 2. Optimized Solution (O(1) space using inorder pointers)
// -----------------------------
class OptimizedSolution {
private:
    TreeNode* prev = nullptr;

    void solve(TreeNode* root, TreeNode*& p, TreeNode*& q) {
        if (!root) return;

        solve(root->left, p, q);

        if (prev && root->val < prev->val) {
            if (!p) p = prev;
            q = root;
        }
        prev = root;

        solve(root->right, p, q);
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode* p = nullptr;
        TreeNode* q = nullptr;
        solve(root, p, q);

        if (p && q) {
            int temp = p->val;
            p->val = q->val;
            q->val = temp;
        }
    }
};

// -----------------------------
// Helper: Inorder print to verify correction
// -----------------------------
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// -----------------------------
// Main Function
// -----------------------------
int main() {
    /*
        Construct BST with swapped nodes:
            3
           / \
          1   4
             /
            2
        (Here, nodes 2 and 3 are swapped)
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before Recovery (Inorder): ";
    printInorder(root);
    cout << endl;

    // ✅ Brute Force
    BruteForceSolution brute;
    brute.recoverTree(root);

    cout << "After Brute Force Recovery: ";
    printInorder(root);
    cout << endl;

    // Swap again to test Optimized version
    int temp = root->val;
    root->val = root->right->left->val;
    root->right->left->val = temp;

    cout << "\nAfter Re-swapping (Before Optimized Recovery): ";
    printInorder(root);
    cout << endl;

    // ✅ Optimized
    OptimizedSolution opt;
    opt.recoverTree(root);

    cout << "After Optimized Recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}