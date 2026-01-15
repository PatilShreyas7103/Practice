// Integer to Roman

#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";

        map<int, string> mp;
        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";

        vector<int> v = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        for (int val : v) {
            while (num >= val) {
                ans += mp[val];
                num -= val;
            }
        }

        return ans;
    }
};