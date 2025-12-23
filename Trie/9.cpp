// Word Search II

#include <bits/stdc++.h>
using namespace std;

class BruteForce {
public:

    bool backtrack(vector<vector<char>>& board, int r, int c, string& word, int i) {
        if (i == word.length()) return true;
        if (r < 0 || c < 0 || r >= board.size() ||
            c >= board[0].size() || board[r][c] != word[i])
            return false;

        board[r][c] = '*';
        bool ret = backtrack(board, r + 1, c, word, i + 1) ||
                   backtrack(board, r - 1, c, word, i + 1) ||
                   backtrack(board, r, c + 1, word, i + 1) ||
                   backtrack(board, r, c - 1, word, i + 1);
        board[r][c] = word[i];
        return ret;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int ROWS = board.size(), COLS = board[0].size();
        vector<string> res;

        for (string& word : words) {
            bool flag = false;
            for (int r = 0; r < ROWS && !flag; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (board[r][c] != word[0]) continue;
                    if (backtrack(board, r, c, word, 0)) {
                        res.push_back(word);
                        flag = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string completeWord = "";
};

class Optimal {
private:
    TrieNode* root;

    void insertWord(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!current->children[idx]) {
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }
        current->completeWord = word;
    }

    void dfs(int row, int col,
             vector<vector<char>>& board,
             TrieNode* currentNode,
             vector<string>& result) {

        char ch = board[row][col];
        if (ch == '#') return;

        int idx = ch - 'a';
        if (!currentNode->children[idx]) return;

        currentNode = currentNode->children[idx];

        if (!currentNode->completeWord.empty()) {
            result.push_back(currentNode->completeWord);
            currentNode->completeWord.clear();
        }

        board[row][col] = '#';

        if (row > 0) dfs(row - 1, col, board, currentNode, result);
        if (col > 0) dfs(row, col - 1, board, currentNode, result);
        if (row + 1 < board.size()) dfs(row + 1, col, board, currentNode, result);
        if (col + 1 < board[0].size()) dfs(row, col + 1, board, currentNode, result);

        board[row][col] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (const string& word : words) {
            insertWord(word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(r, c, board, root, result);
            }
        }

        return result;
    }
};