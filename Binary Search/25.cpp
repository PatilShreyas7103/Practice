// Painters Partition Problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPaint(int maxTime, vector<int>& boards, int painters) {
        int usedPainters = 1;
        int currTime = 0;

        for (int len : boards) {
            if (currTime + len <= maxTime) {
                currTime += len;
            } else {
                usedPainters++;
                currTime = len;
            }
        }
        return usedPainters <= painters;
    }

    int minTime(vector<int>& boards, int painters) {
        int low = *max_element(boards.begin(), boards.end());
        int high = accumulate(boards.begin(), boards.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPaint(mid, boards, painters)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};