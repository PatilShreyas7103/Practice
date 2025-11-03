// 🔥Minimum time to Burning Tree Problem - GFG / LeetCode Style

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Binary Tree Node definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class Solution {
public:
    void solve(Node* root, map<Node*, Node*>& mp) {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            mp[root->left] = root;
            solve(root->left, mp);
        }
        if (root->right) {
            mp[root->right] = root;
            solve(root->right, mp);
        }
    }

    void findnode(Node* root, int t, Node*& target) {
        if (root == NULL) {
            return;
        }
        if (root->data == t) {
            target = root;
            return;
        }
        findnode(root->left, t, target);
        findnode(root->right, t, target);
    }

    int minTime(Node* root, int t) {
        map<Node*, Node*> mp;
        solve(root, mp);

        unordered_map<Node*, bool> vis;
        Node* target = NULL;
        findnode(root, t, target);

        if (!target) return 0;

        queue<Node*> q;
        q.push(target);
        vis[target] = true;
        int k = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool burned = false;

            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                    burned = true;
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                    burned = true;
                }

                if (mp.find(node) != mp.end() && !vis[mp[node]]) {
                    vis[mp[node]] = true;
                    q.push(mp[node]);
                    burned = true;
                }
            }

            if (burned) k++;
        }

        return k;
    }
};

// Helper function to build a sample tree
Node* buildSampleTree() {
    /*
              1
             / \
            2   3
           / \   \
          4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

// Driver Code
int main() {
    Node* root = buildSampleTree();
    Solution sol;

    int target = 2;
    cout << "Minimum time to burn tree from node " << target << " = "
         << sol.minTime(root, target) << " seconds" << endl;

    return 0;
}