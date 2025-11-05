// ✅ Question: Unique Binary Search Trees (LeetCode 96)
// ✅ Approach: Dynamic Programming (Catalan Number Formula)
// ✅ Time Complexity: O(n²)
// ✅ Space Complexity: O(n)

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

class Solution {
public:
    int numTrees(int n) {
        vector<int> uniqTree(n + 1, 1);  // Base cases: 0 or 1 node -> 1 tree

        for (int nodes = 2; nodes <= n; nodes++) {
            int total = 0;
            for (int root = 1; root <= nodes; root++) {
                // left subtree = root - 1 nodes
                // right subtree = nodes - root nodes
                total += uniqTree[root - 1] * uniqTree[nodes - root];
            }
            uniqTree[nodes] = total;
        }

        return uniqTree[n];        
    }
};

// ---------------- Main Function ----------------
int main() {
    Solution sol;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Number of unique BSTs: " << sol.numTrees(n) << endl;

    /*
        Example:
        Input: 3
        Output: 5
        Explanation:
        Possible BSTs:
             1         3     3      2      1
              \       /     /      / \      \
               3     2     1      1   3      2
              /     /       \                  \
             2     1         2                  3
    */
    return 0;
}