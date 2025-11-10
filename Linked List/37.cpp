// 💻 Program: 287. Find the Duplicate Number — Four Approaches

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

// ---------------------------------------------------------------
// 🧩 Approach 1: Binary Search on Value Range (O(n log n) Time, O(1) Space)
// ---------------------------------------------------------------
class BinarySearchSolution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            // Count how many numbers are <= mid
            for (int num : nums) {
                if (num <= mid)
                    count++;
            }

            if (count > mid)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Floyd’s Tortoise and Hare (Cycle Detection) (O(n) Time, O(1) Space)
// ---------------------------------------------------------------
class FloydCycleSolution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = 0, fast = 0;

        // Phase 1: Detect intersection point
        while (true) {
            slow = v[slow];
            fast = v[v[fast]];
            if (slow == fast)
                break;
        }

        // Phase 2: Find entrance to the cycle (duplicate)
        int slow2 = 0;
        while (true) {
            slow = v[slow];
            slow2 = v[slow2];
            if (slow == slow2)
                break;
        }

        return slow;
    }
};

// ---------------------------------------------------------------
// 🧮 Approach 3: Sorting (O(n log n) Time, O(1) Extra Space)
// ---------------------------------------------------------------
class SortingSolution {
public:
    int findDuplicate(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();

        for (int i = 0; i < n - 1; i++) {
            if (v[i] == v[i + 1])
                return v[i];
        }

        return -1;
    }
};

// ---------------------------------------------------------------
// 📊 Approach 4: HashMap / Frequency Counting (O(n) Time, O(n) Space)
// ---------------------------------------------------------------
class HashMapSolution {
public:
    int findDuplicate(vector<int>& v) {
        map<int, int> freq;

        for (int num : v)
            freq[num]++;

        for (auto it : freq) {
            if (it.second > 1)
                return it.first;
        }

        return -1;
    }
};