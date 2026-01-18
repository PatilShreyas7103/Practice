// Sort Characters By Frequency — All Approaches
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Sorting by Frequency (Your Approach)
// Idea:
// - Count frequency
// - Store (frequency, character)
// - Sort in descending order of frequency
class SortByFreq {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        vector<pair<int, char>> v;
        for (auto &it : mp) {
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());

        string ans = "";
        for (auto &it : v) {
            ans.append(it.first, it.second);
        }

        return ans;
    }
};
/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 2: Bucket Sort (Optimal)
// Idea:
// - Frequency ranges from 1 to n
// - Create buckets where index = frequency
// - Place characters into frequency buckets
class BucketSort {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        int n = s.length();
        vector<vector<char>> bucket(n + 1);

        for (auto &it : mp) {
            bucket[it.second].push_back(it.first);
        }

        string ans = "";
        for (int f = n; f > 0; f--) {
            for (char c : bucket[f]) {
                ans.append(f, c);
            }
        }

        return ans;
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*------------------------------------------------------*/
// Approach 3: Priority Queue (Max Heap)
// Idea:
// - Push (frequency, character) into max heap
// - Always extract highest frequency
class MaxHeap {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto &it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (!pq.empty()) {
            auto [f, c] = pq.top();
            pq.pop();
            ans.append(f, c);
        }

        return ans;
    }
};
/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
