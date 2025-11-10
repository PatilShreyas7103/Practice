// 💻 Program: LRU Cache Implementation — Doubly Linked List + HashMap

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    // Node structure for doubly linked list
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;

    // Constructor
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head (most recently used)
    void add(Node* temp) {
        Node* curr = head->next;
        head->next = temp;
        temp->next = curr;
        curr->prev = temp;
        temp->prev = head;
    }

    // Delete a given node from the list
    void del(Node* temp) {
        Node* delPrev = temp->prev;
        Node* delNext = temp->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // Get the value of the key if present, else return -1
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            int ans = temp->val;
            mp.erase(key);
            del(temp);
            add(temp);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }

    // Insert or update (put) a key-value pair
    void put(int key, int value) {
        // If key already exists
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            mp.erase(key);
            del(temp);
        }
        // If capacity reached, remove least recently used
        else if (mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            del(lru);
        }

        // Add new node to the front (most recently used)
        Node* newNode = new Node(key, value);
        add(newNode);
        mp[key] = head->next;
    }
};