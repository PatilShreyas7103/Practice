// Longest Subarray with Sum 0

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force
- Consider all possible subarrays
- Compute sum for each subarray
- If sum is 0, update maximum length
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int maxLen(vector<int>& v) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
                if (sum == 0) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

/*
Approach 2: Prefix Sum + Hash Map (Optimal)
- Maintain prefix sum
- If prefix sum repeats, subarray in between has sum 0
- Store first occurrence of each prefix sum
Time: O(N)
Space: O(N)
*/
class SolutionOptimal {
public:
    int maxLen(vector<int>& v) {
        unordered_map<int, int> mp;
        int sum = 0, maxi = 0;

        for (int i = 0; i < v.size(); i++) {
            sum += v[i];

            if (sum == 0) {
                maxi = i + 1;
            } else if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return maxi;
    }
};