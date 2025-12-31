// Guess Number Higher or Lower

#include <bits/stdc++.h>
using namespace std;

/*
Binary Search
Time: O(log n)
Space: O(1)

guess(num):
-1 → num is higher than picked number
 1 → num is lower than picked number
 0 → num is correct
*/

// Forward declaration (LeetCode provides the implementation)
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int s = 1;
        int e = n;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int res = guess(mid);

            if (res == -1) {
                e = mid - 1;
            } 
            else if (res == 1) {
                s = mid + 1;
            } 
            else {
                return mid;
            }
        }
        return -1;
    }
};