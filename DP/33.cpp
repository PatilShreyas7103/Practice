// Best Time to Buy and Sell Stock (LeetCode 121)

#include <bits/stdc++.h>
using namespace std;

/* ===================== APPROACH 1: BRUTE FORCE ===================== */
class SolutionBruteForce {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                profit = max(profit, prices[j] - prices[i]);
            }
        }

        return profit;
    }
};

/* ===================== APPROACH 2: PREFIX MIN + SUFFIX MAX ===================== */
class SolutionPrefixSuffix {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> mn(n), mx(n);

        mn[0] = prices[0];
        for (int i = 1; i < n; i++) {
            mn[i] = min(mn[i - 1], prices[i]);
        }

        mx[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = max(mx[i + 1], prices[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, mx[i] - mn[i]);
        }

        return ans;
    }
};

/* ===================== APPROACH 3: OPTIMAL SINGLE PASS ===================== */
class SolutionOptimal {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int buy = prices[0];
        int ans = 0;

        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - buy);
            buy = min(buy, prices[i]);
        }

        return ans;
    }
};