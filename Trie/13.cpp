// Top K Frequent Words

#include <bits/stdc++.h>
using namespace std;

// Brute Force approach

class BruteForce {
public:
    vector<string> topKFrequent(vector<string>& v, int k) {
        unordered_map<string,int> mp;
        for(auto s: v)
        {
            mp[s]++;
        }

        vector<pair<int,string>> p;
        for(auto it: mp)
        {
            string s = it.first;
            int f = it.second;

            p.push_back({f,s});
        }

        sort(p.rbegin(), p.rend());

        int sz = p.size();
        for(int i=0; i<sz; i++)
        {
            for(int j=i+1; j<sz; j++)
            {
                int f1 = p[i].first;
                int f2 = p[j].first;
                string s1 = p[i].second;
                string s2 = p[j].second;

                if(f2==f1 && s1>s2)
                {
                    swap(p[i], p[j]);
                }
            }
        }

        vector<string> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(p[i].second);
        }

        return ans;
    }
};

// Heap based approach

class Solution {
public:
    struct Compare {
        bool operator()(const pair<string,int>& a,
                        const pair<string,int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (string& word : words) {
            freq[word]++;
        }

        priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            Compare
        > minHeap;

        for (auto& it : freq) {
            minHeap.push({it.first, it.second});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = minHeap.top().first;
            minHeap.pop();
        }

        return ans;
    }
};