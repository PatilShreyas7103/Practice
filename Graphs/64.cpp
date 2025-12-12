// Word Search 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

class Solution {
public:
    
    bool dfs(int r, int c, int id,
                vector<vector<char>> &board,
                vector<vector<int>> &vis,
                const string &word,
                const int dx[], const int dy[],
                int m, int n)
        {
            // if we matched the last character
            if (id == word.length() - 1) return true;

            vis[r][c] = 1;

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc]) {
                    // check next character
                    if (board[nr][nc] == word[id + 1]) {
                        if (dfs(nr, nc, id + 1, board, vis, word, dx, dy, m, n)) {
                            vis[r][c] = 0;     // unmark before returning success
                            return true;
                        }
                    }
                }
            }

            vis[r][c] = 0;   // backtrack
            return false;
        }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
            int n = board[0].size();

            // early pruning
            if ((int)word.length() > m * n) return 0;

            const int dx[4] = {-1, 0, 1, 0};
            const int dy[4] = {0, 1, 0, -1};

            vector<vector<int>> vis(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (board[i][j] == word[0]) {
                        if (dfs(i, j, 0, board, vis, word, dx, dy, m, n)) {
                            return 1;
                        }
                    }
                }
            }

            return 0;
    }

};

