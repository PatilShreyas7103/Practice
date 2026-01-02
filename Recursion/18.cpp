// N-Queens  

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Naive Backtracking with Safety Check
Time: O(N! * N)
Space: O(N^2)
*/
class SolutionNaive {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, int n) {
        // check left side of row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int col, vector<vector<char>> &board,
               vector<vector<string>> &res, int n) {
        if (col == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                temp.push_back(string(board[i].begin(), board[i].end()));
            }
            res.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, res, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(0, board, res, n);
        return res;
    }
};

/*
Approach 2: Optimized Backtracking using Hashing
Time: O(N!)
Space: O(N)
*/
class SolutionOptimized {
public:
    void solve(int col, vector<string> &board, int n,
               vector<int> &leftRow,
               vector<int> &upperDiagonal,
               vector<int> &lowerDiagonal,
               vector<vector<string>> &res) {

        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 &&
                lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, res);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, res);
        return res;
    }
};