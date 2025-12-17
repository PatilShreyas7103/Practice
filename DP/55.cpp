// 152. Maximum Product Subarray

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

class BruteForceSolution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int ans = INT_MIN;

        for(int i=0; i<n; i++)
        {
            int m = 1;
            for(int j=i; j<n; j++)
            {
                m*=v[j];
                ans=max(ans, m);
            }
        }

        return ans;
    }
};

class OptimizedSolution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(); //size of array.

        int pre = 1, suff = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
            pre *= arr[i];
            suff *= arr[n - i - 1];
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};