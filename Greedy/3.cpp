// Lemonade Change

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Track number of ₹5 and ₹10 bills.
- For each customer:
  * If bill is 5 → take it.
  * If bill is 10 → give one 5 as change.
  * If bill is 20 → prefer giving 10+5, else give three 5s.
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& v) {
        int f5 = 0, f10 = 0;

        for (int bill : v) {
            if (bill == 5) {
                f5++;
            }
            else if (bill == 10) {
                if (f5 == 0) return false;
                f5--;
                f10++;
            }
            else { // bill == 20
                if (f10 > 0 && f5 > 0) {
                    f10--;
                    f5--;
                }
                else if (f5 >= 3) {
                    f5 -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/