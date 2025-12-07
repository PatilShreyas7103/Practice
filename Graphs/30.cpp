// Bellman Ford Algorithm
 
 
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
class Solution {
  public:

    vector<int> bellmanFord(int v, vector<vector<int>>& e, int s) {
        vector<int> dis(v, 1e8);
        dis[s] = 0;
        for(int i=0; i<v-1; i++)
        {
            for(auto it: e)
            {
                int a = it[0];
                int b = it[1];
                int wt = it[2];
                
                if(dis[a]!=1e8 && dis[a] + wt< dis[b])
                {
                    dis[b] = dis[a] + wt;
                }
            }
        }
        for(auto it: e)
        {
            int a = it[0];
            int b = it[1];
            int wt = it[2];
            
            if(dis[a]!=1e8 && dis[a] + wt< dis[b])
            {
                return {-1};
            }
        }
        
        return dis;
        
    }
};


