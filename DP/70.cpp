// 343. Integer Break
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
    int integerBreak(int num) {
        long long ans = -1;

            for(long long k=2; k<=num; k++)
            {
                if(num%k==0)
                {
                    // perfect divisible
                    long long x = num/k;
                    ans=max(ans,(long long)pow(x,k));
                }
                else
                {
                    // not divisible
                    long long x1 = num/k; //k-1
                    long long x2 = num/k + num%k; // 1
                    ans = max(ans, (long long)pow(x1,k-1)*x2);

                    long long x3 = (num+k-1)/k; //k-1
                    long long x4 = num-x3*(k-1); // 1
                    ans = max(ans, (long long)pow(x3,k-1)*x4);
                }
            }
        


        return ans;
    }
};