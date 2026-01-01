// Count of Smaller Numbers After Self 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2)
Space: O(1)
*/
class SolutionBrute {
public:
    vector<int> countSmaller(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[j] < v[i]) ans[i]++;
            }
        }
        return ans;
    }
};

/*
Approach 2: Sorted Array + Binary Search
Time: O(n^2) worst case
Space: O(n)
*/
class SolutionBinaryInsert {
public:
    vector<int> countSmaller(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, 0);
        vector<int> sorted;

        for (int i = n - 1; i >= 0; i--) {
            int cnt = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
            ans[i] = cnt;
            sorted.insert(sorted.begin() + cnt, v[i]);
        }
        return ans;
    }
};
