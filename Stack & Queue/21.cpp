// Implement Stack using Queue

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Single Queue (Push Costly)
Time:
- push(): O(n)
- pop(): O(1)
- top(): O(1)
- empty(): O(1)
Space: O(n)

Idea:
- Use one queue.
- On push(x), first push x, then rotate the previous elements
  so that x comes to the front.
- Front of the queue always represents the stack top.
*/
class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};