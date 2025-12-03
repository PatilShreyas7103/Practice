// Last Stone Weight

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
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        
        while (maxHeap.size() > 1) {
            int firstStone = maxHeap.top();
            maxHeap.pop();
            int secondStone = maxHeap.top();
            maxHeap.pop();
            
            if (firstStone != secondStone) {
                maxHeap.push(firstStone - secondStone);
            }
        }
        
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};