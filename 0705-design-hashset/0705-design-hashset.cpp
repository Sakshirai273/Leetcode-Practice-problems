class MyHashSet {
public:
    int numBuckets;
    vector<list<int>> buckets;
    int getHashValue(int key) {
        return key%numBuckets;
    }
    
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets, list<int>{});
    }
    
    void add(int key) {
        int index = getHashValue(key);
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        if(itr == buckets[index].end())
            buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getHashValue(key);
        
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        if(itr != buckets[index].end())
            buckets[index].erase(itr);
    }
    
    bool contains(int key) {
        int index = getHashValue(key);
        
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        return itr != buckets[index].end();
    }
};


//NOTE:
/*
You can use the information of load factor to resize the hashset if the Load Factor crosses 0.75
int n = No. of elements inserted till now
int b = Total Number of Buckets

Load Factor = (n/b);
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */