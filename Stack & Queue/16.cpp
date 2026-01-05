// LRU Cache

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Doubly Linked List + Hash Map
Time: O(1) for get() and put()
Space: O(capacity)

Idea:
- Use a doubly linked list to maintain usage order (most recent at front).
- Use an unordered_map to get node address in O(1).
- On access/update, move node to front.
- On overflow, remove least recently used node (from tail).
*/
class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    int cap;
    unordered_map<int, node*> mp;
    node* head;
    node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void add(node* temp) {
        node* curr = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = curr;
        curr->prev = temp;
    }

    void del(node* temp) {
        node* p = temp->prev;
        node* n = temp->next;
        p->next = n;
        n->prev = p;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        node* t = mp[key];
        int ans = t->val;

        del(t);
        add(t);

        mp[key] = head->next;
        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node* t = mp[key];
            mp.erase(key);
            del(t);
        } else if (mp.size() == cap) {
            node* lru = tail->prev;
            mp.erase(lru->key);
            del(lru);
        }

        node* n = new node(key, value);
        add(n);
        mp[key] = head->next;
    }
};