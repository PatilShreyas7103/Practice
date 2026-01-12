// Rotate Matrix by 90 Degrees Clockwise

#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Using Extra Matrix
- Create a new matrix
- Place each element at its rotated position
- Copy rotated matrix back
Time: O(N^2)
Space: O(N^2)
*/
class SolutionExtraSpace {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        matrix = rotated;
    }
};

/*
Approach 2: Optimal (In-place)
- Transpose the matrix
- Reverse each row
Time: O(N^2)
Space: O(1)
*/
class SolutionOptimal {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(v[i][j], v[j][i]);
            }
        }

        for (auto &row : v) {
            reverse(row.begin(), row.end());
        }
    }
};