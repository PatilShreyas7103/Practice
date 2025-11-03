// 🧠 Bottom View of Binary Tree (DFS recursive + BFS iterative implementations)

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // DFS recursive approach: track deepest node (largest row) for each column
    void dfs(Node* root, int row, int col, map<int, pair<int,int>> &mp) {
        if (!root) return;
        // update if unseen or current node is at deeper or equal level
        if (mp.find(col) == mp.end() || row >= mp[col].second) {
            mp[col] = {root->data, row};
        }
        dfs(root->left, row + 1, col - 1, mp);
        dfs(root->right, row + 1, col + 1, mp);
    }

    vector<int> bottomViewDFS(Node* root) {
        map<int, pair<int,int>> mp; // col -> {value, row}
        dfs(root, 0, 0, mp);
        vector<int> ans;
        for (auto &it : mp) ans.push_back(it.second.first);
        return ans;
    }

    // BFS (level-order) iterative approach: overwrite column with last seen node
    vector<int> bottomViewBFS(Node* root) {
        if (!root) return {};
        queue<pair<Node*, int>> q; // node, col
        q.push({root, 0});
        map<int,int> mp; // col -> last seen value

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            Node* node = p.first;
            int col = p.second;
            mp[col] = node->data; // overwrite so bottom-most (later) stays
            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }

        vector<int> ans;
        for (auto &it : mp) ans.push_back(it.second);
        return ans;
    }
};

// helper to build the sample tree used in examples
Node* buildExample() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = buildExample();
    Solution sol;

    vector<int> resDFS = sol.bottomViewDFS(root);
    cout << "Bottom View (DFS): ";
    for (int v : resDFS) cout << v << " ";
    cout << "\n";

    vector<int> resBFS = sol.bottomViewBFS(root);
    cout << "Bottom View (BFS): ";
    for (int v : resBFS) cout << v << " ";
    cout << "\n";

    return 0;
}
