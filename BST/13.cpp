// ✅ Question: BST Iterator - Inorder Traversal Based

#include <bits/stdc++.h>
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushall(TreeNode* root) {
        while (root) {           // keep going left
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushall(temp->right);    // push all left nodes from right child
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

// ✅ Simple test in VS Code
int main() {
    /*
         7
        / \
       3   15
          /  \
         9    20
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);

    cout << "BST Inorder Traversal using Iterator: ";
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}