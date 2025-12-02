// Top k most frequent elements (Sort + Min-Heap Approaches)

#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

class Solution_Sort {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        map<int,int> mp;
        for(auto it: v) {
            mp[it]++;
        }

        vector<pair<int,int>> p;
        for(auto it: mp) {
            p.push_back({it.second, it.first});
        }

        // Sort by frequency in descending order
        sort(p.rbegin(), p.rend()); 
        
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(p[i].second);
        }

        return ans;
    }
};

typedef pair<int,int> pi;

class Solution_MinHeap {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pi,vector<pi>, greater<pi>> pq;
        map<int,int> mp;
        for(auto it: v) {
            mp[it]++;
        }

        for(auto it: mp) {
            // Push {frequency, element}
            pq.push({it.second, it.first}); 
            
            // Maintain a heap size of exactly K
            if(pq.size()>k) {
                // Remove the smallest frequency element (the root of the Min Heap)
                pq.pop(); 
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};