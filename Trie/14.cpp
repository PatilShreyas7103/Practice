// Shortest Unique prefix for every word

#include <bits/stdc++.h>
using namespace std;

// APPROACH : TRIE

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
    
    void insert(string &s)
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
    string solve(string &s, Trie &trie)
    {
        Node* node = trie.root;
        string curr = "";
        for(char ch: s)
        {
            int id = ch-'a';
            
            if(node->prefix==1)
            {
                return curr;
            }
            curr+= ch;
            node = node->links[id];
        }
        return curr;
    }
    
    vector<string> findPrefixes(string arr[], int n) {
        // code here
        Trie trie;
        vector<string> res;
        
        for(int i=0; i<n; i++)
        {
            string s = arr[i];
            trie.insert(s);
        }
        
        for(int i=0; i<n; i++)
        {
            string s = arr[i];
            string ans = solve(s,trie);
            res.push_back(ans);
        }
        
        return res;
    }
};

 // APPROACH : SORTING + PREFIX

class Solution {
public:
    int commonPrefixLength(const string& a, const string& b) {
        int len = min(a.size(), b.size());
        int i = 0;
        while (i < len && a[i] == b[i]) {
            i++;
        }
        return i;
    }

    vector<string> findPrefixes(string arr[], int n) {
        vector<string> words(arr, arr + n);
        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end());

        unordered_map<string, string> answer;

        for (int i = 0; i < n; i++) {
            int lcpPrev = 0, lcpNext = 0;

            if (i > 0) {
                lcpPrev = commonPrefixLength(sortedWords[i], sortedWords[i - 1]);
            }
            if (i < n - 1) {
                lcpNext = commonPrefixLength(sortedWords[i], sortedWords[i + 1]);
            }

            int prefixLen = max(lcpPrev, lcpNext) + 1;
            answer[sortedWords[i]] = sortedWords[i].substr(0, prefixLen);
        }

        vector<string> result;
        for (int i = 0; i < n; i++) {
            result.push_back(answer[arr[i]]);
        }

        return result;
    }
};