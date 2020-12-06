// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4


#include <iostream>
#include <vector>
#include <unordered_map> 
#include <list> 
using namespace std; 

/* Evict the Least Recently Used k-v pair. */ 
class LRUCache {
    list<pair<int, int>> dll; // <key, value> 
    unordered_map<int, list<pair<int,int>>::iterator> m; // key -> node* 
    int csize = 0;
public:
    LRUCache(int capacity) {
        csize = capacity;
    }
    
    // O(1) time | O(1) space 
    int get(int key) {
        if (m.find(key) == m.end()) 
            return -1; 
        
        // Bring the most recently accessed pair to the front. 
        dll.push_front( make_pair(key, m[key]->second) ); 
        // Erase the pair. 
        dll.erase(m[key]); 
        // Update the map's iterator of the list to the dll.begin().
        m[key] = dll.begin(); 

        return m[key]->second; // value
    }
    
    // O(1) time | O(capacity) space 
    void put(int key, int value) {
        // if key exists in the map,
        if (m.find(key) != m.end()) {
            // then, we update only the value in dll by erasing here and adding later.
            dll.erase(m[key]); // iterator in m is directly used to erase a node in DLL. Thus, O(1) time. 
        }

        // if list is full, then need to evict. 
        if (dll.size() >= csize)
        {
            // Find the key of LRU cache
            int keyToRemove = dll.back().first;
            // int keyToRemove = (next(dll.end(),-1))->first;
            // Pop LRU node. 
            dll.pop_back(); 
            // Erase the LRU (last) cache from map. 
            m.erase(keyToRemove);
        }
        
        // Always Update dll and unordered_map with the new k-v pair.         
        dll.push_front( make_pair(key, value) );
        m[key] = dll.begin(); // 
        //m.insert( {key, dll.begin()} );
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 
// MAP
//  k.  v.   
//  [4 ] [ptr1] 
//  [3 ] [ptr2] 
 
// DLL<pair> (cache)
//  [4, 4 ] <-> [ ] <->  <-> [ ] <-> [ ] 

 
 
 
 
 int main () {
    
    int capacity = 2; 
    int result; 
    
    LRUCache *obj = new LRUCache(capacity); 
    obj->put(1, 1); 
    obj->put(2, 2); 
    result = obj->get(1); 
    cout << result << endl;     // returns 1
    
    obj->put(3, 3); // evicts key 2 
    result = obj->get(2);    
    cout << result << endl;     // returns -1 (not found) 
    obj->put(4, 4); // evicts key 1 
    result = obj->get(1);       // returns -1 (not found) 
    cout << result << endl; 
    
    result = obj->get(3);   
    cout << result << endl;     // returns 3 
    result = obj->get(4);    
    cout << result << endl;     // returns 4 
    
    return 0;
 }
