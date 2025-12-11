// Island Perimeter
 
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
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    int islandPerimeter(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        int cnt = 0;

        for(int i=0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(v[i][j]==1)
                {
                    for(int k=0; k<4; k++)
                    {
                        int nr = i+dx[k];
                        int nc = j+dy[k];

                        if(isValid(nr,nc,m,n))
                        {
                            if(v[nr][nc]==0)
                            {
                                cnt++;
                            }
                        }
                        else
                        {
                            cnt++;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};