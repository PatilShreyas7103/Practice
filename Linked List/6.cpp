// Deletion in Doubly Linked List (All Cases)

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
#include <bits/stdc++.h>
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
};

Node* deleteNode(Node* head, int pos) {
    if (head == nullptr) return nullptr;

    // Case 1: Single node in the list
    if (head->next == nullptr && pos == 1) {
        delete head;
        return nullptr;
    }

    // Case 2: Delete head node
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        head->back = nullptr;
        delete temp;
        return head;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the node to be deleted
    while (temp && cnt < pos) {
        temp = temp->next;
        cnt++;
    }

    if (!temp) return head; // Invalid position

    // Case 3: Delete tail node
    if (temp->next == nullptr) {
        temp->back->next = nullptr;
        delete temp;
        return head;
    }

    // Case 4: Delete middle node
    Node* prevNode = temp->back;
    Node* nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->back = prevNode;

    delete temp;
    return head;
}
