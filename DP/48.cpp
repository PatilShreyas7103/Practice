// Evaluate Boolean Expression to True

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
#define ll long long
const int mod = 1e19;

class Solution {
  public:
    int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    // If the result for this subproblem has been computed before, return it.
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    // Iterate through the expression to divide it into left and right subexpressions
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        // Recursively calculate the number of ways to make the left and right subexpressions true or false
        ll lT = f(i, ind - 1, 1, exp, dp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp, dp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp, dp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp, dp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {  // AND operator
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {  // OR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    
    // Store the result in the DP table and return it.
    return dp[i][j][isTrue] = ways;
}

// Function to start evaluating the expression
int countWays(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));  // DP table initialization
    return f(0, n - 1, 1, exp, dp);  // Start evaluation with isTrue set to true.
}
};

class Tabulation {
public:
    int countWays(string &exp) {
        int n = exp.size();
        const int mod = 1000000007;

        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(n, vector<long long>(2, 0))
        );

        for (int i = 0; i < n; i++) {
            dp[i][i][1] = (exp[i] == 'T');
            dp[i][i][0] = (exp[i] == 'F');
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i + 1; k < j; k += 2) {
                    long long lT = dp[i][k - 1][1];
                    long long lF = dp[i][k - 1][0];
                    long long rT = dp[k + 1][j][1];
                    long long rF = dp[k + 1][j][0];

                    if (exp[k] == '&') {
                        dp[i][j][1] = (dp[i][j][1] + lT * rT) % mod;
                        dp[i][j][0] = (dp[i][j][0] + lF * rT + lT * rF + lF * rF) % mod;
                    } 
                    else if (exp[k] == '|') {
                        dp[i][j][1] = (dp[i][j][1] + lT * rT + lT * rF + lF * rT) % mod;
                        dp[i][j][0] = (dp[i][j][0] + lF * rF) % mod;
                    } 
                    else {
                        dp[i][j][1] = (dp[i][j][1] + lT * rF + lF * rT) % mod;
                        dp[i][j][0] = (dp[i][j][0] + lT * rT + lF * rF) % mod;
                    }
                }
            }
        }

        return dp[0][n - 1][1];
    }
};



