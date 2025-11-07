// Segregate 0s, 1s, and 2s in Linked List

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    // Segregate nodes into 0s, 1s, and 2s - using three pointer approach
    Node* segregate(Node* head) {
        Node* a1 = new Node(-1);
        Node* a2 = a1;
        Node* b1 = new Node(-1);
        Node* b2 = b1;
        Node* c1 = new Node(-1);
        Node* c2 = c1;

        Node* t = head;

        while(t) {
            if(t->data == 0) {
                a2->next = t;
                a2 = a2->next;
            } else if(t->data == 1) {
                b2->next = t;
                b2 = b2->next;
            } else {
                c2->next = t;
                c2 = c2->next;
            }
            t = t->next;
        }
        
        // Connect the three lists
        b2->next = c1->next;
        a2->next = b1->next;
        c2->next = nullptr;

        Node* newHead = a1->next;
        // Delete dummy nodes to avoid memory leaks
        delete a1;
        delete b1;
        delete c1;

        return newHead;
    }

    // Brute force approach: Use counting and reconstruct list
    Node* segregateCounting(Node* head) {
        int count0 = 0, count1 = 0, count2 = 0;
        Node* temp = head;

        while(temp) {
            if(temp->data == 0) count0++;
            else if(temp->data == 1) count1++;
            else count2++;
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            if(count0) {
                temp->data = 0;
                count0--;
            } else if(count1) {
                temp->data = 1;
                count1--;
            } else {
                temp->data = 2;
                count2--;
            }
            temp = temp->next;
        }

        return head;
    }
};
