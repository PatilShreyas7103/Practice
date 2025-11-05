// 🌳 N-ary Tree Maximum Depth (LeetCode 559)

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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int solve(Node* root) {
       if(!root)
        {
            return 0;
        }

        vector<Node*> v = root->children;
        int sz = v.size();
        int ans = 0;

        for(auto it: v)
        {
            int h = solve(it);
            ans = max(ans,h);
        }

        return ans+1;
    }

    int maxDepth(Node* root) {
        return solve(root);
    }
};

// 🧪 Example usage (You can modify for testing)
int main() {
    // Create a small N-ary tree:
    //        1
    //      / | \
    //     2  3  4
    //       / \
    //      5   6

    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node3 = new Node(3, {node5, node6});
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* root = new Node(1, {node2, node3, node4});

    Solution sol;
    cout << "Maximum Depth: " << sol.maxDepth(root) << endl;

    return 0;
}