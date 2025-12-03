// Total Cost to Hire K Workers

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

class SolutionPriorityQueue {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int left = 0;
        int right = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> leftCandidates;
        priority_queue<int, vector<int>, greater<int>> rightCandidates;

        long long totalCost = 0;

        while (k--) {
            while (leftCandidates.size() < candidates && left <= right) {
                leftCandidates.push(costs[left++]);
            }
            while (rightCandidates.size() < candidates && left <= right) {
                rightCandidates.push(costs[right--]);
            }

            int leftCost = leftCandidates.empty() ? INT_MAX : leftCandidates.top();
            int rightCost = rightCandidates.empty() ? INT_MAX : rightCandidates.top();

            if (leftCost <= rightCost) {
                totalCost += leftCost;
                leftCandidates.pop();
            } else {
                totalCost += rightCost;
                rightCandidates.pop();
            }
        }

        return totalCost;
    }
};