// String Compression
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach : Optimal (In-place Two Pointers)
// Idea:
// - Use two pointers i (read) and j (write)
// - Count consecutive characters
// - Write character and its count digits in-place
class Optimal {
public:
    int compress(vector<char>& v) {
        int n = v.size();
        int i = 0, j = 0;  // i → read, j → write

        while (i < n) {
            int k = i;
            while (k < n && v[k] == v[i]) {
                k++;
            }

            int cnt = k - i;
            v[j++] = v[i];

            if (cnt > 1) {
                string num = to_string(cnt);
                for (char c : num) {
                    v[j++] = c;
                }
            }

            i = k;
        }

        return j;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/