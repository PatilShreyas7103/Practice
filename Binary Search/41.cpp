// Check if Array B is a Subset of Array A

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Hashing (Frequency Map)
Time: O(n + m)
Space: O(n)
*/
class SolutionHash {
public:
    bool isSubset(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mp;
        for (int x : a) {
            mp[x]++;
        }

        for (int x : b) {
            if (mp[x] == 0) {
                return false;
            }
            mp[x]--;
        }
        return true;
    }
};

/*
Approach 2: Sorting + Two Pointers
Time: O(n log n + m log m)
Space: O(1)
*/
class SolutionTwoPointer {
public:
    bool isSubset(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else {
                return false;
            }
        }
        return j == b.size();
    }
};

/*
Approach 3: Sorting + Binary Search (CORRECT WITH DUPLICATES)
Idea:
- Sort array A
- For each element in B, find it using lower_bound
- Mark used elements by moving search start index

Time: O(n log n + m log n)
Space: O(1)
*/
class SolutionBinarySearch {
public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int n = a.size();
        int start = 0;

        for (int x : b) {
            int it = lower_bound(a.begin() + start, a.end(), x) - a.begin();

            if (it == n || a[it] != x) {
                return false;
            }

            start = it + 1;  // move forward safely
        }
        return true;
    }
};