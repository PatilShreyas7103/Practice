// Longest Consecutive Sequence

#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force
- For each element, check how long the consecutive sequence continues
- Uses linear search for next element
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = v[i];
            int cnt = 1;

            while (find(v.begin(), v.end(), x + 1) != v.end()) {
                x++;
                cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};

/*
Approach 2: Sorting
- Sort the array
- Skip duplicates
- Count consecutive elements
Time: O(N log N)
Space: O(1)
*/
class SolutionSorting {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        if (n == 0) return 0;

        sort(v.begin(), v.end());

        int len = 1, ans = 1;

        for (int i = 0; i < n - 1; i++) {
            if (v[i] + 1 == v[i + 1]) {
                len++;
                ans = max(ans, len);
            } else if (v[i] == v[i + 1]) {
                continue;
            } else {
                len = 1;
            }
        }

        return ans;
    }
};

/*
Approach 3: Hash Set (Optimal)
- Insert all elements into a set
- Start counting only if (x-1) is not present
- Build consecutive sequence forward
Time: O(N)
Space: O(N)
*/
class SolutionOptimal {
public:
    int longestConsecutive(vector<int>& v) {
        unordered_set<int> st(v.begin(), v.end());
        int ans = 0;

        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int cnt = 1;
                int curr = x;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};