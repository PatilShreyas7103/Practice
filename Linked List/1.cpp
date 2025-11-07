// 🧩 Linked List Implementation with Insert at Head and Tail
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

// 🌿 Node structure definition
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// 🌱 LinkedList class definition
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // 🧩 Insert a new node at the head of the list
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head; // Point new node to current head
        head = newNode;       // Update head
    }

    // 🧩 Insert a new node at the tail of the list
    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {  // If list is empty
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode; // Attach new node at the end
    }

    // 🖨️ Display the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 🧹 Destructor to free memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

// 🧪 Example driver code
int main() {
    LinkedList list;

    cout << "Inserting at head: 30, 20, 10" << endl;
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.printList();  // Expected: 10 -> 20 -> 30 -> NULL

    cout << "\nInserting at tail: 40, 50" << endl;
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.printList();  // Expected: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    return 0;
}