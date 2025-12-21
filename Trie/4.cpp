// Number of Distinct Substrings in a String

#include<bits/stdc++.h>
using namespace std;

class BruteForce {
  public:
    int countSubs(string& s) {
        // code here
        int n = s.length();
        unordered_set<string> st;
        
        for(int i=0; i<n; i++)
        {
            string str = "";
            for(int j=i; j<n; j++)
            {
                str+=s[j];
                st.insert(str);
            }
        }
        
        return st.size();
    }
};

class Node {
public:
    Node* links[26];

    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
    }

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Optimal {
public:
    int countSubs(string& s) {
        int n = s.length();
        Node* root = new Node();
        int distinctCount = 0;

        for (int i = 0; i < n; i++) {
            Node* current = root;
            for (int j = i; j < n; j++) {
                if (!current->contains(s[j])) {
                    distinctCount++;
                    current->put(s[j], new Node());
                }
                current = current->get(s[j]);
            }
        }

        return distinctCount;
    }
};