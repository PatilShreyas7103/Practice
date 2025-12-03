// 373. Find K Pairs with Smallest Sums

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

typedef pair<int, pair<int, int>> pi;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        vector<vector<int>> ans;
        int m = a.size();
        int n = b.size();
        if (a.empty() || b.empty() || k == 0) return ans;

        // Min-heap using default greater<pi>
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        // push first column pairs (a[i] + b[0])
        for (int i = 0; i < min(m, k); ++i) {
            pq.push({a[i] + b[0], {i, 0}});
        }

        while (k-- && !pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int sum = t.first;
            int i = t.second.first;
            int j = t.second.second;

            ans.push_back({a[i], b[j]});

            if (j + 1 < b.size()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};