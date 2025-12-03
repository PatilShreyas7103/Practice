// Maximum Sum Combinations from Two Arrays

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

class PriorityQueueApproach {
public:
    vector<int> findKMaxSums(vector<int>& arr1, vector<int>& arr2, int k) {
        sort(arr1.rbegin(), arr1.rend());
        sort(arr2.rbegin(), arr2.rend());
        
        using SumTuple = tuple<int, int, int>;
        priority_queue<SumTuple> maxHeap;
        set<pair<int, int>> visitedPairs;
        
        maxHeap.push({arr1[0] + arr2[0], 0, 0});
        visitedPairs.insert({0, 0});
        
        vector<int> kLargestSums;
        
        while (k-- > 0 && !maxHeap.empty()) {
            auto [currentSum, idx1, idx2] = maxHeap.top();
            maxHeap.pop();
            
            kLargestSums.push_back(currentSum);
            
            if (idx1 + 1 < arr1.size() && 
                visitedPairs.find({idx1 + 1, idx2}) == visitedPairs.end()) {
                maxHeap.push({arr1[idx1 + 1] + arr2[idx2], idx1 + 1, idx2});
                visitedPairs.insert({idx1 + 1, idx2});
            }
            
            if (idx2 + 1 < arr2.size() && 
                visitedPairs.find({idx1, idx2 + 1}) == visitedPairs.end()) {
                maxHeap.push({arr1[idx1] + arr2[idx2 + 1], idx1, idx2 + 1});
                visitedPairs.insert({idx1, idx2 + 1});
            }
        }
        
        return kLargestSums;
    }
};

class BruteForceApproach {
public:
    vector<int> findKMaxSums(vector<int>& arr1, vector<int>& arr2, int k) {
        int n = arr1.size();
        vector<int> allSums;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                allSums.push_back(arr1[i] + arr2[j]);
            }
        }
        
        sort(allSums.rbegin(), allSums.rend());
        vector<int> result(allSums.begin(), allSums.begin() + min(k, (int)allSums.size()));
        
        return result;
    }
};

