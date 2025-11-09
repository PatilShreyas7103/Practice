// 💻 Program: Copy List with Random Pointer — Both Approaches

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// ---------------------------------------------------------------
// 🧩 Approach 1: HashMap-based Deep Copy (O(n) Time, O(n) Space)
// ---------------------------------------------------------------
class HashMapSolution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> nodeMap;
        Node* current = head;

        // Step 1: Create a copy of each node and store in map
        while (current) {
            Node* copy = new Node(current->val);
            nodeMap[current] = copy;
            current = current->next;
        }

        // Step 2: Set next and random pointers
        current = head;
        while (current) {
            nodeMap[current]->next = nodeMap[current->next];
            nodeMap[current]->random = nodeMap[current->random];
            current = current->next;
        }

        // Step 3: Return the deep-copied list head
        return nodeMap[head];
    }
};

// ---------------------------------------------------------------
// ⚡ Approach 2: Optimized In-Place Interleaving (O(n) Time, O(1) Space)
// ---------------------------------------------------------------
class OptimizedSolution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Insert copied nodes between original nodes
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // Step 2: Set random pointers for the copied nodes
        current = head;
        while (current) {
            if (current->random)
                current->next->random = current->random->next;
            current = current->next->next;
        }

        // Step 3: Separate the copied list from the original
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;

        while (original) {
            original->next = original->next->next;
            copy->next = (copy->next) ? copy->next->next : nullptr;
            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};