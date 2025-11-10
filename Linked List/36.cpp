// 💻 Program: Design HashMap — Custom Implementation Using Separate Chaining

#include <bits/stdc++.h>
using namespace std;

// Node structure for separate chaining
class Node {
public:
    int key;
    int val;
    Node* next;

    Node(int k = -1, int v = -1, Node* n = nullptr) : key(k), val(v), next(n) {}
};

// ---------------------------------------------------------------
// 🧩 Custom HashMap Implementation (Separate Chaining)
// ---------------------------------------------------------------
class MyHashMap {
private:
    vector<Node*> map;

public:
    // Constructor to initialize hash map with 1000 buckets
    MyHashMap() {
        map.resize(1000);
        for (int i = 0; i < 1000; ++i) {
            map[i] = new Node(); // dummy head node for each bucket
        }
    }

    // Hash function
    int hash(int key) {
        return key % 1000;
    }

    // Insert or update a key-value pair
    void put(int key, int value) {
        int hash_key = hash(key);
        Node* curr = map[hash_key];

        while (curr->next) {
            if (curr->next->key == key) {
                curr->next->val = value; // update existing key
                return;
            }
            curr = curr->next;
        }

        // Insert new node if key not found
        curr->next = new Node(key, value);
    }

    // Retrieve value for a given key
    int get(int key) {
        int hash_key = hash(key);
        Node* curr = map[hash_key];

        while (curr->next) {
            if (curr->next->key == key) {
                return curr->next->val;
            }
            curr = curr->next;
        }

        return -1; // key not found
    }

    // Remove a key-value pair if exists
    void remove(int key) {
        int hash_key = hash(key);
        Node* curr = map[hash_key];

        while (curr->next) {
            if (curr->next->key == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};