// Next Permutation

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force (Conceptual)
- Find a pair (i, j) such that i < j and v[j] > v[i]
- Keep updating to get the last such valid pair
- Swap them
- Sort the subarray after index i
- If no such pair exists, sort the entire array
Time: O(N^2 + N log N)
Space: O(1)
*/
class SolutionBruteForce {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        int l = -1, r = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[j] > v[i]) {
                    l = i;
                    r = j;
                }
            }
        }

        if (l == -1) {
            sort(v.begin(), v.end());
        } else {
            swap(v[l], v[r]);
            sort(v.begin() + l + 1, v.end());
        }
    }
};

/*
Approach 2: Optimal (Lexicographical Order)
- Find first index from right where nums[i] < nums[i+1]
- Swap it with just greater element on its right
- Reverse the part after that index
- If no such index exists, reverse entire array
Time: O(N)
Space: O(1)
*/
class SolutionOptimal {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};