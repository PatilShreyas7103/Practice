// K-th Element of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Merge + Extra Array (Brute Force)
Time: O(n + m)
Space: O(n + m)
*/
class SolutionBrute {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int> v;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) v.push_back(a[i++]);
            else v.push_back(b[j++]);
        }

        while (i < a.size()) v.push_back(a[i++]);
        while (j < b.size()) v.push_back(b[j++]);

        return v[k - 1];
    }
};

/*
Approach 2: Merge Logic without Extra Space
Time: O(n + m)
Space: O(1)
*/
class SolutionLinear {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i = 0, j = 0, cnt = 1;

        while (i < a.size() && j < b.size()) {
            int val;
            if (a[i] < b[j]) val = a[i++];
            else val = b[j++];

            if (cnt == k) return val;
            cnt++;
        }

        while (i < a.size()) {
            if (cnt == k) return a[i];
            i++; cnt++;
        }

        while (j < b.size()) {
            if (cnt == k) return b[j];
            j++; cnt++;
        }

        return -1;
    }
};

/*
Approach 3: Binary Search on Partition (Optimal)
Time: O(log(min(n, m)))
Space: O(1)
*/
class SolutionBinary {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();

        // Ensure a is the smaller array
        if (m > n) return kthElement(b, a, k);

        int low = max(0, k - n);
        int high = min(k, m);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n) ? INT_MAX : b[cut2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } 
            else if (l1 > r2) {
                high = cut1 - 1;
            } 
            else {
                low = cut1 + 1;
            }
        }
        return -1;
    }
};