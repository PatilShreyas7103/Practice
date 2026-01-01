// Power Function (x^n) 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force Loop
Time: O(n)
Space: O(1)
*/
class SolutionBrute {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double ans = 1.0;
        for (long long i = 0; i < exp; i++) {
            ans *= x;
        }
        return ans;
    }
};

/*
Approach 2: Recursive Binary Exponentiation
Time: O(log n)
Space: O(log n)
*/
class SolutionRecursive {
public:
    double power(double x, long long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;

        double half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }

    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        return power(x, exp);
    }
};

/*
Approach 3: Iterative Binary Exponentiation (Optimal)
Time: O(log n)
Space: O(1)
*/
class Solution {
public:
    double myPow(double x, long long n) {
        double ans = 1;
        int p = n;
        if(n<0)
        {
            n = -n;
        }
        if(n==0)
        {
            return 1.0;
        }
        while(n>0)
        {
            if(n&1)
            {
                ans = ans*x;
                n--;
            }
            else
            {
                n = n/2;
                x = x*x;
            }
        }
        if(p>0)
        {
            return ans;
        }
        else
        {
            return (1.0/ans);
        }
    }
};