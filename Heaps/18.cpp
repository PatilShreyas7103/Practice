// Smallest Number in Infinite Set

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

class SmallestInfiniteSetPriorityQueue {
public:
    int smallestAvailable;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> addedNumbers;

    SmallestInfiniteSetPriorityQueue() : smallestAvailable(1) {}

    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            addedNumbers.erase(smallest);
            return smallest;
        }
        return smallestAvailable++;
    }

    void addBack(int num) {
        if (num < smallestAvailable && addedNumbers.find(num) == addedNumbers.end()) {
            minHeap.push(num);
            addedNumbers.insert(num);
        }
    }
};

