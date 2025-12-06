// 127. Word Ladder

#include <bits/stdc++.h>
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
    int ladderLength(string s, string e, vector<string>& w) {
        queue<pair<string,int>> q;
        q.push({s,1});
        int n = w[0].length();
        unordered_set<string> st(w.begin(), w.end());
        while(!q.empty()) {
            string t = q.front().first;
            int step = q.front().second;
            q.pop();
            if(t==e) {
                return step;
            }
            for(int i=0; i<n; i++) {
                char ch = t[i];
                for(char c='a'; c<='z'; c++) {
                    t[i]=c;
                    if(st.find(t)!=st.end()) {
                        st.erase(t);
                        q.push({t,step+1});
                    }
                }
                t[i]=ch;
            }
        }
        return 0;
    }
};
