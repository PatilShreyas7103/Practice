// Reverse a Doubly Linked List using two methods

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

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};


// Method 1: In-place pointer reversal
Node* reverseDLL_Pointer(Node* head) {
    if (!head || !head->next) return head;

    Node* prev = nullptr;
    Node* current = head;
    Node* forward = nullptr;

    while (current) {
        forward = current->next;   // Store next node
        current->next = prev;      // Reverse next pointer
        current->back = forward;   // Reverse back pointer
        prev = current;            // Move prev ahead
        current = forward;         // Move current ahead
    }

    return prev; // prev becomes new head
}

// Method 2: Stack-based reversal
Node* reverseDLL_Stack(Node* head) {
    if (!head || !head->next) return head;
    stack<int> st;
    Node* temp = head;
    while (temp) {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
