// Count Good Numbers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int mod = 1000000007;

    long long myPow(long long x, long long n) {
        long long ans = 1;
        x %= mod;

        while (n > 0) {
            if (n & 1) {
                ans = (ans * x) % mod;
                n--;
            } else {
                x = (x * x) % mod;
                n >>= 1;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = (myPow(5, even) * myPow(4, odd)) % mod;
        return (int)ans;
    }
};