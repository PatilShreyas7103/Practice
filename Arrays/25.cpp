// Majority Element II (Appears More Than n/3 Times)

#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

/*
Approach 1: Brute Force
- For each element, count its frequency
- If frequency > n/3, add to answer
- At most 2 elements can satisfy the condition
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            bool alreadyTaken = false;
            for (int x : ans)
                if (x == nums[i])
                    alreadyTaken = true;

            if (alreadyTaken) continue;

            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (nums[j] == nums[i])
                    cnt++;

            if (cnt > n / 3)
                ans.push_back(nums[i]);

            if (ans.size() == 2)
                break;
        }

        return ans;
    }
};

/*
Approach 2: Hash Map (Frequency Count)
- Store frequency of each element
- Return elements with frequency > n/3
Time: O(N)
Space: O(N)
*/
class SolutionMap {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int x : v)
            mp[x]++;

        for (auto &it : mp) {
            if (it.second > n / 3)
                ans.push_back(it.first);
        }

        return ans;
    }
};

/*
Approach 3: Extended Moore’s Voting Algorithm (Optimal)
- At most 2 elements can appear more than n/3 times
- Maintain two candidates and their counts
- Verify candidates in second pass
Time: O(N)
Space: O(1)
*/
class SolutionMooreVoting {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        int c1 = 0, c2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;

        for (int x : v) {
            if (x == e1)
                c1++;
            else if (x == e2)
                c2++;
            else if (c1 == 0) {
                e1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                e2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;
        for (int x : v) {
            if (x == e1) c1++;
            else if (x == e2) c2++;
        }

        vector<int> ans;
        if (c1 > n / 3) ans.push_back(e1);
        if (c2 > n / 3) ans.push_back(e2);

        return ans;
    }
};