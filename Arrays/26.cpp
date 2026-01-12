// 3Sum Problem (Find All Unique Triplets with Sum Zero)

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force + Set
- Check all possible triplets using 3 loops
- Sort each valid triplet and store in a set to avoid duplicates
Time: O(N^3 * logK)
Space: O(K)  (K = number of unique triplets)
*/
class SolutionBruteForce {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (v[i] + v[j] + v[k] == 0) {
                        vector<int> triplet = {v[i], v[j], v[k]};
                        sort(triplet.begin(), triplet.end());
                        st.insert(triplet);
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for (auto &it : st)
            ans.push_back(it);

        return ans;
    }
};

/*
Approach 2: Sorting + Two Pointers (Optimal)
- Sort the array
- Fix one element and use two pointers for the remaining two
- Skip duplicates carefully
Time: O(N^2)
Space: O(1) (excluding output)
*/
class SolutionOptimal {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    ans.push_back({arr[i], arr[left], arr[right]});
                    left++;
                    right--;

                    while (left < right && arr[left] == arr[left - 1])
                        left++;
                    while (left < right && arr[right] == arr[right + 1])
                        right--;
                }
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }

        return ans;
    }
};