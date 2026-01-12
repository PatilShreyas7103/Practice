// Count Inversions in an Array

#include <vector>
using namespace std;

/*
Approach 1: Brute Force
- Check all pairs (i, j) where i < j
- If v[i] > v[j], it is an inversion
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int inversionCount(vector<int>& v) {
        int n = v.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] > v[j])
                    cnt++;
            }
        }

        return cnt;
    }
};

/*
Approach 2: Merge Sort (Optimal)
- Divide array into halves
- Count inversions while merging sorted halves
- When left[i] > right[j], all remaining left elements form inversions
Time: O(N log N)
Space: O(N)
*/
class SolutionOptimal {
public:
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;
        int cnt = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
                cnt += (mid - left + 1);
            }
        }

        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];

        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;

        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);

        return cnt;
    }

    int inversionCount(vector<int>& v) {
        return mergeSort(v, 0, v.size() - 1);
    }
};