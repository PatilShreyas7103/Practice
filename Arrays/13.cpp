// Sort Colors (0s, 1s, 2s)

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Built-in Sort
- Directly sort the array
- Simple but not optimal for this problem
Time: O(N log N)
Space: O(1)
*/
class SolutionSort {
public:
    void sortColors(vector<int>& v) {
        sort(v.begin(), v.end());
    }
};

/*
Approach 2: Dutch National Flag Algorithm (Optimal)
- Maintain three pointers: low, mid, high
- 0s go to left, 2s go to right, 1s stay in middle
Time: O(N)
Space: O(1)
*/
class SolutionDNF {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
Approach 3: Counting Method
- Count number of 0s and 2s
- Fill array with 0s, then 1s, then 2s
Time: O(N)
Space: O(1)
*/
class SolutionCounting {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int cnt0 = 0, cnt2 = 0;

        for (int x : v) {
            if (x == 0) cnt0++;
            else if (x == 2) cnt2++;
        }

        for (int i = 0; i < cnt0; i++)
            v[i] = 0;

        for (int i = cnt0; i < n - cnt2; i++)
            v[i] = 1;

        for (int i = n - cnt2; i < n; i++)
            v[i] = 2;
    }
};