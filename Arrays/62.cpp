// Wave Array 
#include <bits/stdc++.h>
using namespace std;

// Optimal Approach (Single Pass after Sort)
class Optimal {
public:
    vector<int> waveArray(vector<int> &A) {
        sort(A.begin(), A.end());   // ensures lexicographically smallest result

        for (int i = 0; i + 1 < A.size(); i += 2) {
            swap(A[i], A[i + 1]);
        }
        return A;
    }
};