// K Closest Points to Origin

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

class SolutionMaxHeap {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using DistancePoint = pair<double, pair<int, int>>;
        priority_queue<DistancePoint> maxHeap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            double distance = sqrt(x * x + y * y);
            maxHeap.push({distance, {x, y}});
            
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            result.push_back({top.second.first, top.second.second});
        }
        
        return result;
    }
};

class SolutionMinHeap {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using DistancePoint = pair<double, pair<int, int>>;
        priority_queue<DistancePoint, vector<DistancePoint>, greater<DistancePoint>> minHeap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            double distance = sqrt(x * x + y * y);
            minHeap.push({distance, {x, y}});
        }

        vector<vector<int>> result;
        while (k-- > 0 && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            result.push_back({top.second.first, top.second.second});
        }
        
        return result;
    }
};
