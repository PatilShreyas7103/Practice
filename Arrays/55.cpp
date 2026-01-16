// Design HashMap 

#include <vector>
using namespace std;

class MyHashMap {
private:
    vector<int> mp;

public:
    MyHashMap() {
        // keys range from 0 to 1e6
        mp.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};