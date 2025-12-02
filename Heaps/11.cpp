// Question: Kth Largest Element in a Stream (Min-Heap Approach)

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

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k1;

    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for (int x : nums) {
            pq.push(x);
            if (pq.size() > k1) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k1) pq.pop();
        return pq.top();
    }
};