// Merge Sorted Array

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Extra Placement + Sort
- Copy elements of second array into first
- Sort the combined array
Time: O((m+n) log(m+n))
Space: O(1)
*/
class SolutionSort {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        for (int i = m; i < m + n; i++) {
            a[i] = b[i - m];
        }
        sort(a.begin(), a.end());
    }
};

/*
Approach 2: Optimal (Three Pointers from Back)
- Start merging from the end of array a
- Compare largest elements first
- Place elements in correct position without extra space
Time: O(m + n)
Space: O(1)
*/
class SolutionOptimal {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m - 1;
        int j = n - 1;
        int idx = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (a[i] < b[j]) {
                a[idx--] = b[j--];
            } else {
                a[idx--] = a[i--];
            }
        }

        while (j >= 0) {
            a[idx--] = b[j--];
        }
    }
};