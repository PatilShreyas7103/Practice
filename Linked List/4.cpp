//  Search a value in Linked List

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

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Solution class containing search function
class Solution {
public:
    // Function to search for a value in LL
    bool find(Node* head, int key) {
        // Pointer to traverse the list
        Node* current = head;

        // Traverse until end
        while (current != NULL) {
            // Check if current node matches key
            if (current->data == key) {
                // Return true if found
                return true;
            }
            // Move to next node
            current = current->next;
        }

        // Return false if not found
        return false;
    }

    // Recursive function to search for a value in Linked List
    bool searchValue(Node* head, int key) {
        // Base case: if list is empty
        if (head == NULL)
            return false;

        // If current node matches key
        if (head->data == key)
            return true;

        // Recur for remaining list
        return searchValue(head->next, key);
    }
};

// Driver code
int main() {
    // Creating linked list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Solution obj;

    // Search for value
    if (obj.searchValue(head, 20))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
