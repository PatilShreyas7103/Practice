// Question: Convert Min Heap ↔ Max Heap in one class

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* ==================== MAX HEAPIFY ==================== */
    void MaxHeapify(vector<int> &arr, int i, int N)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < N && arr[l] > arr[i])
            largest = l;

        if (r < N && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            MaxHeapify(arr, largest, N);
        }
    }

    /* ============== Convert Min Heap → Max Heap ============== */
    void convertMinToMaxHeap(vector<int> &v, int N) {
        for (int i = (N - 2) / 2; i >= 0; --i)
            MaxHeapify(v, i, N);
    }

    /* ==================== MIN HEAPIFY ==================== */
    void MinHeapify(vector<int> &arr, int i, int N)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < N && arr[l] < arr[i])
            smallest = l;

        if (r < N && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            MinHeapify(arr, smallest, N);
        }
    }

    /* ============== Convert Max Heap → Min Heap ============== */
    void convertMaxToMinHeap(vector<int> &v, int N) {
        for (int i = (N - 2) / 2; i >= 0; --i)
            MinHeapify(v, i, N);
    }
};