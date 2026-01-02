// Rat in a Maze

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int r, int c, int n) {
        return (r >= 0 && c >= 0 && r < n && c < n);
    }

    void solve(int r, int c, int n,
               vector<vector<int>>& v,
               vector<vector<int>>& vis,
               vector<string>& ans,
               string curr,
               int dx[], int dy[]) {

        if (r == n - 1 && c == n - 1) {
            ans.push_back(curr);
            return;
        }

        vis[r][c] = 1;

        string dir = "URDL";

        for (int i = 0; i < 4; i++) {
            int adjr = r + dx[i];
            int adjc = c + dy[i];

            if (isValid(adjr, adjc, n) &&
                v[adjr][adjc] == 1 &&
                !vis[adjr][adjc]) {

                solve(adjr, adjc, n, v, vis,
                      ans, curr + dir[i], dx, dy);
            }
        }

        vis[r][c] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& v) {
        int n = v.size();
        vector<string> ans;

        if (v[0][0] == 0 || v[n - 1][n - 1] == 0) {
            return ans;
        }

        vector<vector<int>> vis(n, vector<int>(n, 0));

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        solve(0, 0, n, v, vis, ans, "", dx, dy);
        return ans;
    }
};