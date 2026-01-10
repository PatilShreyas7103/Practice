// Leaders in an Array

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force
- For each element, check all elements to its right
- If no greater element exists on the right, it is a leader
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    vector<int> leaders(vector<int>& v) {
        int n = v.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++) {
                if (v[j] > v[i]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader)
                ans.push_back(v[i]);
        }

        return ans;
    }
};

/*
Approach 2: Optimal (Right-to-Left Traversal)
- Traverse array from the right
- Maintain maximum seen so far
- Current element is leader if it >= max
Time: O(N)
Space: O(1)
*/
class SolutionOptimal {
public:
    vector<int> leaders(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        int mx = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (v[i] >= mx)
                ans.push_back(v[i]);
            mx = max(mx, v[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};