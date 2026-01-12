// 4Sum Problem (Find All Unique Quadruplets with Given Target)

#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force + Set
- Try all possible quadruplets using 4 nested loops
- Sort each quadruplet and store in a set to avoid duplicates
Time: O(N^4 * logK)
Space: O(K)
*/
class SolutionBruteForce {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        long long sum =
                            (long long)arr[i] + arr[j] + arr[k] + arr[l];

                        if (sum == target) {
                            vector<int> quad = {arr[i], arr[j], arr[k], arr[l]};
                            sort(quad.begin(), quad.end());
                            st.insert(quad);
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

/*
Approach 2: Hashing (3 Loops + HashSet)
- Fix first two elements
- Use hash set to find the required 4th element
- Store sorted quadruplets in set to avoid duplicates
Time: O(N^3)
Space: O(N + K)
*/
class SolutionHashing {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> seen;

                for (int k = j + 1; k < n; k++) {
                    long long need =
                        (long long)target - arr[i] - arr[j] - arr[k];

                    if (seen.count(need)) {
                        vector<int> quad =
                            {arr[i], arr[j], arr[k], (int)need};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }

                    seen.insert(arr[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

/*
Approach 3: Sorting + Two Pointers (Optimal)
- Sort the array
- Fix first two elements
- Use two pointers for remaining two
- Skip duplicates carefully
Time: O(N^3)
Space: O(1) (excluding output)
*/
class SolutionOptimal {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum =
                        (long long)arr[i] + arr[j] +
                        arr[left] + arr[right];

                    if (sum == target) {
                        ans.push_back(
                            {arr[i], arr[j], arr[left], arr[right]});

                        while (left < right &&
                               arr[left] == arr[left + 1]) left++;
                        while (left < right &&
                               arr[right] == arr[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }

        return ans;
    }
};