// 💻 Program: Delete all occurrences of a given key (x) from a Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node definition
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Solution class with deleteAllOccurOfX function
class Solution {
public:
    void deleteAllOccurOfX(Node** head_ref, int x) {
        Node* curr = *head_ref;

        // Handle all occurrences of x at the head
        while (curr && curr->data == x) {
            Node* temp = curr;
            curr = curr->next;
            if (curr) curr->prev = NULL;
            delete temp;
        }

        *head_ref = curr;

        while (curr) {
            if (curr->data == x) {
                Node* temp = curr;
                Node* prevNode = curr->prev;
                Node* nextNode = curr->next;

                if (prevNode) prevNode->next = nextNode;
                if (nextNode) nextNode->prev = prevNode;

                curr = nextNode;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }
};
