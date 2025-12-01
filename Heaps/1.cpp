// Question: Implementation of Max Heap and Min Heap

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

/*
    Array-based binary heap implementation

    - MaxHeap: parent >= children
    - MinHeap: parent <= children

    Indexing: 0-based
        left child  = 2*i + 1
        right child = 2*i + 2
        parent      = (i - 1) / 2
*/

/* ======================= MAX HEAP ======================= */
class MaxHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Move element at index i UP to restore max-heap property
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // Move element at index i DOWN to restore max-heap property
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;

            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    MaxHeap() {}

    // Build heap from an existing array (O(n))
    MaxHeap(const vector<int> &arr) {
        heap = arr;
        for (int i = (int)heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    bool empty() const { return heap.empty(); }
    int size()  const { return (int)heap.size(); }

    // Return maximum element (root)
    int top() const {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    // Insert a new key and restore heap property (O(log n))
    void push(int key) {
        heap.push_back(key);
        heapifyUp((int)heap.size() - 1);
    }

    // Remove and return maximum element (root) (O(log n))
    int pop() {
        if (heap.empty()) throw runtime_error("Heap is empty");

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) heapifyDown(0);
        return root;
    }

    // Utility to print heap array (level order)
    void printHeap() const {
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }
};

/* ======================= MIN HEAP ======================= */
class MinHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Move element at index i UP to restore min-heap property
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // Move element at index i DOWN to restore min-heap property
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;

            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    MinHeap() {}

    // Build heap from an existing array (O(n))
    MinHeap(const vector<int> &arr) {
        heap = arr;
        for (int i = (int)heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    bool empty() const { return heap.empty(); }
    int size()  const { return (int)heap.size(); }

    // Return minimum element (root)
    int top() const {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    // Insert a new key and restore heap property (O(log n))
    void push(int key) {
        heap.push_back(key);
        heapifyUp((int)heap.size() - 1);
    }

    // Remove and return minimum element (root) (O(log n))
    int pop() {
        if (heap.empty()) throw runtime_error("Heap is empty");

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) heapifyDown(0);
        return root;
    }

    // Utility to print heap array (level order)
    void printHeap() const {
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    MaxHeap maxH;
    maxH.push(10);
    maxH.push(4);
    maxH.push(15);
    maxH.push(20);

    cout << "MaxHeap elements: ";
    maxH.printHeap();
    cout << "Max element: " << maxH.top() << "\n";
    cout << "Extracted: " << maxH.pop() << "\n";
    cout << "After pop: ";
    maxH.printHeap();

    MinHeap minH;
    minH.push(10);
    minH.push(4);
    minH.push(15);
    minH.push(2);

    cout << "MinHeap elements: ";
    minH.printHeap();
    cout << "Min element: " << minH.top() << "\n";
    cout << "Extracted: " << minH.pop() << "\n";
    cout << "After pop: ";
    minH.printHeap();

    return 0;
}
