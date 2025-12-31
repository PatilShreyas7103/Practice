// Successful Pairs of Spells and Potions 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n * m)
Space: O(1)
*/
class SolutionBrute {
public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {
        vector<int> ans;

        for (int s : spells) {
            int cnt = 0;
            for (int p : potions) {
                if ((long long)s * p >= success) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

/*
Approach 2: Sorting + Binary Search (Optimal)
Time: O(m log m + n log m)
Space: O(1) (excluding answer)
*/
class SolutionBinary {
public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();

        vector<int> ans;
        for (int s : spells) {
            long long need = (success + s - 1) / s; // ceil(success / s)
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            ans.push_back(m - idx);
        }
        return ans;
    }
};