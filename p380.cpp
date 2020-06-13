class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        std::srand(std::time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) == m.end()){
            m[val] = data.size();
            data.emplace_back(val);
            return true;
        }
        else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int i = m[val];
            if(i != data.size()-1){
                data[i] = data[data.size()-1];
                m[data[data.size()-1]] = i; 
            }
            data.pop_back();
            m.erase(val);
            return true;
        }
        else return false;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(data.size()!=0)
            return data[rand()%data.size()];
        else return 0;
    }
    
private:
    vector<int> data;
    unordered_map<int,int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */