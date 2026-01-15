// H-Index

#include <vector>
using namespace std;

/*
Approach: Counting / Bucket Sort
- Use buckets to count number of papers with given citations
- Any citation greater than n is capped to n
- Traverse from high to low to find maximum h
Time: O(N)
Space: O(N)
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n + 1, 0);

        for (int c : citations) {
            bucket[min(c, n)]++;
        }

        int papers = 0;
        for (int h = n; h >= 0; h--) {
            papers += bucket[h];
            if (papers >= h)
                return h;
        }

        return 0;
    }
};