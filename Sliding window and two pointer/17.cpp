// Contains Duplicate II
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Try all pairs (i, j)
// - Check if nums[i] == nums[j] and |i - j| <= k
class BruteForce {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        int n = v.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n && j - i <= k; j++) {
                if (v[i] == v[j])
                    return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n*k)
Space Complexity: O(1)
*/

/*------------------------------------------------------*/
// Approach 2: Hash Map (Index Tracking) ✅ BEST
// Idea:
// - Store last index of each value
// - If same value appears again within distance k → true
class MapApproach {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < v.size(); i++) {
            if (mp.count(v[i]) && i - mp[v[i]] <= k)
                return true;

            mp[v[i]] = i;
        }
        return false;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 3: Sliding Window + Set (Correct Sliding Window)
// Idea:
// - Maintain a window of size at most k
// - Use set to detect duplicates in the window
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        unordered_set<int> st;
        int l = 0;

        for (int r = 0; r < v.size(); r++) {
            if (st.count(v[r]))
                return true;

            st.insert(v[r]);

            if (r - l == k) {
                st.erase(v[l]);
                l++;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/