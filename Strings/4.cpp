// Encode and Decode Strings

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        if(strs.empty()) return "";

        string res = "";

        for(auto &s : strs) {
            res += to_string(s.size()) + ",";
        }

        res += "#";

        for(auto &s : strs) {
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};

        vector<string> ans;
        vector<int> sizes;

        int i = 0;
        while(s[i] != '#') {
            int num = 0;
            while(s[i] != ',') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            sizes.push_back(num);
            i++;
        }

        i++;

        for(int sz : sizes) {
            ans.push_back(s.substr(i, sz));
            i += sz;
        }

        return ans;
    }
};