// Prefix match with other strings

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach

class BruteForce {
  public:
    bool prefix(string p, string q, int k)
    {
        int m = p.length();
        int n = q.length();
        
        if(m<k)
        {
            return false;
        }
        int i = 0;
        while(k--)
        {
            if(p[i]!=q[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    int klengthpref(string arr[], int n, int k, string str) {
        
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            string s = arr[i];
            bool check = prefix(s,str,k);
            if(check)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};

// Trie approach

class Node
{
    public:
    Node* links[26];
    int prefix;
    int end;
    
    Node()
    {
        for(int i=0; i<26; i++)
        {
            links[i] = nullptr;
            prefix = 0;
            end = 0;
        }
    }
    
};

class Trie
{
    public:
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(string s)
    {
        Node* node = root;
        for(char ch:s)
        {
            int id = ch-'a';
            if(!node->links[id])
            {
                node->links[id] = new Node();
            }
            node = node->links[id];
            node->prefix = node->prefix+1;
        }
        node->end = node->end+1;
    }
};

class Solution {
  public:
    int solve(int k, string &str, Trie trie)
    {
        Node* node = trie.root;
        
        for(int i=0; i<k; i++)
        {
            char ch = str[i];
            int id = ch-'a';
            if(!node->links[id])
            {
                return 0;
            }
            node = node->links[id];
        }
        
        return node->prefix;
    }
    int klengthpref(string arr[], int n, int k, string str) {
        Trie trie;
        
        for(int i=0; i<n; i++)
        {
            string s = arr[i];
            trie.insert(s);
        }
        
        int cnt = solve(k, str,trie);
        
        return cnt;
    }
    
    
    
};