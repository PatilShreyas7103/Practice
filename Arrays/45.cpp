// Valid Sudoku

#include <vector>
using namespace std;

/*
Approach: Boolean Hashing
- Use 3 boolean matrices to track:
  1) Numbers seen in each row
  2) Numbers seen in each column
  3) Numbers seen in each 3x3 box
- If any number repeats, return false
Time: O(1)  (81 cells)
Space: O(1)
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num])
                        return false;

                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }

        return true;
    }
};