//  Longest Palindromic Substring
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
    string longestPalindrome(string s) {
        int n  = s.length();
        int mx = 0;
        string ans = "";
        for(int i=0; i<n; i++)
        {
            string k = "";
            for(int j=i; j<n; j++)
            {
                k+= s[j];
                if(check(k))
                {
                    if(k.length()>mx)
                    {
                        mx = k.length();
                        ans=k;
                    }
                }
            }
        }

        return ans;
    }
};

class OptimizedSolution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;
        string res = "";

        for(int i=0; i<n; i++)
        {
            // odd length palindrome
            int l = i;
            int r = i;

            while(l>=0 && r<n && s[l]==s[r])
            {
                if(r-l+1>ans)
                {
                    ans=r-l+1;
                    res = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            
            // even length palindrome
            l = i;
            r = i+1;

            while(l>=0 && r<n && s[l]==s[r])
            {
                if(r-l+1>ans)
                {
                    ans=r-l+1;
                    res = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};