// 🧩 Search in a Binary Search Tree — Recursive and Iterative Approaches

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ✅ Recursive Solution
class RecursiveSolution {
public:
    TreeNode* solve(TreeNode* root, int k) {
        if (root == nullptr)
            return nullptr;

        if (root->val == k)
            return root;
        else if (k < root->val)
            return solve(root->left, k);
        else
            return solve(root->right, k);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root, val);
    }
};

// ✅ Iterative Solution
class IterativeSolution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};

// Utility function to print result
void printResult(TreeNode* node) {
    if (node)
        cout << "Node found with value: " << node->val << endl;
    else
        cout << "Node not found." << endl;
}

// Driver code
int main() {
    /*
        Constructing the following BST:
                  8
                 / \
                3   10
               / \    \
              1   6    14
                 / \   /
                4   7 13
    */
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6, new TreeNode(4), new TreeNode(7));
    root->right->right = new TreeNode(14, new TreeNode(13), nullptr);

    int val = 6;

    cout << "🔹 Recursive Search Result:\n";
    RecursiveSolution rsol;
    printResult(rsol.searchBST(root, val));

    cout << "\n🔹 Iterative Search Result:\n";
    IterativeSolution isol;
    printResult(isol.searchBST(root, val));

    return 0;
}