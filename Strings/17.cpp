// Repeated String Match using Rabin-Karp Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int cnt = 0;
        while(repeated.length() < a.length() + b.length()){
            repeated += a;
            cnt++;
            if(repeated.find(b) != string::npos) return cnt;
        }
        return -1;
    }
};

class Solution2 {
public:
    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();

        string text = "";
        int cnt = 0;

        // Repeat until length is enough to cover b (plus overlap)
        while ((int)text.size() < n + m) {
            text += a;
            cnt++;

            if (rabinKarp(text, b)) {
                return cnt;
            }
        }
        return -1;
    }

private:
    bool rabinKarp(const string &text, const string &pattern) {
        const long long mod = 1000000007;
        const long long base = 31;

        int n = text.size();
        int m = pattern.size();
        if (m > n) return false;

        long long hashP = 0, hashT = 0, power = 1;

        // Compute base^(m-1)
        for (int i = 0; i < m - 1; i++) {
            power = (power * base) % mod;
        }

        // Initial hash
        for (int i = 0; i < m; i++) {
            hashP = (hashP * base + pattern[i]) % mod;
            hashT = (hashT * base + text[i]) % mod;
        }

        // Sliding window
        for (int i = 0; i <= n - m; i++) {
            if (hashP == hashT) {
                // Verify to avoid collision
                if (text.substr(i, m) == pattern)
                    return true;
            }

            if (i < n - m) {
                hashT = (hashT - text[i] * power) % mod;
                if (hashT < 0) hashT += mod;
                hashT = (hashT * base + text[i + m]) % mod;
            }
        }

        return false;
    }
};