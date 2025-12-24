// Extra Characters in a String

#include <bits/stdc++.h>
using namespace std;

// Apprach 1: Memoization + set

class Memoization {
    private:
    int dfs(int i, string& s, unordered_set<string>& words, vector<int>& dp) {
        int n = s.length();
        if(i==n)
        {
            return dp[i] = 0;
        }
        if (dp[i] != -1) return dp[i];
        int res = 1 + dfs(i + 1, s, words, dp);
        for (int j = i; j < s.size(); j++) {
            if (words.count(s.substr(i, j - i + 1))) {
                res = min(res, dfs(j + 1, s, words, dp));
            }
        }
        dp[i] = res;
        return res;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return dfs(0, s, words, dp);
    }
};

// Apprach 2: Tabulation + set

class Tabulation {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];
            for (int j = i; j < n; j++) {
                if (words.count(s.substr(i, j - i + 1))) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};

// Apprach 3: Memoization + Trie

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.addWord(word);
        }

        vector<int> dp(s.size() + 1, -1);
        return dfs(0, s, trie, dp);
    }

private:
    int dfs(int i, const string& s, Trie& trie, vector<int>& dp) {
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int res = 1 + dfs(i + 1, s, trie, dp);
        TrieNode* curr = trie.root;

        for (int j = i; j < s.size(); ++j) {
            if (!curr->children[s[j] - 'a']) break;
            curr = curr->children[s[j] - 'a'];
            if (curr->isWord) {
                res = min(res, dfs(j + 1, s, trie, dp));
            }
        }

        dp[i] = res;
        return res;
    }
};


// Apprach 4: Tabultion + Trie
class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.addWord(word);
        }

        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1 + dp[i + 1];
            TrieNode* curr = trie.root;

            for (int j = i; j < n; ++j) {
                if (!curr->children[s[j] - 'a']) break;
                curr = curr->children[s[j] - 'a'];
                if (curr->isWord) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};