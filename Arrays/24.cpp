// Pascal's Triangle

#include <vector>
using namespace std;

/*
Approach 1: Dynamic Programming (Row by Row)
- First and last element of every row is 1
- Inner elements are sum of two elements from previous row
Time: O(N^2)
Space: O(N^2)
*/
class SolutionDP {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};

/*
Approach 2: Mathematical (nCr Formula) — Optimal
- Each row is generated using combination formula
- nCr = nC(r-1) * (n-r+1) / r
- No dependency on previous rows
Time: O(N^2)
Space: O(N^2)
*/
class SolutionNCR {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> row;
            long long val = 1;

            for (int j = 0; j <= i; j++) {
                row.push_back(val);
                val = val * (i - j) / (j + 1);
            }

            ans.push_back(row);
        }

        return ans;
    }
};