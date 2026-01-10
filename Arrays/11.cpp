// Longest Subarray with Sum K

#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach 1: Sliding Window (ONLY for Positive Numbers)
- Use two pointers (window)
- Expand window by moving right pointer
- Shrink window if sum exceeds k
- Works ONLY because all numbers are positive
Time: O(N)
Space: O(1)
*/
class SolutionPositiveOnly {
public:
    int longestSubarray(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, sum = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            sum += v[r];

            while (sum > k && l <= r) {
                sum -= v[l];
                l++;
            }

            if (sum == k) {
                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};

/*
Approach 2: Prefix Sum + Hash Map (Positive + Negative)
- Maintain prefix sum
- Store first occurrence of each prefix sum
- If (currentSum - k) exists, subarray with sum k is found
- Works with negative numbers as well
Time: O(N)
Space: O(N)
*/
class SolutionPositiveNegative {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k) {
                ans = max(ans, i + 1);
            }

            if (mp.find(sum - k) != mp.end()) {
                ans = max(ans, i - mp[sum - k]);
            }

            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return ans;
    }
};