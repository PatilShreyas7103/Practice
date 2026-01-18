// Text Justification
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            vector<string> line;
            int length = 0;

            // pack words into current line
            while (i < n && length + words[i].size() + line.size() <= maxWidth) {
                line.push_back(words[i]);
                length += words[i].size();
                i++;
            }

            int gaps = line.size() - 1;
            string currLine = "";

            // last line OR single word line → left justified
            if (i == n || gaps == 0) {
                for (int k = 0; k < line.size(); k++) {
                    currLine += line[k];
                    if (k != line.size() - 1)
                        currLine += " ";
                }
                currLine += string(maxWidth - currLine.size(), ' ');
            }
            // fully justified line
            else {
                int totalSpaces = maxWidth - length;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = 0; k < line.size(); k++) {
                    currLine += line[k];
                    if (k < gaps) {
                        currLine += string(spaceEach, ' ');
                        if (extra > 0) {
                            currLine += " ";
                            extra--;
                        }
                    }
                }
            }

            res.push_back(currLine);
        }

        return res;
    }
};