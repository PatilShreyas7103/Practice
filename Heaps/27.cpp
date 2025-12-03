// Car Pooling

#include <bits/stdc++.h>
using namespace std;

class SolutionPrefixSum {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> change(1002, 0);
        
        for (auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            
            change[start] += passengers;
            change[end] -= passengers;
        }
        
        int currentPassengers = 0;
        int maxPassengers = 0;
        
        for (int delta : change) {
            currentPassengers += delta;
            maxPassengers = max(maxPassengers, currentPassengers);
        }
        
        return maxPassengers <= capacity;
    }
};

class SolutionBruteForce {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(2001, 0);
        
        for (auto& trip : trips) {
            int numPassengers = trip[0];
            int startLocation = trip[1];
            int endLocation = trip[2];
            
            for (int location = startLocation; location < endLocation; location++) {
                passengers[location] += numPassengers;
                if (passengers[location] > capacity) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
