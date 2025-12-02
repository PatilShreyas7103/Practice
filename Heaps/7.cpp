// Question: Array Rank Transform (Sort + Map Approach)

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
    vector<int> arrayRankTransform(vector<int>& v) {
        map<int, int> mp;
        int n = v.size();

        vector<int> k = v;          // copy of original array
        sort(v.begin(), v.end());   // sort array

        int cnt = 1;
        for (int i = 0; i < n; i++) {
            if (mp.find(v[i]) == mp.end()) {
                mp[v[i]] = cnt;     // assign rank to distinct values
                cnt++;
            }
        }

        for (int i = 0; i < n; i++) {
            k[i] = mp[k[i]];        // replace with rank
        }

        return k;
    }
};