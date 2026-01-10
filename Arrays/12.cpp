// Two Sum Problem

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force
- Check every possible pair
- If any pair sums to target, return result
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    string twoSumExists(vector<int>& arr, int target) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target)
                    return "YES";
            }
        }
        return "NO";
    }

    vector<int> twoSumIndices(vector<int>& arr, int target) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};

/*
Approach 2: Hashing (Unsorted Array)
- Store element -> index
- Check if (target - current) exists
Time: O(N)
Space: O(N)
*/
class SolutionHashing {
public:
    string twoSumExists(vector<int>& arr, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            int need = target - arr[i];
            if (mp.find(need) != mp.end())
                return "YES";
            mp[arr[i]] = i;
        }

        return "NO";
    }

    vector<int> twoSumIndices(vector<int>& arr, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            int need = target - arr[i];
            if (mp.find(need) != mp.end())
                return {mp[need], i};
            mp[arr[i]] = i;
        }

        return {-1, -1};
    }
};

/*
Approach 3: Sorting + Two Pointers
- Store values with original indices
- Sort the array
- Move pointers based on sum comparison
Time: O(N log N)
Space: O(N)
*/
class SolutionTwoPointer {
public:
    string twoSumExists(vector<int> arr, int target) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < arr.size(); i++)
            nums.push_back({arr[i], i});

        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l].first + nums[r].first;
            if (sum == target)
                return "YES";
            else if (sum < target)
                l++;
            else
                r--;
        }

        return "NO";
    }

    vector<int> twoSumIndices(vector<int> arr, int target) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < arr.size(); i++)
            nums.push_back({arr[i], i});

        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l].first + nums[r].first;
            if (sum == target)
                return {nums[l].second, nums[r].second};
            else if (sum < target)
                l++;
            else
                r--;
        }

        return {-1, -1};
    }
};