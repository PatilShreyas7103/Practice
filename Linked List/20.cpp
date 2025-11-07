// 🧩 Add One to Number Represented by Linked List — All 3 Approaches

#include <bits/stdc++.h>
using namespace std;
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

// ✅ Definition for singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    // ------------------------------------------------------------------
    // 🔹 Approach 1: Recursive Helper (adds from the end)
    int addOneUtil(Node* node) {
        if (!node) return 1;  // carry = 1 for the last null
        int carry = addOneUtil(node->next);
        int sum = node->data + carry;
        node->data = sum % 10;
        return sum / 10;
    }

    Node* addOneRecursive(Node* head) {
        if (!head) return new Node(1);
        int carry = addOneUtil(head);
        if (carry) {
            Node* newHead = new Node(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }

    // ------------------------------------------------------------------
    // 🔹 Approach 2: Iterative (without reversing)
    Node* addOneIterative(Node* head) {
        if (!head) return new Node(1);

        Node* lastNotNine = nullptr;
        Node* curr = head;

        while (curr) {
            if (curr->data != 9) lastNotNine = curr;
            curr = curr->next;
        }

        // All digits are 9
        if (!lastNotNine) {
            Node* newHead = new Node(1);
            newHead->next = head;
            curr = head;
            while (curr) {
                curr->data = 0;
                curr = curr->next;
            }
            return newHead;
        }

        // Increase the rightmost non-9 by 1
        lastNotNine->data += 1;
        curr = lastNotNine->next;
        while (curr) {
            curr->data = 0;
            curr = curr->next;
        }

        return head;
    }

    // ------------------------------------------------------------------
    // 🔹 Approach 3: Reverse-Add-Reverse method
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addOneReverse(Node* head) {
        if (!head) return new Node(1);

        Node* revHead = reverseList(head);
        Node* curr = revHead;
        int carry = 1;
        Node* prev = nullptr;

        while (curr && carry) {
            curr->data += carry;
            if (curr->data >= 10) {
                curr->data %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            prev = curr;
            curr = curr->next;
        }

        if (carry) prev->next = new Node(1);
        return reverseList(revHead);
    }
};

// ------------------------------------------------------------------
// Utility functions
void printList(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

Node* appendNode(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    return head;
}

// ------------------------------------------------------------------
// 🧪 Driver Code
int main() {
    Solution sol;

    // Recursive
    Node* headRec = nullptr;
    headRec = appendNode(headRec, 1);
    headRec = appendNode(headRec, 2);
    headRec = appendNode(headRec, 9);

    cout << "Original (Recursive): ";
    printList(headRec);
    Node* resRec = sol.addOneRecursive(headRec);
    cout << "After +1 (Recursive): ";
    printList(resRec);
    cout << endl;

    // Iterative (Non-Reverse)
    Node* headIter = nullptr;
    headIter = appendNode(headIter, 1);
    headIter = appendNode(headIter, 2);
    headIter = appendNode(headIter, 9);

    cout << "Original (Iterative): ";
    printList(headIter);
    Node* resIter = sol.addOneIterative(headIter);
    cout << "After +1 (Iterative): ";
    printList(resIter);
    cout << endl;

    // Reverse-Based
    Node* headRev = nullptr;
    headRev = appendNode(headRev, 1);
    headRev = appendNode(headRev, 2);
    headRev = appendNode(headRev, 9);
    headRev = appendNode(headRev, 9);

    cout << "Original (Reverse): ";
    printList(headRev);
    Node* resRev = sol.addOneReverse(headRev);
    cout << "After +1 (Reverse): ";
    printList(resRev);

    return 0;
}