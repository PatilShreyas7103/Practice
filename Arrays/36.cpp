// Product of Array Except Self

#include <vector>
using namespace std;

/*
Approach 1: Brute Force
- For each index, multiply all elements except itself
Time: O(N^2)
Space: O(N)
*/
class SolutionBruteForce {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (i != j)
                    prod *= v[j];
            }
            res.push_back(prod);
        }

        return res;
    }
};

/*
Approach 2: Division Method (Zero Handling)
- Count number of zeros
- If no zero → divide total product
- If one zero → only zero index has product
- If more than one zero → all products are zero
Time: O(N)
Space: O(1)
*/
class SolutionDivision {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> res;
        int zeroCount = 0;
        int prod = 1;

        for (int x : v) {
            if (x == 0)
                zeroCount++;
            else
                prod *= x;
        }

        if (zeroCount == 0) {
            for (int x : v)
                res.push_back(prod / x);
        }
        else if (zeroCount == 1) {
            for (int x : v) {
                if (x == 0)
                    res.push_back(prod);
                else
                    res.push_back(0);
            }
        }
        else {
            res.assign(n, 0);
        }

        return res;
    }
};

/*
Approach 3: Prefix & Suffix Product (Optimal)
- prefix[i] = product of elements before i
- suffix[i] = product of elements after i
- result[i] = prefix[i] * suffix[i]
- No division used
Time: O(N)
Space: O(1) (excluding output)
*/
class SolutionOptimal {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> res(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= v[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= v[i];
        }

        return res;
    }
};