// Decode ways
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

class MemoizationSolution {
public:
    int solve(int i, int n, string &s, vector<int> &dp) {
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        int one = solve(i + 1, n, s, dp);
        int two = 0;

        if (i + 1 < n &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            two = solve(i + 2, n, s, dp);
        }

        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }
};

class Tabulation {
public:

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n] = 1;

        for(int i=n-1; i>=0; i--)
        {
            if (s[i] == '0')
            {
                 dp[i] = 0;
                 continue;
            }

            int one = dp[i+1];
            int two = 0;

            if (i + 1 < n &&
                (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                two = dp[i+2];
            }

            dp[i] = one + two;
        }

        return dp[0];
    }
};

/*
// well that is what i think it is and i like coding in this way 
actually this macbook box is way more useful than you might 
think it seems perfect or maybe just its a new way to ype 
that might be the reason actually the hand is paining 
especially my wrist maybe beacuse i am not used to type 
like this hopefully i might get used to it soon
*/