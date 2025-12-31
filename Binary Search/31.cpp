// Median of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Merge + Extra Array (Brute Force)
Time: O(n1 + n2)
Space: O(n1 + n2)
*/
class SolutionBrute {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> v;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) v.push_back(a[i++]);
            else v.push_back(b[j++]);
        }

        while (i < a.size()) v.push_back(a[i++]);
        while (j < b.size()) v.push_back(b[j++]);

        int sz = v.size();
        if (sz & 1) return v[sz / 2];
        return (v[sz / 2] + v[sz / 2 - 1]) / 2.0;
    }
};

/*
Approach 2: Merge Logic without Extra Space
Time: O(n1 + n2)
Space: O(1)
*/
class SolutionLinear {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;
        int i = 0, j = 0, cnt = 0;
        int ind1 = n / 2 - 1, ind2 = n / 2;
        int el1 = -1, el2 = -1;

        while (i < n1 && j < n2) {
            int val = (a[i] < b[j]) ? a[i++] : b[j++];
            if (cnt == ind1) el1 = val;
            if (cnt == ind2) el2 = val;
            cnt++;
        }

        while (i < n1) {
            if (cnt == ind1) el1 = a[i];
            if (cnt == ind2) el2 = a[i];
            cnt++; i++;
        }

        while (j < n2) {
            if (cnt == ind1) el1 = b[j];
            if (cnt == ind2) el2 = b[j];
            cnt++; j++;
        }

        if (n & 1) return el2;
        return (el1 + el2) / 2.0;
    }
};

/*
Approach 3: Binary Search on Partition (Optimal)
Time: O(log(min(n1, n2)))
Space: O(1)
*/
class SolutionBinary {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int n1 = a.size(), n2 = b.size();
        int low = 0, high = n1;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};