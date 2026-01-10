// Union of Two Sorted Arrays

#include <vector>
#include <set>
using namespace std;

/*
Approach 1: Set-based approach
- Insert all elements of both arrays into a set
- Set automatically removes duplicates and keeps elements sorted
- Convert set to vector and return
Time: O((n + m) log(n + m))
Space: O(n + m)
*/
class SolutionSetApproach {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> st;
        for (int x : a) st.insert(x);
        for (int x : b) st.insert(x);
        return vector<int>(st.begin(), st.end());
    }
};

/*
Approach 2: Two-pointer approach (for sorted arrays)
- Traverse both arrays using two pointers
- Add smaller element to answer while skipping duplicates
- After one array ends, process remaining elements
Time: O(n + m)
Space: O(1) (excluding output array)
*/
class SolutionTwoPointer {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int i = 0, j = 0;
        int m = a.size(), n = b.size();

        while (i < m && j < n) {
            if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
            } else {
                if (ans.empty() || ans.back() != b[j])
                    ans.push_back(b[j]);
                j++;
            }
        }

        while (i < m) {
            if (ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }

        while (j < n) {
            if (ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
};