// Hotel Bookings Possible 
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (Day-by-day counting)
class BruteForce {
public:
    bool hotel(vector<int> &a, vector<int> &d, int c) {
        unordered_map<int, int> vis;
        int n = a.size();
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int day = a[i]; day <= d[i]; day++) {
                vis[day]++;
                mx = max(mx, vis[day]);
            }
        }
        return mx <= c;
    }
};

// Optimal Approach (Sorting + Two Pointers)
class Optimal {
public:
    bool hotel(vector<int> &a, vector<int> &d, int c) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());

        int i = 0, j = 0;
        int curr = 0;

        while (i < n && j < n) {
            if (a[i] <= d[j]) {
                curr++;            // guest arrives
                if (curr > c) return false;
                i++;
            } else {
                curr--;            // guest leaves
                j++;
            }
        }
        return true;
    }
};