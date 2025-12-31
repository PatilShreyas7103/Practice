// Peak Index in a Mountain Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size();
        int s = 1;
        int e = n - 2;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1]) {
                return mid;
            } 
            else if (v[mid - 1] > v[mid]) {
                e = mid - 1;
            } 
            else {
                s = mid + 1;
            }
        }
        return -1;
    }
};