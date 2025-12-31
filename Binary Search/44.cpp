// Kth Smallest Element in a Sorted Matrix 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force
Time: O(n^2 log n)
Space: O(n^2)
*/
class SolutionBrute {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> v;
        for (auto &row : mat) {
            for (int x : row) {
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};

/*
Approach 2: Min Heap
Time: O(k log n)
Space: O(n)
*/
class SolutionHeap {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        for (int i = 0; i < n; i++) {
            pq.push({mat[i][0], {i, 0}});
        }

        while (--k) {
            auto t = pq.top(); pq.pop();
            int r = t.second.first;
            int c = t.second.second;

            if (c + 1 < n) {
                pq.push({mat[r][c + 1], {r, c + 1}});
            }
        }
        return pq.top().first;
    }
};

/*
Approach 3: Binary Search on Value (Optimal)
Time: O(n log(max-min))
Space: O(1)
*/
class SolutionBinary {
public:
    int countLessEqual(vector<vector<int>>& mat, int mid) {
        int n = mat.size();
        int i = 0, j = n - 1;
        int cnt = 0;

        while (i < n && j >= 0) {
            if (mat[i][j] <= mid) {
                cnt += (j + 1);
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(mat, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};