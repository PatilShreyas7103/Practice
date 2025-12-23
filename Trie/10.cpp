// Search Suggestions System 

#include <bits/stdc++.h>
using namespace std;

/* ===================== TRIE APPROACH ===================== */

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!current->children[idx]) {
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }
        current->isWord = true;
    }

    void dfs(TrieNode* node, string& current, vector<string>& result) {
        if (result.size() == 3) return;

        if (node->isWord) {
            result.push_back(current);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int idx = ch - 'a';
            if (node->children[idx]) {
                current.push_back(ch);
                dfs(node->children[idx], current, result);
                current.pop_back();
            }
        }
    }

    vector<string> getSuggestions(const string& prefix) {
        TrieNode* current = root;
        vector<string> result;
        string word = "";

        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!current->children[idx]) {
                return result;
            }
            word.push_back(ch);
            current = current->children[idx];
        }

        dfs(current, word, result);
        return result;
    }
};

class SolutionTrie {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (const string& product : products) {
            trie.insert(product);
        }

        vector<vector<string>> answer;
        string prefix = "";

        for (char ch : searchWord) {
            prefix.push_back(ch);
            answer.push_back(trie.getSuggestions(prefix));
        }

        return answer;
    }
};

/* ===================== TWO POINTER APPROACH ===================== */

class SolutionTwoPointer {
public:
    bool isPrefix(const string& prefix, const string& word) {
        if (word.size() < prefix.size()) return false;
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != word[i]) return false;
        }
        return true;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        int n = products.size();
        int left = 0, right = n - 1;
        vector<vector<string>> result;

        string prefix = "";

        for (char ch : searchWord) {
            prefix.push_back(ch);

            while (left <= right && !isPrefix(prefix, products[left])) {
                left++;
            }
            while (left <= right && !isPrefix(prefix, products[right])) {
                right--;
            }

            vector<string> current;
            for (int i = left; i < min(left + 3, right + 1); i++) {
                current.push_back(products[i]);
            }

            result.push_back(current);
        }

        return result;
    }
};