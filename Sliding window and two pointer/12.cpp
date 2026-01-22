// Max Number of K-Sum Pairs
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Brute Force
// Idea:
// - Try all pairs (i, j)
// - If v[i] + v[j] == k and both unused, count it
// - Mark elements as used
// NOTE: Too slow for large input
class BruteForce {
public:
    int maxOperations(vector<int>& v, int k) {
        int n = v.size();
        vector<bool> used(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (!used[j] && v[i] + v[j] == k) {
                    used[i] = used[j] = true;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 2: Hash Map (Frequency Counting)
// Idea:
// - Count frequency of each number
// - For each number x, pair it with (k - x)
// - Add min(freq[x], freq[k-x])
// - Handle special case when x == k-x
class HashMapApproach {
public:
    int maxOperations(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        for (int x : v)
            mp[x]++;

        int ans = 0;
        for (auto &it : mp) {
            int x = it.first;
            int y = k - x;

            if (!mp.count(x)) continue;

            if (x == y) {
                ans += mp[x] / 2;
                mp[x] = 0;
            } else if (mp.count(y)) {
                int pairs = min(mp[x], mp[y]);
                ans += pairs;
                mp[x] = mp[y] = 0;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 3: Sorting + Two Pointers (Optimal & Cleanest)
// Idea:
// - Sort the array
// - Use two pointers i (smallest) and j (largest)
// - If sum == k → count++, move both pointers
// - If sum > k → decrease j
// - If sum < k → increase i
class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int i = 0, j = v.size() - 1;
        int ans = 0;

        while (i < j) {
            int sum = v[i] + v[j];
            if (sum == k) {
                ans++;
                i++;
                j--;
            } else if (sum > k) {
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/