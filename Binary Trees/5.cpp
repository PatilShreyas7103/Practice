// 🔹 Question: Preorder, Inorder, and Postorder Traversal in One Iteration

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Solution class containing traversal function
class Solution {
public:
    // Function to get Preorder, Inorder, and Postorder traversals
    vector<vector<int>> preInPostTraversal(Node* root) {
        // Vectors to store the three traversals
        vector<int> pre, in, post;

        // Handle empty tree
        if (root == nullptr)
            return {};

        // Stack to maintain nodes and their traversal state
        stack<pair<Node*, int>> st;
        st.push({root, 1}); // 1 → Preorder, 2 → Inorder, 3 → Postorder

        while (!st.empty()) {
            auto [node, state] = st.top();
            st.pop();

            if (state == 1) {
                // Preorder: Node → Left → Right
                pre.push_back(node->data);
                st.push({node, 2}); // Move to next state (Inorder)

                if (node->left)
                    st.push({node->left, 1});

            } else if (state == 2) {
                // Inorder: Left → Node → Right
                in.push_back(node->data);
                st.push({node, 3}); // Move to next state (Postorder)

                if (node->right)
                    st.push({node->right, 1});

            } else {
                // Postorder: Left → Right → Node
                post.push_back(node->data);
            }
        }

        // Return all three traversals
        return {pre, in, post};
    }
};

// Main function
int main() {
    // Creating a sample binary tree
    /*
             1
            / \
           2   3
          / \
         4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Create object of Solution class
    Solution sol;

    // Get traversals
    vector<vector<int>> traversals = sol.preInPostTraversal(root);
    vector<int> pre = traversals[0];
    vector<int> in = traversals[1];
    vector<int> post = traversals[2];

    // Print results
    cout << "Preorder traversal: ";
    for (int val : pre) cout << val << " ";
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) cout << val << " ";
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) cout << val << " ";
    cout << endl;

    return 0;
}