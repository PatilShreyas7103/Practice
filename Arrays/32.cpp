// Missing and Repeating Number

#include <vector>
using namespace std;

/*
Approach 1: Using Frequency Array
- Count occurrences of each number
- Frequency 2 → repeating
- Frequency 0 → missing
Time: O(N)
Space: O(N)
*/
class SolutionFreq {
public:
    vector<int> findTwoElement(vector<int>& v) {
        int n = v.size();
        vector<int> cnt(n + 1, 0);

        for (int x : v)
            cnt[x]++;

        int repeat = -1, missing = -1;

        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 2) repeat = i;
            else if (cnt[i] == 0) missing = i;
        }

        return {repeat, missing};
    }
};

/*
Approach 2: Mathematical (Sum & Square Sum) — Optimal
- Let expected sum = n(n+1)/2
- Let expected sq sum = n(n+1)(2n+1)/6
- diff = actualSum - expectedSum = R - M
- diffSq = actualSqSum - expectedSqSum = R^2 - M^2
- Solve equations to find R and M
Time: O(N)
Space: O(1)
*/
class SolutionMath {
public:
    vector<int> findTwoElement(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0, sqSum = 0;

        for (int x : nums) {
            sum += x;
            sqSum += (long long)x * x;
        }

        long long expSum = n * (n + 1) / 2;
        long long expSqSum = n * (n + 1) * (2 * n + 1) / 6;

        long long diff = sum - expSum;                 // R - M
        long long diffSq = sqSum - expSqSum;           // R^2 - M^2

        long long sumRM = diffSq / diff;               // R + M

        long long repeating = (diff + sumRM) / 2;
        long long missing = repeating - diff;

        return {(int)repeating, (int)missing};
    }
};

/*
Approach 3: XOR Method (Most Optimal & Safe)
- XOR all array elements with numbers 1..n
- Result = R ^ M
- Use rightmost set bit to divide numbers into two groups
- Identify repeating and missing
Time: O(N)
Space: O(1)
*/
class SolutionXOR {
public:
    vector<int> findTwoElement(vector<int>& v) {
        int n = v.size();
        int xr = 0;

        for (int x : v) xr ^= x;
        for (int i = 1; i <= n; i++) xr ^= i;

        int bit = xr & -xr;
        int a = 0, b = 0;

        for (int x : v) {
            if (x & bit) a ^= x;
            else b ^= x;
        }

        for (int i = 1; i <= n; i++) {
            if (i & bit) a ^= i;
            else b ^= i;
        }

        for (int x : v) {
            if (x == a) return {a, b};
        }

        return {b, a};
    }
};