// 841. Keys and Rooms
 
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

class SolutionBFS {
public:
    bool canVisitAllRooms(vector<vector<int>>& v) {
        queue<int> q;
        q.push(0);
        int n = v.size();

        vector<int> vis(n,0);
        vis[0] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: v[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        for(auto it: vis)
        {
            if(it==0)
            {
                return false;
            }
        }

        return true;
    }
};