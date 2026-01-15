// Game of Life (In-Place)

#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Direction vectors
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        // First pass: mark transitions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;

                for (int d = 0; d < 8; d++) {
                    int r = i + dx[d];
                    int c = j + dy[d];

                    if (isValid(r, c, m, n) &&
                        (board[r][c] == 1 || board[r][c] == -1)) {
                        live++;
                    }
                }

                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = -1; // live → dead
                } else {
                    if (live == 3)
                        board[i][j] = 2;  // dead → live
                }
            }
        }

        // Second pass: finalize states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};