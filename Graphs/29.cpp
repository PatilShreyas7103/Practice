//  Minimum Multiplications to reach End

 
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
typedef pair<int,int> pi;
class Solution {
  public:
    int minimumMultiplications(vector<int>& v, int s, int e) {
        // code here
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int n = v.size();
        pq.push({0,s});
        int mod = 100000 ;
        vector<int> vis(mod+1,0);
        
        while(!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            
            int st = f.first;
            int res = f.second;
            
            if(res==e)
            {
                return st;
            }
            
            for(int i=0; i<n; i++)
            {
                int ans  = (res*v[i])%mod;
                if(vis[ans]==1)
                {
                    continue;
                }
                else
                {
                    pq.push({st+1,ans});
                    vis[ans] = 1;
                }
                
            }
        }
        
        return -1;

    }
};