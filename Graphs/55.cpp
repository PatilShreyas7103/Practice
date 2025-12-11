// Verifying an alien dictionary
 
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
    bool isAlienSorted(vector<string>& v, string order) {
       unordered_map<char,int> mp;
       int id = 0;
       
       for(auto ch: order)
       {
            mp[ch] = id++;
       }

       int len = v.size();
       for(int i=0; i<len-1; i++)
       {
            string a = v[i];
            string b = v[i+1];

            int n = min(a.length(), b.length());
            bool done = false;
            for(int j=0; j<n; j++)
            {
                if(a[j]!=b[j])
                {
                    done = true;
                    if(mp[a[j]]>mp[b[j]])
                    {
                        return false;
                    }
                    break;
                }
            }

            if(!done)
            {
                if(a.length()>b.length())
                {
                    return false;
                }
            }
       }

       return true;
    }
};