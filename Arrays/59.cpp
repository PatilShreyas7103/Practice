// Largest Number
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int x : nums) {
            v.push_back(to_string(x));
        }

        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] + v[j] < v[j] + v[i]) {
                    swap(v[i], v[j]);
                }
            }
        }

        if (v[0] == "0") return "0";

        string ans = "";
        for (auto &s : v) {
            ans += s;
        }
        return ans;
    }
};