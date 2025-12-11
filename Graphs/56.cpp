// Find the Town Judge
 
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

class SolutionMap {
public:
    // Approach: track in-degree and out-degree with maps/arrays
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
        for (auto &t : trust) {
            outdeg[t[0]]++;
            indeg[t[1]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (indeg[i] == n - 1 && outdeg[i] == 0) return i;
        }
        return -1;
    }
};

class SolutionCount {
public:
    // Approach: single-pass counting trick (increment trusted, decrement trusting)
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1) return 1;
        vector<int> score(n + 1, 0);
        for (auto &p : trust) {
            score[p[0]]--; // trusts someone -> lose a point
            score[p[1]]++; // is trusted -> gain a point
        }
        for (int i = 1; i <= n; ++i) {
            if (score[i] == n - 1) return i;
        }
        return -1;
    }
};