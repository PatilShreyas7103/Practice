// Flatten a linked list with child pointers

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

class Solution {
public:
    // Optimal approach: merge two sorted lists connected by child pointers
    Node* solve(Node* p, Node* q) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (p && q) {
            if (p->data < q->data) {
                temp->child = p;
                p = p->child;
            } else {
                temp->child = q;
                q = q->child;
            }
            temp->next = nullptr; // Ensure next is null in flattened list
            temp = temp->child;
        }
        if (p) {
            temp->next = nullptr;
            temp->child = p;
        }
        if (q) {
            temp->next = nullptr;
            temp->child = q;
        }

        return dummy->child;
    }

    // Flatten the list by merging from left to right (optimal)
    Node* flatten(Node* root) {
        if (!root || !root->next) {
            return root;
        }

        Node* p = root;
        Node* q = root->next;

        while (q) {
            Node* fow = q->next;
            Node* merged = solve(p, q);
            p = merged;
            q = fow;
        }

        return p;
    }

    // Brute-force approach: flatten by collecting all values, sorting, and reconstructing
    Node* flattenBruteForce(Node* root) {
        vector<int> vals;
        Node* head = root;
        while (head) {
            Node* temp = head;
            while (temp) {
                vals.push_back(temp->data);
                temp = temp->child;
            }
            head = head->next;
        }
        sort(vals.begin(), vals.end());
        return convertArrToLinkedList(vals);
    }

    // Helper to convert vector to linked list connected by child pointers
    Node* convertArrToLinkedList(const vector<int>& arr) {
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        for (int v : arr) {
            curr->child = new Node(v);
            curr = curr->child;
        }
        return dummy->child;
    }
};

