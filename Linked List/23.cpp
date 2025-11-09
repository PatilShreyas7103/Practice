// Find pairs with given sum in doubly linked list

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

/* Doubly linked list node class */
class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class Solution {
  public:
    // Two-pointer approach (efficient) - returns data values
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int k) {
        Node* left = head;
        Node* right = NULL;
        Node* t = head;
        vector<pair<int,int>> p;
        // Move 't' to the last node
        while(t && t->next) t = t->next; 
        right = t;
        // Find pairs
        while(left && right && left != right && left->data < right->data) {
            int sum = left->data + right->data;
            if(sum == k) {
                p.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum < k) left = left->next;
            else right = right->prev;
        }
        return p;
    }
    
};

// Brute force

class Solution1 {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<int> v;

        vector<pair<int,int>> p;
        Node* t = head;
        while(t)
        {
            v.push_back(t->data);
            t = t->next;
        }
        int n = v.size();
        map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[v[i]]++;
        }
        
        for(int i=0; i<n; i++)
        {
            int r = target-v[i];
            if(mp.find(r)!=mp.end() && r!=v[i])
            {
                p.push_back({v[i],r});
                mp.erase(r);
                mp.erase(v[i]);
            }
        }
        
        return p;
    }
};