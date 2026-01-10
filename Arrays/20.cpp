// Set Matrix Zeroes

#include <vector>
#include <unordered_set>
using namespace std;

/*
Approach 1: Brute Force (Marking with Extra Value)
- If a cell is 0, mark its entire row and column with -1
- In second pass, convert -1 to 0
Time: O((M*N)*(M+N))
Space: O(1)
*/
class SolutionBruteForce {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int col = 0; col < n; col++)
                        if (matrix[i][col] != 0)
                            matrix[i][col] = -1;

                    for (int row = 0; row < m; row++)
                        if (matrix[row][j] != 0)
                            matrix[row][j] = -1;
                }
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
    }
};

/*
Approach 2: Using Row & Column Sets
- Store rows and columns containing 0
- Zero out those rows and columns
Time: O(M*N)
Space: O(M + N)
*/
class SolutionUsingSets {
public:
    void setZeroes(vector<vector<int>>& v) {
        unordered_set<int> row, col;
        int m = v.size(), n = v[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (int r : row)
            for (int j = 0; j < n; j++)
                v[r][j] = 0;

        for (int c : col)
            for (int i = 0; i < m; i++)
                v[i][c] = 0;
    }
};

/*
Approach 3: Optimal (First Row & Column as Markers)
- Use first row and column to mark zero rows/columns
- Use two flags for first row and first column
Time: O(M*N)
Space: O(1)
*/
class SolutionOptimal {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                firstRowZero = true;

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                firstColZero = true;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (firstRowZero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};