// Container With Most Water

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force
- Try all possible pairs (i, j)
- Area = (j - i) * min(height[i], height[j])
- Track maximum area
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = (j - i) * min(v[i], v[j]);
                maxi = max(maxi, area);
            }
        }

        return maxi;
    }
};

/*
Approach 2: Two Pointers (Optimal)
- Start with widest container (left = 0, right = n-1)
- Compute area and move pointer with smaller height
- This ensures no better area is missed
Time: O(N)
Space: O(1)
*/
class SolutionOptimal {
public:
    int maxArea(vector<int>& v) {
        int i = 0, j = v.size() - 1;
        int ans = 0;

        while (i < j) {
            int area = (j - i) * min(v[i], v[j]);
            ans = max(ans, area);

            if (v[i] < v[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};