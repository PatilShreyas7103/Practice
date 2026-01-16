// First Missing Positive

#include <vector>
#include <set>
#include <cstdlib>
using namespace std;

/*
Approach 1: Brute Force using Set
- Store all positive numbers in a set
- Check from 1 upwards for the first missing number
Time: O(N log N)
Space: O(N)
*/
class SolutionBruteForce {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;

        for (int x : nums) {
            if (x > 0)
                st.insert(x);
        }

        int curr = 1;
        for (int x : st) {
            if (x == curr)
                curr++;
            else if (x > curr)
                break;
        }

        return curr;
    }
};

/*
Approach 2: Optimal In-Place (Index Marking)
- Use array indices to mark presence
- Index i represents number i+1
Time: O(N)
Space: O(1)
*/
class SolutionOptimal {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace negative numbers with 0
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                nums[i] = 0;
        }

        // Step 2: Mark presence
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                if (nums[val - 1] > 0)
                    nums[val - 1] *= -1;
                else if (nums[val - 1] == 0)
                    nums[val - 1] = -(n + 1);
            }
        }

        // Step 3: Find first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0)
                return i + 1;
        }

        return n + 1;
    }
};