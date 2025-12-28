// N-th Root of a Number

#include <bits/stdc++.h>
using namespace std;

/* ===================== BRUTE FORCE APPROACH ===================== */
class BruteForce {
public:
    int nthRoot(int n, int m) {
        if (m == 0 || m == 1) {
            return m;
        }

        for (int value = 1; value <= m; value++) {
            long long powerValue = pow(value, n);

            if (powerValue == m) {
                return value;
            } 
            else if (powerValue > m) {
                break;
            }
        }

        return -1;
    }
};

/* ===================== BINARY SEARCH (USING POW) ===================== */
class BinarySearchWithPow {
public:
    int nthRoot(int n, int m) {
        if (m == 0 || m == 1) {
            return m;
        }

        long long left = 1;
        long long right = m;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long powerValue = pow(mid, n);

            if (powerValue == m) {
                return mid;
            } 
            else if (powerValue < m) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

/* ===================== BINARY SEARCH (SAFE POWER - NO FLOAT) ===================== */
class BinarySearchSafePower {
private:
    long long fastPower(long long b, int e) {
        long long ans = 1;
        
        while(e>0)
        {
            if(e&1)
            {
                e--;
                ans*=b;
            }
            else
            {
                e/=2;
                b*=b;
            }
        }
        
        return ans;
    }

public:
    int nthRoot(int n, int m) {
        int left = 1;
        int right = m;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long value = fastPower(mid, n);

            if (value == m) {
                return mid;
            } 
            else if (value < m) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};