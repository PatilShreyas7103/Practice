// Two Stacks in an Array

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Two Stacks Using a Single Array
Time: O(1) for all operations
Space: O(n)

Idea:
- Use one array of size n.
- Stack1 grows from left to right.
- Stack2 grows from right to left.
- Prevent overflow by checking top1 < top2 - 1.
*/
class twoStacksArray {
private:
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacksArray(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        }
        return -1;
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        }
        return -1;
    }
};

/*
Approach 2: Using Deque
Time: O(1) for all operations
Space: O(n)

Idea:
- Use deque where:
  - Stack1 operates on the front.
  - Stack2 operates on the back.
- Maintain separate counters for both stacks.
*/
class twoStacksDeque {
public:
    deque<int> dq;
    int n1, n2;

    twoStacksDeque() {
        n1 = 0;
        n2 = 0;
    }

    void push1(int x) {
        dq.push_front(x);
        n1++;
    }

    void push2(int x) {
        dq.push_back(x);
        n2++;
    }

    int pop1() {
        if (n1 == 0) return -1;
        int val = dq.front();
        dq.pop_front();
        n1--;
        return val;
    }

    int pop2() {
        if (n2 == 0) return -1;
        int val = dq.back();
        dq.pop_back();
        n2--;
        return val;
    }
};