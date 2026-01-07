// Maximum Frequency Stack 

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Max Heap (Priority Queue)
Time:
- push(): O(log n)
- pop(): O(log n)
Space: O(n)

Idea:
- Maintain frequency of each value.
- Use a max-heap storing {frequency, index, value}.
- Higher frequency has priority.
- If frequencies tie, more recent index wins.
*/
class FreqStackHeap {
private:
    priority_queue<vector<int>> heap; // {frequency, index, value}
    unordered_map<int, int> cnt;
    int index;

public:
    FreqStackHeap() {
        index = 0;
    }

    void push(int val) {
        cnt[val]++;
        heap.push({cnt[val], index++, val});
    }

    int pop() {
        auto top = heap.top();
        heap.pop();
        int val = top[2];
        cnt[val]--;
        return val;
    }
};

/*
Approach 2: Brute Force (Vector + Frequency Map)
Time:
- push(): O(1)
- pop(): O(n)
Space: O(n)

Idea:
- Store elements in a vector.
- Track frequencies using a map.
- On pop(), find max frequency, then scan from back
  to find the most recent element with that frequency.
*/
class FreqStackBruteForce {
private:
    unordered_map<int, int> cnt;
    vector<int> st;

public:
    FreqStackBruteForce() {}

    void push(int val) {
        st.push_back(val);
        cnt[val]++;
    }

    int pop() {
        int maxCnt = 0;
        for (auto it : cnt) {
            maxCnt = max(maxCnt, it.second);
        }

        int i = st.size() - 1;
        while (cnt[st[i]] != maxCnt) {
            i--;
        }

        int val = st[i];
        st.erase(st.begin() + i);
        cnt[val]--;
        return val;
    }
};