// Design Circular Deque

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Circular Array
Time: O(1) for all operations
Space: O(k)

Idea:
- Use an array of size k.
- Maintain two pointers:
  front → index of front element
  rear  → index of rear element
- Use modulo arithmetic to make it circular.
- Maintain a size variable to check empty/full conditions.
*/
class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int cap;

public:
    MyCircularDeque(int k) {
        cap = k;
        arr.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front - 1 + cap) % cap;
        arr[front] = value;

        if (size == 0) {
            rear = front;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        rear = (rear + 1) % cap;
        arr[rear] = value;

        if (size == 0) {
            front = rear;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % cap;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        rear = (rear - 1 + cap) % cap;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};