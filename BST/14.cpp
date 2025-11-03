// ✅ Question: Two Sum in BST (Both Brute Force and Optimized Using BST Iterator)

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

// -----------------------------
// Definition of TreeNode
// -----------------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// -----------------------------
// ✅ Brute Force Solution
// -----------------------------
class BruteForceSolution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int i = 0, j = v.size() - 1;

        while (i < j) {
            int sum = v[i] + v[j];
            if (sum == k) return true;
            else if (sum > k) j--;
            else i++;
        }
        return false;
    }
};

// -----------------------------
// ✅ Optimized Solution using BST Iterator (O(n) time, O(h) space)
// -----------------------------
class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse; // false = inorder, true = reverse inorder

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
};

class OptimizedSolution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false); // ascending order
        BSTIterator r(root, true);  // descending order

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) {
                if (l.hasNext()) i = l.next();
                else break;
            } else {
                if (r.hasNext()) j = r.next();
                else break;
            }
        }
        return false;
    }
};

// -----------------------------
// Helper Function to print tree inorder
// -----------------------------
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// -----------------------------
// Main Function
// -----------------------------
int main() {
    // Construct a sample BST
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

    cout << "BST (Inorder): ";
    printInOrder(root);
    cout << endl;

    int target = 22;

    // ✅ Test Brute Force Solution
    BruteForceSolution brute;
    cout << "\nBrute Force Result: ";
    cout << (brute.findTarget(root, target) ? "Pair Found ✅" : "Pair Not Found ❌") << endl;

    // ✅ Test Optimized Solution
    OptimizedSolution opt;
    cout << "Optimized Result: ";
    cout << (opt.findTarget(root, target) ? "Pair Found ✅" : "Pair Not Found ❌") << endl;

    return 0;
}