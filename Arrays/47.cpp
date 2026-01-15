// Find Pivot Index

#include <vector>
using namespace std;

/*
Approach 1: Prefix Array (Your Idea – Corrected)
- First pass: store left sum for each index
- Second pass: compute right sum properly and compare
Time: O(N)
Space: O(N)
*/
class SolutionPrefix {
public:
    int pivotIndex(vector<int>& v) {
        int n = v.size();
        vector<int> p(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            p[i] = sum;      // left sum
            sum += v[i];
        }

        int total = sum;
        int rightSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            rightSum = total - p[i] - v[i];
            if (p[i] == rightSum)
                return i;
        }

        return -1;
    }
};

/*
Approach 2: Optimal (No Extra Space)
- Compute total sum
- Maintain left sum
- rightSum = total - leftSum - v[i]
Time: O(N)
Space: O(1)
*/
class SolutionOptimal {
public:
    int pivotIndex(vector<int>& v) {
        int total = 0;
        for (int x : v)
            total += x;

        int leftSum = 0;

        for (int i = 0; i < v.size(); i++) {
            if (leftSum == total - leftSum - v[i])
                return i;
            leftSum += v[i];
        }

        return -1;
    }
};