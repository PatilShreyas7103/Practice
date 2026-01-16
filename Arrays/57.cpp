// Range Sum Query 2D - Immutable

#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> pref;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        pref.assign(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j] =
                    matrix[i-1][j-1]
                    + pref[i-1][j]
                    + pref[i][j-1]
                    - pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return pref[r2+1][c2+1]
             - pref[r1][c2+1]
             - pref[r2+1][c1]
             + pref[r1][c1];
    }
};