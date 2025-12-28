// Sqrt(x) — Integer Square Root

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        long long lastValid = 1;
        for (int value = 1; value <= x; value++) {
            long long square = 1LL * value * value;

            if (square == x) {
                return value;
            } 
            else if (square < x) {
                lastValid = value;
            } 
            else {
                break;
            }
        }

        return lastValid;
    }
};

/* ===================== STL SQRT APPROACH ===================== */
class STLApproach {
public:
    int mySqrt(int x) {
        return (sqrt(x));
    }
};

/* ===================== POWER FUNCTION APPROACH ===================== */
class PowerFunctionApproach {
public:
    int mySqrt(int x) {
        return (pow(x, 0.5));
    }
};

/* ===================== BINARY SEARCH APPROACH ===================== */
class BinarySearchApproach {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        long long answer = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == x) {
                return mid;
            } 
            else if (square < x) {
                answer = mid;
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return answer;
    }
};