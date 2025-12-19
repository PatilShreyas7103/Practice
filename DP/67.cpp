// 647. Palindromic Substrings
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
    bool check(string s)
    {
        int i = 0;
        int j = s.length()-1;

        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            string str = "";
            for(int j=i; j<n; j++)
            {
                str+=s[j];
                if(check(str))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

class TwoPointerSolution {
public:

    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int p = i;
            int q = i;
            // odd length
            while(p>=0 && q<n && s[p]==s[q])
            {
                p--;
                q++;
                ans++;
            }

            p = i;
            q=i+1;
            // even length
            while(p>=0 && q<n && s[p]==s[q])
            {
                p--;
                q++;
                ans++;
            }
        }

        return ans;
    }
};


class DP_Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {

                    dp[i][j] = true;
                    res++;
                }
            }
        }

        return res;
    }
};