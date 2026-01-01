// String to Integer (atoi) 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Iterative (Recommended)
Time: O(n)
Space: O(1)
*/
class SolutionIterative {
public:
    bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long long num = 0;

        // skip leading spaces
        while (i < n && s[i] == ' ') i++;

        if (i == n) return 0;

        // handle sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // parse digits
        while (i < n && isDigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            if (sign * num >= INT_MAX) return INT_MAX;
            if (sign * num <= INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * num);
    }
};

/*
Approach 2: Recursive (Educational – Not Preferred in Interviews)
Time: O(n)
Space: O(n) due to recursion stack
*/
class SolutionRecursive {
public:
    int helper(const string &s, int i, long long num, int sign) {
        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(sign * num);
        }

        num = num * 10 + (s[i] - '0');

        if (sign * num >= INT_MAX) return INT_MAX;
        if (sign * num <= INT_MIN) return INT_MIN;

        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;

        // skip spaces
        while (i < n && s[i] == ' ') i++;

        // handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
};