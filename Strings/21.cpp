// Zigzag Conversion 
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Optimal Approach (Row-wise Simulation using Direction)
// Idea:
// - Maintain current row and direction
// - Move down until last row, then move up
// - Store characters row-wise
// - Concatenate all rows at the end
class Optimal {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);
        int idx = 0, dir = 1;

        for (char c : s) {
            rows[idx].push_back(c);

            if (idx == 0)
                dir = 1;
            else if (idx == numRows - 1)
                dir = -1;

            idx += dir;
        }

        string ans = "";
        for (auto &row : rows)
            ans += row;

        return ans;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/