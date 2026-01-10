// Maximum Subarray Sum + Subarray Printing

#include <vector>
#include <climits>
using namespace std;

/*
Approach 1: Brute Force
- Consider every possible subarray
- Calculate sum and track maximum
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += v[j];
                mx = max(mx, sum);
            }
        }

        return mx;
    }
};

/*
Approach 2: Kadane’s Algorithm (Optimal)
- Maintain current sum
- Reset sum when it becomes negative
- Track maximum sum encountered
Time: O(N)
Space: O(1)
*/
class SolutionKadane {
public:
    int maxSubArray(vector<int>& v) {
        int mx = INT_MIN;
        int sum = 0;

        for (int x : v) {
            sum += x;
            mx = max(mx, sum);
            if (sum < 0)
                sum = 0;
        }

        return mx;
    }
};

// Maximum Subarray Sum with Subarray Printing

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

/*
Approach 1: Brute Force
- Try all possible subarrays
- Track maximum sum and corresponding indices
- Print subarray with maximum sum
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int ansL = 0, ansR = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum > mx) {
                    mx = sum;
                    ansL = i;
                    ansR = j;
                }
            }
        }

        cout << "The subarray is: [";
        for (int i = ansL; i <= ansR; i++)
            cout << nums[i] << " ";
        cout << "]" << endl;

        return mx;
    }
};

/*
Approach 2: Kadane’s Algorithm with Indices (Optimal)
- Maintain running sum
- Reset sum when it becomes negative
- Track start and end indices of max subarray
Time: O(N)
Space: O(1)
*/
class SolutionKadane {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0, maxi = LLONG_MIN;
        int start = 0, ansStart = 0, ansEnd = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0)
                start = i;

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            if (sum < 0)
                sum = 0;
        }

        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++)
            cout << nums[i] << " ";
        cout << "]" << endl;

        return maxi;
    }
};