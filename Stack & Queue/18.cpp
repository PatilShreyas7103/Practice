// Queue using Linked List

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Linked List Implementation
Time: O(1) for enqueue, dequeue, getFront
Space: O(n)

Idea:
- Maintain two pointers: front and rear.
- Enqueue at rear, dequeue from front.
- Keep a size counter for O(1) size retrieval.
*/

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
private:
    Node* front;
    Node* rear;
    int sz;

public:
    myQueue() {
        front = nullptr;
        rear = nullptr;
        sz = 0;
    }

    bool isEmpty() {
        return sz == 0;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        sz++;
    }

    void dequeue() {
        if (isEmpty()) return;

        Node* temp = front;
        front = front->next;
        delete temp;
        sz--;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int size() {
        return sz;
    }
};