// Length of Loop in Linked List

#include <iostream>
#include <map>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// ----------- Approach 1: Using a Map -----------
class SolutionMap {
public:
    int lengthOfLoop(Node* head) {
        int ans = 0;
        Node* temp = head;
        map<Node*, int> mp;
        while (temp) {
            mp[temp]++;
            if(mp[temp] == 2) {
                ans++;
            }
            if(mp[temp] > 2) {
                break;
            }
            temp = temp->next;
        }
        return ans;
    }
};

// ----------- Approach 2: Floyd's Cycle Algorithm -----------
class SolutionFloyd {
public:
    int lengthOfLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return countLoopLength(slow);
            }
        }
        return 0;
    }

    int countLoopLength(Node* meetingPoint) {
        Node* temp = meetingPoint;
        int length = 1;
        while (temp->next != meetingPoint) {
            temp = temp->next;
            length++;
        }
        return length;
    }
};

// Optionally, add your test cases and main() function below.
