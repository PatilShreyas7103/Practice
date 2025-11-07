// Intersection of Two Linked Lists (4 Approaches)

#include <iostream>
#include <unordered_set>
using namespace std;

class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};

// Approach 1: Brute force - double loop O(n^2)
node* intersectionPresentBruteForce(node* head1, node* head2) {
    while (head2 != NULL) {
        node* temp = head1;
        while (temp != NULL) {
            if (temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}

// Approach 2: Using hash set O(n+m), O(n)
node* intersectionPresentHashSet(node* head1, node* head2) {
    unordered_set<node*> st;
    while (head1 != NULL) {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        if (st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}

// Calculate length difference
int getDifference(node* head1, node* head2) {
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            ++len1; head1 = head1->next;
        }
        if (head2 != NULL) {
            ++len2; head2 = head2->next;
        }
    }
    return len1 - len2; // if negative -> list2 longer, else list1 longer
}

// Approach 3: Using length difference and pointer advances O(n+m)
node* intersectionPresentLengthDiff(node* head1, node* head2) {
    int diff = getDifference(head1, head2);
    if (diff < 0) while (diff++ != 0) head2 = head2->next;
    else while (diff-- != 0) head1 = head1->next;

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return NULL;
}

// Approach 4: Two pointer optimal O(n+m)
node* intersectionPresentTwoPointer(node* head1, node* head2) {
    node* d1 = head1;
    node* d2 = head2;

    while (d1 != d2) {
        d1 = (d1 == NULL) ? head2 : d1->next;
        d2 = (d2 == NULL) ? head1 : d2->next;
    }
    return d1; // Could be NULL or intersection node
}
