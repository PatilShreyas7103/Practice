// Fractional knapsack

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Compute value/weight ratio for each item.
- Sort items by decreasing ratio.
- Take full item if possible, else take fractional part.
*/

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int cap) {
        int n = val.size();
        double ans = 0.0;

        // ratio, value, weight
        vector<pair<double, pair<int,int>>> items;

        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], {val[i], wt[i]}});
        }

        sort(items.rbegin(), items.rend());

        for (auto it : items) {
            double ratio = it.first;
            int value = it.second.first;
            int weight = it.second.second;

            if (weight <= cap) {
                ans += value;
                cap -= weight;
            } else {
                ans += ratio * cap;
                break;
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/