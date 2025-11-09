// 💻 Program: Remove duplicates from a sorted Doubly Linked List

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

// Doubly Linked List Node definition
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// Solution class
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if (!head || !head->next)
            return head;

        Node* curr = head;
        Node* fow = head->next;

        while (fow) {
            while (fow && fow->data == curr->data) {
                fow = fow->next;
            }
            if (fow) {
                fow->prev = curr;
                curr->next = fow;
                curr = fow;
                fow = fow->next;
            } else {
                curr->next = NULL; // Important: terminate the list
            }
        }

        return head;
    }
};

