// Question: Minimum Cost to Connect Ropes (Min-Heap Approach)

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
    int minCost(vector<int>& v) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it : v) {
            pq.push(it);
        }

        int ans = 0;

        while (!pq.empty()) {
            int t1 = pq.top();
            pq.pop();

            if (pq.empty()) break;

            int t2 = pq.top();
            pq.pop();

            ans += t1 + t2;
            pq.push(t1 + t2);
        }

        return ans;
    }
};