// Kids With the Greatest Number of Candies

#include <vector>
using namespace std;

/*
Approach 1: Brute Force
- For each child, check if (candies[i] + extra) is
  greater than or equal to every other child
Time: O(N^2)
Space: O(N)
*/
class SolutionBruteForce {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int e) {
        int n = v.size();
        vector<bool> ans(n, true);

        for (int i = 0; i < n; i++) {
            int val = v[i] + e;
            bool ok = true;

            for (int j = 0; j < n; j++) {
                if (v[j] > val) {
                    ok = false;
                    break;
                }
            }
            ans[i] = ok;
        }

        return ans;
    }
};

/*
Approach 2: Optimized (Your Idea – Using Maximum)
- Find the maximum candies among all kids
- For each kid, check if candies[i] + extra >= max
Time: O(N)
Space: O(N)
*/
class SolutionOptimal {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int e) {
        int n = v.size();
        vector<bool> ans(n, true);

        int mx = -1;
        for (int x : v)
            mx = max(mx, x);

        for (int i = 0; i < n; i++) {
            if (v[i] + e < mx)
                ans[i] = false;
        }

        return ans;
    }
};