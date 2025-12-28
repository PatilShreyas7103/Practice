// Kth Missing Positive Number – Three Approaches

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Using Hash Set
Time: O(n + k)
Space: O(n)
*/
class SolutionSet {
public:
    int findKthPositive(vector<int>& v, int k) {
        unordered_set<int> st(v.begin(), v.end());
        int ans = 0;

        for (int i = 1; i <= k; i++) {
            ans++;
            while (st.count(ans)) {
                ans++;
            }
        }
        return ans;
    }
};

/*
Approach 2: Two Pointer / Linear Scan
Time: O(n + k)
Space: O(1)
*/
class SolutionLinear {
public:
    int findKthPositive(vector<int>& v, int k) {
        int id = 0, num = 1, cnt = 0;
        int n = v.size();

        while (true) {
            if (id < n && v[id] == num) {
                id++;
            } else {
                cnt++;
                if (cnt == k) return num;
            }
            num++;
        }
    }
};

/*
Approach 3: Binary Search (Optimal)
Time: O(log n)
Space: O(1)
*/
class SolutionBinary {
public:
    int findKthPositive(vector<int>& v, int k) {
        int n = v.size();
        int s = 0, e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int missing = v[mid] - (mid + 1);

            if (missing < k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return e + k + 1;
    }
};