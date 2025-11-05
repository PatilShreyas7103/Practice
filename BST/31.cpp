// ✅ Question: Closest Nodes Queries in a Binary Search Tree (LeetCode 2476)
// ✅ Approaches Included:
// 1️⃣ Brute Force (Inorder + Binary Search)
// 2️⃣ Optimized (Direct Floor and Ceil Search in BST)
// ✅ Time Complexity:
//    - Approach 1: O(N + Q·logN)
//    - Approach 2: O(Q·logN)
// ✅ Space Complexity: O(N) for storing inorder traversal (Approach 1)

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
#include <bits/stdc++.h>
using namespace std;

// ---------- Definition for TreeNode ----------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ===========================================================
// ✅ Approach 1: Inorder Traversal + Binary Search
// ===========================================================
class BruteForceSolution {
public:
    void inorder(TreeNode* root, vector<int> &a) {
        if (!root) return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> a;
        inorder(root, a);  // store sorted inorder traversal
        int n = a.size();

        vector<vector<int>> res;

        for (int x : q) {
            // Find floor
            int s = 0, e = n - 1, floorVal = -1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (a[mid] == x) {
                    floorVal = x;
                    break;
                } else if (a[mid] < x) {
                    floorVal = a[mid];
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

            // Find ceil
            s = 0, e = n - 1;
            int ceilVal = -1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (a[mid] == x) {
                    ceilVal = x;
                    break;
                } else if (a[mid] < x) {
                    s = mid + 1;
                } else {
                    ceilVal = a[mid];
                    e = mid - 1;
                }
            }

            res.push_back({floorVal, ceilVal});
        }

        return res;
    }
};

// ===========================================================
// ✅ Approach 2: Optimized Direct Floor & Ceil Traversal
// ===========================================================
class OptimizedSolution {
public:
    int findFloor(TreeNode* root, int x) {
        int ans = -1;
        while (root) {
            if (root->val == x) return x;
            else if (root->val < x) {
                ans = root->val;
                root = root->right;
            } else root = root->left;
        }
        return ans;
    }

    int findCeil(TreeNode* root, int x) {
        int ans = -1;
        while (root) {
            if (root->val == x) return x;
            else if (root->val > x) {
                ans = root->val;
                root = root->left;
            } else root = root->right;
        }
        return ans;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<vector<int>> ans;
        for (int x : q) {
            int f = findFloor(root, x);
            int c = findCeil(root, x);
            ans.push_back({f, c});
        }
        return ans;
    }
};

// ===========================================================
// 🧪 Driver Code for VS Code Testing
// ===========================================================
int main() {
    /*
        Example BST:
                 6
                / \
               2   13
              / \  / \
             1  4 9  15
                /   \
               3     14
        Queries: [2, 5, 16]
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(15);
    root->right->right->left = new TreeNode(14);

    vector<int> queries = {2, 5, 16};

    // 🧩 Brute Force
    BruteForceSolution brute;
    auto res1 = brute.closestNodes(root, queries);
    cout << "Brute Force Result:\n";
    for (auto &v : res1) cout << "[" << v[0] << ", " << v[1] << "] ";
    cout << "\n";

    // ⚡ Optimized
    OptimizedSolution opt;
    auto res2 = opt.closestNodes(root, queries);
    cout << "Optimized Result:\n";
    for (auto &v : res2) cout << "[" << v[0] << ", " << v[1] << "] ";
    cout << "\n";

    return 0;
}