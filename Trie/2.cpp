// Implement Trie II

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26] = {nullptr};
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(const string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->cntPrefix;
    }

    void erase(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return;
            }
            node = node->get(ch);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apple");

    cout << "Count Words Equal to 'apple': "
         << trie.countWordsEqualTo("apple") << endl;

    cout << "Count Words Starting With 'app': "
         << trie.countWordsStartingWith("app") << endl;

    trie.erase("apple");

    cout << "Count Words Equal to 'apple': "
         << trie.countWordsEqualTo("apple") << endl;

    cout << "Count Words Starting With 'app': "
         << trie.countWordsStartingWith("app") << endl;

    trie.erase("apple");

    cout << "Count Words Starting With 'app': "
         << trie.countWordsStartingWith("app") << endl;

    return 0;
}