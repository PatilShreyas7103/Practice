// Fibonacci Number
#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization (Top-Down DP) -------------------- */
class FibonacciMemoization {
public:
    long long solve(int n, vector<long long> &dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    long long fib(int n) {
        vector<long long> dp(n + 1, -1);
        return solve(n, dp);
    }
};

/* -------------------- Tabulation (Bottom-Up DP) -------------------- */
class FibonacciTabulation {
public:
    long long fib(int n) {
        if (n <= 1) return n;

        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/* -------------------- Space Optimized DP -------------------- */
class FibonacciSpaceOptimized {
public:
    long long fib(int n) {
        if (n <= 1) return n;

        long long prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            long long curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};