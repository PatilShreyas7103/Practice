// Car Fleet

#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Sorting + Greedy (Time Comparison)
Time: O(n log n)
Space: O(n)

Idea:
- Pair each car's position with its speed.
- Sort cars by position in descending order (closest to target first).
- Compute time taken by each car to reach the target.
- If a car takes more time than the previous fleet, it forms a new fleet.
- Otherwise, it merges into the existing fleet.
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 1;
        double prevTime = (double)(target - cars[0].first) / cars[0].second;

        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - cars[i].first) / cars[i].second;
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};