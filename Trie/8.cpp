// Design Add and Search Words Data Structure
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[26] = {nullptr};
    bool isEnd = false;

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

class WordDictionary {
private:
    Node* root;

    bool dfs(Node* node, int index, string& word) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr) {
                    if (dfs(node->links[i], index + 1, word)) {
                        return true;
                    }
                }
            }
            return false;
        }

        if (!node->contains(ch)) {
            return false;
        }

        return dfs(node->get(ch), index + 1, word);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->contains(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, 0, word);
    }
};