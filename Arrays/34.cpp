// Reverse Pairs (i < j and nums[i] > 2 * nums[j])

#include <vector>
using namespace std;

/*
Approach 1: Brute Force
- Check all pairs (i, j) where i < j
- Count if nums[i] > 2 * nums[j]
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int reversePairs(vector<int>& v) {
        int n = v.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((long long)v[i] > 2LL * v[j])
                    cnt++;
            }
        }

        return cnt;
    }
};

/*
Approach 2: Merge Sort (Optimal)
- Similar to inversion count
- While merging, count pairs where arr[i] > 2 * arr[j]
- Use two pointers on sorted halves
Time: O(N log N)
Space: O(N)
*/
class SolutionOptimal {
public:
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right])
                right++;
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;
        int cnt = 0;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& v) {
        return mergeSort(v, 0, v.size() - 1);
    }
};