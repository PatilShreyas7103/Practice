// 💻 Program: Design Circular Queue — Array Implementation Using Modulo Indexing

#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> v;
    int rear = 0;
    int front = 0;
    int n;

    // Constructor to initialize queue of size k
    MyCircularQueue(int k) {
        v = vector<int>(k + 1); // use k+1 to distinguish full vs empty
        n = k + 1;
    }

    // Insert element into the circular queue
    bool enQueue(int value) {
        if (isFull()) return false;
        v[rear] = value;
        rear = (rear + 1) % n;
        return true;
    }

    // Delete element from the circular queue
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % n;
        return true;
    }

    // Get the front item
    int Front() {
        if (isEmpty()) return -1;
        return v[front];
    }

    // Get the last item
    int Rear() {
        if (isEmpty()) return -1;
        int ele = (rear == 0) ? n - 1 : rear - 1;
        return v[ele];
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == rear;
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % n == front;
    }
};