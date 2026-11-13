class RandomizedCollection {
    vector<int>v;
    unordered_map<int,unordered_set<int>>mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool notPresent=false;
        if(mp.find(val)==mp.end())
            notPresent=true;
        v.push_back(val);
        mp[val].insert(v.size()-1);
        return notPresent;
    }

    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        int lastElement=v[v.size()-1];
        int indexOfVal=*mp[val].begin();
        if(val==lastElement){
            mp[lastElement].erase(v.size()-1);
            if (mp[lastElement].empty())
            mp.erase(lastElement);
            v.pop_back();
            return true;
        }
        mp[lastElement].erase(v.size()-1);
        mp[lastElement].insert(indexOfVal);
        v[indexOfVal]=lastElement;
        mp[val].erase(indexOfVal);
        if (mp[val].empty())
            mp.erase(val);
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