/*
Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
Method: hashset to keep track of indices and vector to store
Time Complexity: 
Space Complexity:
*/

class RandomizedCollection {
public:

    // map to keep track of all the indices of a particular value
    unordered_map<int, unordered_set<int>>mp;
    // vector to store all the elements
    vector<int>v;

    RandomizedCollection() {}
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size()-1);

        // return true if not already present
        return mp[val].size()<=1;        
    }
    
    bool remove(int val) {
        if(mp[val].size()==0) return false;

        // remove from map
        int ind = *mp[val].begin();
        mp[val].erase(ind);

        // remove from vector
        // send the element to the last, update the index in map and pop the element
        int num = v.back();
        swap(v[ind], v[v.size()-1]);
        mp[num].insert(ind);
        mp[num].erase(v.size()-1);
        v.pop_back();
        return true;

    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */