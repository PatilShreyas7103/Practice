// Flip String
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class BruteForce {
public:
    vector<int> flip(string s) {
        int n = s.length();
        int L = 0, R = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '0') cnt++;
                else cnt--;

                if (cnt > mx) {
                    mx = cnt;
                    L = i;
                    R = j;
                }
            }
        }

        if (mx == 0) return {};
        return {L + 1, R + 1};
    }
};

// Optimal Approach (Kadane’s Algorithm)
class Optimal {
public:
    vector<int> flip(string s) {
        int n = s.length();
        int curr = 0, mx = 0;
        int start = 0;
        int L = -1, R = -1;

        for (int i = 0; i < n; i++) {
            curr += (s[i] == '0' ? 1 : -1);

            if (curr > mx) {
                mx = curr;
                L = start;
                R = i;
            }

            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
        }

        if (mx == 0) return {};
        return {L + 1, R + 1};
    }
};