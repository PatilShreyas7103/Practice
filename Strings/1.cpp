// Length of Last Word

#include <string>
using namespace std;

/*
Approach: Backward Traversal
- Skip trailing spaces
- Count characters until next space or start
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int id = s.length() - 1;
        int len = 0;

        while (id >= 0 && s[id] == ' ')
            id--;

        while (id >= 0 && s[id] != ' ') {
            len++;
            id--;
        }

        return len;
    }
};