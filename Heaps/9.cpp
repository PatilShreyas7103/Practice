// Question: Divide Cards Into Groups of Size G (Hand of Straights)

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
    bool isNStraightHand(vector<int>& v, int g) {
        int n = v.size();
        if (n % g) return false;

        map<int, int> mp;
        for (auto it : v) mp[it]++;

        while (!mp.empty()) {
            int card = mp.begin()->first;

            for (int i = 0; i < g; i++) {
                if (mp[card + i] == 0) return false;
                mp[card + i]--;
                if (mp[card + i] == 0) mp.erase(card + i);
            }
        }

        return true;
    }
};