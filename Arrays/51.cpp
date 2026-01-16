// Valid Anagram

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Frequency Array
- Count characters of both strings
- Increment for s, decrement for t
*/
class SolutionFreq {
public:
    bool isAnagram(string s, string t) {
        vector<int> f(26, 0);

        for (char c : s)
            f[c - 'a']++;

        for (char c : t)
            f[c - 'a']--;

        for (int x : f) {
            if (x != 0)
                return false;
        }

        return true;
    }
};

/*
Approach 2: Sorting
- Sort both strings and compare
*/
class SolutionSort {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};