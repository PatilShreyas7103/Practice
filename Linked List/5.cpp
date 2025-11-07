// Insertion in Doubly Linked List
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

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* insertAtHead(Node* head, int k) {
    Node* newNode = new Node(k);
    if (head == nullptr) return newNode;
    newNode->next = head;
    head->back = newNode;
    return newNode;
}

Node* insertAtTail(Node* head, int k) {
    Node* newNode = new Node(k);
    if (head == nullptr) return newNode;
    Node* tail = head;
    while (tail->next != nullptr) tail = tail->next;
    tail->next = newNode;
    newNode->back = tail;
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);

    head = insertAtHead(head, 2);
    cout << endl << "After Inserting at Head (2): " << endl;
    print(head);

    head = insertAtTail(head, 10);
    cout << endl << "After Inserting at Tail (10): " << endl;
    print(head);

    return 0;
}