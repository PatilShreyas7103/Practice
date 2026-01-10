// Missing Number in Array

#include <vector>
using namespace std;

/*
Approach 1: Brute Force (Linear Search)
- For every number from 1 to N, check if it exists in the array
- The number not found is the missing number
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int missingNumber(vector<int>& a, int N) {
        for (int i = 1; i <= N; i++) {
            bool found = false;
            for (int j = 0; j < N - 1; j++) {
                if (a[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) return i;
        }
        return -1;
    }
};

/*
Approach 2: Sum Formula
- Calculate sum of first N natural numbers
- Subtract sum of array elements
- Remaining value is the missing number
Time: O(N)
Space: O(1)
*/
class SolutionSumFormula {
public:
    int missingNumber(vector<int>& a, int N) {
        int total = (N * (N + 1)) / 2;
        int sum = 0;
        for (int i = 0; i < N - 1; i++)
            sum += a[i];
        return total - sum;
    }
};

/*
Approach 3: XOR Method
- XOR all numbers from 1 to N
- XOR all elements of the array
- XOR of both results gives the missing number
Time: O(N)
Space: O(1)
*/
class SolutionXOR {
public:
    int missingNumber(vector<int>& a, int N) {
        int x1 = 0, x2 = 0;

        for (int i = 0; i < N - 1; i++) {
            x2 ^= a[i];
            x1 ^= (i + 1);
        }

        x1 ^= N;
        return x1 ^ x2;
    }
};