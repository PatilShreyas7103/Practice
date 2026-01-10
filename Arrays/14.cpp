// Majority Element (Appears More Than n/2 Times)

#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach 1: Brute Force
- For each element, count its frequency using nested loops
- If frequency > n/2, it is the majority element
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i])
                    cnt++;
            }
            if (cnt > n / 2)
                return nums[i];
        }

        return -1;
    }
};

/*
Approach 2: Hash Map (Frequency Count)
- Store frequency of each element
- Return element whose frequency exceeds n/2
Time: O(N)
Space: O(N)
*/
class SolutionMap {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        unordered_map<int, int> mp;

        for (int x : v) {
            mp[x]++;
            if (mp[x] > n / 2)
                return x;
        }

        return -1;
    }
};

/*
Approach 3: Moore’s Voting Algorithm (Optimal)
- Cancel out different elements
- Final candidate is potential majority
- Verify candidate count
Time: O(N)
Space: O(1)
*/
class SolutionMooreVoting {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, el = -1;

        for (int x : nums) {
            if (cnt == 0) {
                el = x;
                cnt = 1;
            } else if (el == x) {
                cnt++;
            } else {
                cnt--;
            }
        }

        cnt = 0;
        for (int x : nums) {
            if (x == el)
                cnt++;
        }

        return (cnt > nums.size() / 2) ? el : -1;
    }
};