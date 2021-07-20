class LRUCache {
public:
    list<pair<int,int>>cache;
    unordered_map<int, list<pair<int, int>>::iterator>um;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(um.count(key)==0){
            return -1;
        }
        
        cache.splice(cache.begin(), cache, um[key]);
        return um[key]->second;
    }
    
    void put(int key, int value) {
        if(um.count(key)>0){
            cache.splice(cache.begin(), cache, um[key]);
            um[key]->second = value;
            return;
        }
        
        if(cache.size()==size){
            auto to_delete_key = cache.back().first;
            cache.pop_back();
            um.erase(to_delete_key);
        }
        
        cache.push_front({key, value});
        um[key] = cache.begin();
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
