// Minimum Platforms

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2)
Space: O(1)
*/
class SolutionBrute {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<int> vis(2400,0);
        int ans = 0;
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            int a = arr[i];
            int d = dep[i];
            
            for(int j=a; j<=d; j++)
            {
                vis[j]++;
                ans=max(ans,vis[j]);
            }
        }
        
        return ans;
    }
};

/*
Approach 2: Sort + Two Pointers (Most Used)
Time: O(n log n)
Space: O(1)
*/
class SolutionTwoPointer {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int plat = 0, ans = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat++;
                ans = max(ans, plat);
                i++;
            } else {
                plat--;
                j++;
            }
        }
        return ans;
    }
};
