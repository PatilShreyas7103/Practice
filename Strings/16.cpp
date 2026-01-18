// Count and Say (Brute Force + Optimal)
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Optimal Approach (Iterative Simulation)
// Idea:
// - Start from "1"
// - Repeat n-1 times
// - For each iteration, group same characters
// - Append count + character to form next term
class Optimal {
public:
    string countAndSay(int n) {
        string curr = "1";

        while (--n) {
            string temp = "";
            for (int i = 0; i < curr.length(); ) {
                char ch = curr[i];
                int cnt = 0;

                while (i < curr.length() && curr[i] == ch) {
                    cnt++;
                    i++;
                }

                temp += to_string(cnt);
                temp += ch;
            }
            curr = temp;
        }
        return curr;
    }
};

/*
Time Complexity: O(n * L)
Space Complexity: O(1) extra (excluding output)
*/