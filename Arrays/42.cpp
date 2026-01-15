// Insert Delete GetRandom O(1)

#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

/*
Approach: Hash Map + Dynamic Array
- Use vector to store elements for O(1) random access
- Use hash map to store value -> index mapping
- For deletion, swap with last element and pop back
Time:
  insert  -> O(1)
  remove  -> O(1)
  getRandom -> O(1)
Space: O(N)
*/
class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> mp;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;

        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;

        int idx = mp[val];
        int last = v.back();

        v[idx] = last;
        mp[last] = idx;

        v.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};