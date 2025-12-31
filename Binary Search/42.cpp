// Find Pair with Given Difference 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2)
Space: O(1)
*/
class SolutionBrute {
public:
    bool findPair(vector<int>& v, int x) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(v[i] - v[j]) == x) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Approach 2: Hashing
Time: O(n) average
Space: O(n)
*/
class SolutionHash {
public:
    bool findPair(vector<int>& v, int x) {
        unordered_map<int,int> mp;
        for (int val : v) mp[val]++;

        for (int val : v) {
            if (x == 0) {
                if (mp[val] > 1) return true;
            } else {
                if (mp.count(val + x) || mp.count(val - x)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Approach 3: Sorting + Two Pointers (Optimal)
Time: O(n log n)
Space: O(1)
*/
class SolutionTwoPointer {
public:
    bool findPair(vector<int>& v, int x) {
        int n = v.size();
        sort(v.begin(), v.end());

        int i = 0, j = 1;
        while (i < n && j < n) {
            if (i == j) {
                j++;
                continue;
            }

            int diff = v[j] - v[i];

            if (diff == x) return true;
            else if (diff < x) j++;
            else i++;
        }
        return false;
    }
};