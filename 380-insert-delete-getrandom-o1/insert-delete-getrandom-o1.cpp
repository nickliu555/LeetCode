class RandomizedSet {
public:
    unordered_map<int, int> valToIndex;;
    vector<int> valArr;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valToIndex.count(val) > 0) return false;
        valToIndex[val] = valArr.size();
        valArr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (valToIndex.count(val) == 0) return false;
        int index = valToIndex[val], lastVal = valArr.back();
        valToIndex[lastVal] = index;
        valArr[index] = lastVal;
        valArr.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % (valArr.size());
        return valArr[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */