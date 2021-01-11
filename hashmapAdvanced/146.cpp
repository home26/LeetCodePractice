class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it==map.end()){
            return -1;
        }
        linkedList.splice(linkedList.begin(), linkedList, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it != map.end()){
            linkedList.erase(it->second);    
        }
        linkedList.push_front(make_pair(key,value));
        map[key] = linkedList.begin();
        if(map.size() > cap){
            int temp = linkedList.rbegin()->first;
            linkedList.pop_back();
            map.erase(temp);
        }
    }
    
private:
    int cap;
    list<pair<int,int>> linkedList;
    unordered_map<int, list<pair<int,int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
