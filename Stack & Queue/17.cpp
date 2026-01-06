// Stack using Linked List

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Linked List Implementation
Time: O(1) for push, pop, top
Space: O(n)

Idea:
- Use a singly linked list.
- Head represents the top of the stack.
- Push and pop happen at the head for O(1) operations.
*/
class LinkedListStack {
private:
    struct Node {
        int val;
        Node* next;
        Node(int d) {
            val = d;
            next = NULL;
        }
    };

    Node* head;   // Top of stack
    int sz;       // Current size

public:
    LinkedListStack() {
        head = NULL;
        sz = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    int pop() {
        if (head == NULL) return -1;

        int res = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        sz--;
        return res;
    }

    int top() {
        if (head == NULL) return -1;
        return head->val;
    }

    bool isEmpty() {
        return sz == 0;
    }
};