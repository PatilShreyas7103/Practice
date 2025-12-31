// Time Based Key-Value Store

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        auto &v = mp[key];  // IMPORTANT: reference, not copy
        int s = 0, e = v.size() - 1;
        string ans = "";

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (v[mid].second <= timestamp) {
                ans = v[mid].first;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};