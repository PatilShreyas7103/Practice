// Question: Sort a Nearly Sorted (k-Sorted) Array Using Min-Heap

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
    void nearlySorted(vector<int>& v, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;  // min heap
        int n = v.size();
        int l = 0;

        for (int i = 0; i < n; i++) {
            pq.push(v[i]);

            if (pq.size() > k) {
                v[l] = pq.top();
                pq.pop();
                l++;
            }
        }

        while (!pq.empty()) {
            v[l] = pq.top();
            pq.pop();
            l++;
        }
    }
};