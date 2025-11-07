// Length of linked List

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

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Solution class containing the method to find length
class Solution {
public:
    // Function to find the length of the linked list
    int lengthOfLinkedList(Node* head) {
        // Initialize counter to 0
        int count = 0;

        // Initialize a temporary pointer to head
        Node* temp = head;

        // Traverse the linked list
        while (temp != nullptr) {
            // Increment count for each node
            count++;

            // Move to the next node
            temp = temp->next;
        }

        // Return the total count
        return count;
    }
};

int main() {
    // Creating a sample linked list
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Create Solution object
    Solution obj;

    // Find and print the length of linked list
    cout << "Length of Linked List: "
         << obj.lengthOfLinkedList(head) << endl;

    return 0;
}
