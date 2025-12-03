// 658. Find K Closest Elements

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

class SolutionMaxHeap {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxHeap;
        
        for (int num : arr) {
            int dist = abs(num - x);
            maxHeap.push({dist, num});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};

class SolutionSortByDistance {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> distPairs;
        for (int num : arr) {
            distPairs.push_back({abs(num - x), num});
        }
        sort(distPairs.begin(), distPairs.end(), [](const auto& a, const auto& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(distPairs[i].second);
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
