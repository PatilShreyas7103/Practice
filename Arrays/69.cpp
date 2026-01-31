// Find the Difference of Two Arrays

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 (Using Set):
- Store unique elements using sets.
- Compare both sets to find unique elements.
*/

class SetApproach {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
        set<int> s1(a.begin(), a.end());
        set<int> s2(b.begin(), b.end());

        vector<int> v1, v2;

        for (int x : s1) {
            if (s2.find(x) == s2.end()) {
                v1.push_back(x);
            }
        }

        for (int x : s2) {
            if (s1.find(x) == s1.end()) {
                v2.push_back(x);
            }
        }

        return {v1, v2};
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
/*
Approach 2 (Using Map):
- Mark elements of one array in map.
- Remove common elements using second array.
- Remaining keys are unique.
*/

class MapApproach {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
        map<int, int> mp;

        for (int x : a) {
            mp[x] = 1;
        }
        for (int x : b) {
            if (mp.count(x)) {
                mp.erase(x);
            }
        }

        vector<int> ans1;
        for (auto it : mp) {
            ans1.push_back(it.first);
        }

        mp.clear();

        for (int x : b) {
            mp[x] = 1;
        }
        for (int x : a) {
            if (mp.count(x)) {
                mp.erase(x);
            }
        }

        vector<int> ans2;
        for (auto it : mp) {
            ans2.push_back(it.first);
        }

        return {ans1, ans2};
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/