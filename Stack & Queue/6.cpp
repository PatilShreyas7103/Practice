// Array Based Circular Queue Implementation

#include <bits/stdc++.h>
using namespace std;

class ArrayQueue {
private:
    int* arr;
    int start;
    int end;
    int currSize;
    int maxSize;

public:
    ArrayQueue(int size = 10) {
        maxSize = size;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    void push(int x) {
        if (currSize == maxSize) return;

        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }

        arr[end] = x;
        currSize++;
    }

    int pop() {
        if (isEmpty()) return -1;

        int popped = arr[start];

        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }

        currSize--;
        return popped;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[start];
    }

    bool isEmpty() {
        return currSize == 0;
    }
};