// Subarray XOR Equals K

#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach 1: Brute Force
- Consider all possible subarrays
- Compute XOR for each subarray
- Increment count if XOR equals k
Time: O(N^2)
Space: O(1)
*/
class SolutionBruteForce {
public:
    long subarrayXor(vector<int>& v, int k) {
        int n = v.size();
        long cnt = 0;

        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = i; j < n; j++) {
                x ^= v[j];
                if (x == k)
                    cnt++;
            }
        }

        return cnt;
    }
};

/*
Approach 2: Prefix XOR + Hash Map (Optimal)
- Maintain prefix XOR
- If (prefixXOR ^ k) exists, valid subarray found
- Store frequency of prefix XORs
Time: O(N)
Space: O(N)
*/
class SolutionOptimal {
public:
    long subarrayXor(vector<int>& v, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefixXor = 0;
        long cnt = 0;

        for (int x : v) {
            prefixXor ^= x;
            cnt += freq[prefixXor ^ k];
            freq[prefixXor]++;
        }

        return cnt;
    }
};