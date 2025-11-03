// 🌳 Question: Populating Next Right Pointers in Each Node (LeetCode 116)
// ✅ Approach: Level Order Traversal using Queue (BFS)
// ⏱️ Time: O(N) | 🧠 Space: O(N)

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

// Definition for a Node
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Solution Class
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            Node* prev = NULL;

            for (int i = 0; i < sz; i++) {
                Node* f = q.front();
                q.pop();

                if (prev) prev->next = f;
                prev = f;

                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }

            // Last node of each level should point to NULL
            prev->next = NULL;
        }

        return root;
    }
};

class Solution1 {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->left==NULL && root->right==NULL)
        {
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size();

            for(int i=0; i<sz; i++)
            {
                auto k1 = q.front();
                q.pop();

                if(i!=sz-1)
                {
                    k1->next = q.front();
                }

                if(k1->left)
                {
                    q.push(k1->left);
                }

                if(k1->right)
                {
                    q.push(k1->right);
                }
            }
        }

        return root;
    }
};

// Example usage
int main() {
    // Build a simple perfect binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    sol.connect(root);

    // Check connections for level 2
    cout << "Next of " << root->left->val << " is "
         << (root->left->next ? to_string(root->left->next->val) : "NULL") << endl;
    cout << "Next of " << root->right->val << " is "
         << (root->right->next ? to_string(root->right->next->val) : "NULL") << endl;

    return 0;
}