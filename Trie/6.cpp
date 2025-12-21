// Maximum XOR With an Element From Array

#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* links[2];

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    TrieNode* get(int bit) {
        return links[bit];
    }

    void put(int bit, TrieNode* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result(queries.size());
        vector<tuple<int, int, int>> offlineQueries;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < queries.size(); ++i) {
            offlineQueries.emplace_back(queries[i][1], queries[i][0], i);
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        int idx = 0;
        int n = nums.size();

        for (auto& [mi, xi, qi] : offlineQueries) {
            while (idx < n && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }
            if (idx == 0) {
                result[qi] = -1;
            } else {
                result[qi] = trie.getMaxXor(xi);
            }
        }

        return result;
    }
};
