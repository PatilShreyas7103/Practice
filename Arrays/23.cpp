// Subarray Sum Equals K

#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach 1: Brute Force
- Consider all possible subarrays
- Calculate sum for each subarray
- Increment count if sum equals k
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
                if (sum == k)
                    cnt++;
            }
        }

        return cnt;
    }
};

/*
Approach 2: Prefix Sum + Hash Map (Optimal)
- Maintain prefix sum
- If (prefixSum - k) exists, a valid subarray is found
- Store frequency of prefix sums
Time: O(N)
Space: O(N)
*/
class SolutionOptimal {
public:
    int subarraySum(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, cnt = 0;

        for (int x : v) {
            sum += x;
            cnt += mp[sum - k];
            mp[sum]++;
        }

        return cnt;
    }
};