// Question: Find Kth Largest and Kth Smallest Elements Using Heaps

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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ==================== Kth Largest ====================
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        for (int x : v) {
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }

    // ==================== Kth Smallest ====================
    int findKthSmallest(vector<int>& v, int k) {
        priority_queue<int> pq; // max heap

        for (int x : v) {
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};