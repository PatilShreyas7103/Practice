// Unique Number of Occurrences

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Count frequency of each number using a map.
- Store frequencies in a set.
- If all frequencies are unique, set size equals map size.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        map<int,int> freq;

        // Count occurrences
        for (int x : v) {
            freq[x]++;
        }

        set<int> st;
        for (auto it : freq) {
            st.insert(it.second);
        }

        return st.size() == freq.size();
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/