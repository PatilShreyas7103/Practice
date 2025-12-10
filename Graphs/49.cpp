// 909. Snakes and Ladders
 
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
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        // Flattened distance array: min dice throws to reach each cell
        vector<int> dist(n*n + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // try rolling dice: 1 to 6 steps
            for (int dice = 1; dice <= 6 && curr + dice <= n*n; dice++) {
                int nextCell = curr + dice;

                // Convert nextCell index → (row, col) on zig-zag board
                int r = (nextCell - 1) / n;     // zero-based row from top
                int c = (nextCell - 1) % n;     // zero-based col from left

                // Adjust row to bottom-based indexing
                int actualRow = n - 1 - r;

                // Zigzag correction: reverse columns on odd rows
                int actualCol = (r % 2 == 1) ? (n - 1 - c) : c;

                // Value on the board (snake/ladder or normal)
                int boardValue = board[actualRow][actualCol];

                // Determine destination: snake/ladder moves you, else stay
                int finalCell = (boardValue == -1) ? nextCell : boardValue;

                // If reached the last cell, return its distance
                if (finalCell == n*n)
                    return dist[curr] + 1;

                // BFS check: first time visiting this cell
                if (dist[finalCell] == -1) {
                    dist[finalCell] = dist[curr] + 1;
                    q.push(finalCell);
                }
            }
        }

        return -1;
    }
};