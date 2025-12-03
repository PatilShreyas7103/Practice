// Find Median from Data Stream

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

class MedianFinderPriorityQueue {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinderPriorityQueue() {}

    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

class MedianFinderBruteForce {
public:
    vector<int> data;

    MedianFinderBruteForce() {}

    void addNum(int num) {
        data.push_back(num);
    }

    double findMedian() {
        int n = data.size();
        sort(data.begin(), data.end());
        if (n % 2 == 1) {
            return data[n / 2];
        } else {
            return (data[n / 2 - 1] + data[n / 2]) / 2.0;
        }
    }
};

// Example usage:
// MedianFinderPriorityQueue* obj = new MedianFinderPriorityQueue();
// obj->addNum(num);
// double param_2 = obj->findMedian();
