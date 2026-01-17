// Make equal elements Array
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Idea:
// - Reduce array to unique elements
// - If unique count > 3 → impossible
// - Handle cases for 1, 2, and 3 unique elements by direct checking
class BruteForce {
public:
    int solve(vector<int> &v, int x) {
        unordered_set<int> st;
        for (int it : v) st.insert(it);

        int u = st.size();

        if (u > 3) return 0;
        if (u == 1) return 1;

        vector<int> k(st.begin(), st.end());

        if (u == 2) {
            int a = k[0], b = k[1];
            return (abs(a - b) == x);
        }

        sort(k.begin(), k.end());
        if (k[1] - k[0] == x && k[2] - k[1] == x)
            return 1;

        return 0;
    }
};
