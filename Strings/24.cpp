// Reverse Vowels of a String
#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------*/
// Approach 1: Two-Pointer (Optimal)
// Idea:
// - Use two pointers i (start) and j (end)
// - Move i forward until a vowel is found
// - Move j backward until a vowel is found
// - Swap the vowels and continue
class Optimal {
public:
    bool isVowel(char ch) {
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }

    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;

            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
