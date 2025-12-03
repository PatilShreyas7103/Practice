// IPO - Maximize Capital from K Projects

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

class SolutionPriorityQueue {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> availableProfits;
        int projectIndex = 0;
        
        while (k-- > 0) {
            while (projectIndex < n && projects[projectIndex].first <= w) {
                availableProfits.push(projects[projectIndex].second);
                projectIndex++;
            }
            
            if (availableProfits.empty()) {
                break;
            }
            
            w += availableProfits.top();
            availableProfits.pop();
        }
        
        return w;
    }
};
