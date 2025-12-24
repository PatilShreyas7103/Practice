// 139. Word Break

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

class Memoization {
public: 
    bool solve(int i, int n, string &s, set<string> &st, vector<int> &dp)
    {
        if(i==n)
        {
            return true;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        for(int j=i; j<n; j++)
        {
            string k = s.substr(i,j-i+1);
            if(st.find(k)!=st.end())
            {
                bool h = solve(j+1,n,s,st,dp);
                if(h)
                {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] =  false;
    }
    bool wordBreak(string s, vector<string>& w) {
        int n = s.length();
        set<string> st;
        for(auto it: w)
        {
            st.insert(it);
        }
        vector<int> dp(n,-1);
        return solve(0,n,s,st,dp);
    }
};

class Tabulation {
public: 
    
    bool wordBreak(string s, vector<string>& w) {
        int n = s.length();
        set<string> st;
        for(auto it: w)
        {
            st.insert(it);
        }
        vector<int> dp(n+1,0);
        dp[n] = 1;

        for(int i=n-1; i>=0; i--)
        {
            bool f = false;
            for(int j=i; j<n; j++)
            {
                string k = s.substr(i,j-i+1);
                if(st.find(k)!=st.end())
                {
                    bool h = dp[j+1];
                    f = f | h;
                }
            }
            dp[i] = f;
        }

        return dp[0];
    }
};

// Approach : Using Trie + DP
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        Trie trie;
        for (const string& word : wordDict) {
            trie.insert(word);
        }

        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            TrieNode* node = trie.root;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!node->children[idx]) {
                    break;
                }

                node = node->children[idx];
                if (node->isEnd && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};