// Implement Queue using Stacks

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Two Stacks (Push Costly)
Time:
- push(): O(n)
- pop(): O(1)
- peek(): O(1)
- empty(): O(1)
Space: O(n)

Idea:
- Maintain the queue order inside a single stack (`input`).
- On push(x):
  1. Move all elements from input → output
  2. Push x into input
  3. Move everything back from output → input
- This ensures the front of the queue is always at the top of `input`.
*/
class MyQueue {
public:
    stack<int> input, output;

    MyQueue() {}

    void push(int x) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }

        input.push(x);

        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
    }

    int pop() {
        int val = input.top();
        input.pop();
        return val;
    }

    int peek() {
        return input.top();
    }

    bool empty() {
        return input.empty();
    }
};