// Assign Cookies 
#include <bits/stdc++.h>
using namespace std;

/* ===================== MEMOIZATION (Top-Down DP) ===================== */
class SolutionMemo {
private:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& student, vector<int>& cookie) {
        if (i == n || j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int skip = solve(i, j + 1, student, cookie);
        int take = 0;
        if (cookie[j] >= student[i]) {
            take = 1 + solve(i + 1, j + 1, student, cookie);
        }

        return dp[i][j] = max(skip, take);
    }

public:
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        n = student.size();
        m = cookie.size();

        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0, student, cookie);
    }
};

/* ===================== TABULATION (Bottom-Up DP) ===================== */
class SolutionTab {
public:
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        int n = student.size();
        int m = cookie.size();

        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int skip = dp[i][j + 1];
                int take = 0;
                if (cookie[j] >= student[i]) {
                    take = 1 + dp[i + 1][j + 1];
                }
                dp[i][j] = max(skip, take);
            }
        }

        return dp[0][0];
    }
};