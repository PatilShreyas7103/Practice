// Single Non-Repeating Element in Array

#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach 1: Brute Force
- For each element, count its occurrences using nested loops
- Element with frequency 1 is the answer
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i])
                    cnt++;
            }
            if (cnt == 1)
                return arr[i];
        }

        return -1;
    }
};

/*
Approach 2: Frequency Map
- Store frequency of each element using hash map
- Element with frequency 1 is the answer
Time: O(N)
Space: O(N)
*/
class SolutionMap {
public:
    int getSingleElement(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr)
            freq[x]++;

        for (int x : arr) {
            if (freq[x] == 1)
                return x;
        }

        return -1;
    }
};

/*
Approach 3: XOR Method (Optimal)
- XOR of identical elements becomes 0
- XOR with 0 gives the number itself
- Final XOR result is the single element
Time: O(N)
Space: O(1)
*/
class SolutionXOR {
public:
    int getSingleElement(vector<int>& arr) {
        int xorr = 0;

        for (int x : arr)
            xorr ^= x;

        return xorr;
    }
};