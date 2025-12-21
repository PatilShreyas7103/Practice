// Longest Valid Word with All Prefixes

#include<bits/stdc++.h>
using namespace std;

struct Node {
public:
    Node* children[26] = {nullptr};
    bool isWordEnd = false;

    bool hasChild(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    void addChild(char ch, Node* node) {
        children[ch - 'a'] = node;
    }

    Node* getChild(char ch) {
        return children[ch - 'a'];
    }

    void markWordEnd() {
        isWordEnd = true;
    }

    bool isEndOfWord() {
        return isWordEnd;
    }

    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    }
};

class Trie {
public:
    Node* rootNode;

    Trie() {
        rootNode = new Node();
    }

    ~Trie() {
        delete rootNode;
    }

    void insertWord(const string& word) {
        Node* currentNode = rootNode;
        for (char ch : word) {
            if (!currentNode->hasChild(ch)) {
                currentNode->addChild(ch, new Node());
            }
            currentNode = currentNode->getChild(ch);
        }
        currentNode->markWordEnd();
    }

    bool searchWord(const string& word) {
        Node* currentNode = rootNode;
        for (char ch : word) {
            if (!currentNode->hasChild(ch)) {
                return false;
            }
            currentNode = currentNode->getChild(ch);
        }
        return currentNode->isEndOfWord();
    }

    bool startsWithPrefix(const string& prefix) {
        Node* currentNode = rootNode;
        for (char ch : prefix) {
            if (!currentNode->hasChild(ch)) {
                return false;
            }
            currentNode = currentNode->getChild(ch);
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        int maxLength = 0;
        string bestWord = "";

        Trie* trie = new Trie();

        for (const string& word : words) {
            trie->insertWord(word);
        }

        for (const string& word : words) {
            string prefix = "";
            bool isValid = true;

            for (char ch : word) {
                prefix += ch;
                if (!trie->searchWord(prefix)) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                if (word.length() > maxLength) {
                    maxLength = word.length();
                    bestWord = word;
                } else if (word.length() == maxLength && word < bestWord) {
                    bestWord = word;
                }
            }
        }

        delete trie;
        return bestWord;
    }
};