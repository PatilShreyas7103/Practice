// Minimum swaps to sort an array

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

// Function to find minimum swaps to sort array
int minSwaps(vector<int>& arr) {
    int n = arr.size();

    // Pair each element with its original index
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {arr[i], i};
    }

    // Sort based on values
    sort(v.begin(), v.end());

    vector<int> visited(n, 0);
    int swaps = 0;

    // Detect cycles
    for (int i = 0; i < n; i++) {
        // Already visited or already in correct position
        if (visited[i] || v[i].second == i)
            continue;

        int cycleSize = 0;
        int j = i;

        // Count nodes in cycle
        while (!visited[j]) {
            visited[j] = 1;
            j = v[j].second;  
            cycleSize++;
        }

        // If cycle of size k → k-1 swaps
        if (cycleSize > 1)
            swaps += (cycleSize - 1);
    }

    return swaps;
}