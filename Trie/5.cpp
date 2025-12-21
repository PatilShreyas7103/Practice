#include <bits/stdc++.h>
using namespace std;

/*
    BRUTE FORCE APPROACH
    --------------------
    Try all possible pairs and compute XOR.
    Time Complexity: O(N^2)
    Space Complexity: O(1)
*/
class BruteForce {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int maxXor = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxXor = max(maxXor, nums[i] ^ nums[j]);
            }
        }
        return maxXor;
    }
};

/*
    OPTIMAL APPROACH (Using Binary Trie)
    -----------------------------------
    Store numbers in a binary trie and greedily try to maximize XOR.
    Time Complexity: O(N * 32)
    Space Complexity: O(N * 32)
*/
class Optimal {
private:
    class Node {
    public:
        Node* children[2] = {nullptr, nullptr};

        bool hasBit(int bit) {
            return children[bit] != nullptr;
        }

        void setBit(int bit, Node* node) {
            children[bit] = node;
        }

        Node* getBit(int bit) {
            return children[bit];
        }
    };

    class Trie {
    public:
        Node* rootNode;

        Trie() {
            rootNode = new Node();
        }

        void insertNumber(int num) {
            Node* currentNode = rootNode;
            for (int bitIndex = 31; bitIndex >= 0; bitIndex--) {
                int bit = (num >> bitIndex) & 1;
                if (!currentNode->hasBit(bit)) {
                    currentNode->setBit(bit, new Node());
                }
                currentNode = currentNode->getBit(bit);
            }
        }

        int getMaximumXor(int num) {
            Node* currentNode = rootNode;
            int maxXorValue = 0;

            for (int bitIndex = 31; bitIndex >= 0; bitIndex--) {
                int bit = (num >> bitIndex) & 1;
                if (currentNode->hasBit(1 - bit)) {
                    maxXorValue |= (1 << bitIndex);
                    currentNode = currentNode->getBit(1 - bit);
                } else {
                    currentNode = currentNode->getBit(bit);
                }
            }
            return maxXorValue;
        }
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for (int num : nums) {
            trie.insertNumber(num);
        }

        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, trie.getMaximumXor(num));
        }

        return maxXor;
    }
};