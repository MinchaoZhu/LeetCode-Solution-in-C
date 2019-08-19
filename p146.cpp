#include <unordered_map>
#include <iostream>
#include <list>

using namespace std;






class LRUCache {
public:
    struct myUnion{
        int key;
        int value;
    };
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        auto findItr = cMap.find(key);
        if(findItr==cMap.end()) return -1;
        else{
            myUnion unionTemp;
            unionTemp.key = key;
            unionTemp.value = findItr->second->value;
            cList.erase(findItr->second);
            cList.emplace_front(unionTemp);
            cMap.erase(key);
            cMap.insert(make_pair(key,cList.begin()));
            return unionTemp.value;
        }
    }
    
    void put(int key, int value) {
        auto findItr = cMap.find(key);
        if(findItr == cMap.end()){
            if(size>=cap){
                int lastNodeKey = cList.back().key;
                cList.pop_back();
                cMap.erase(lastNodeKey);
                --size;
            }
        }
        else{
            cList.erase(findItr->second);
            --size;
        }
        myUnion unionTemp;
        unionTemp.key = key;
        unionTemp.value = value;
        cList.emplace_front(unionTemp);
        cMap.erase(key);
        cMap.insert(make_pair(key,cList.begin()));
        ++size;
    }

private:
    int cap;
    int size;
    list<myUnion> cList;
    unordered_map<int, list<myUnion>::iterator> cMap;
};

int main(void){
    LRUCache cache(2);
    int value = -1;
    cache.put(1, 1);
    cache.put(2, 2);
    //cache.put(2,3);
    //cache.put(4,1);
    value = cache.get(1);
    cout<<value;
    /**
    value = cache.get(2);
    cout<<value;
    **/
    cache.put(3,3);
    value = cache.get(2);
    cout<<value;
    cache.put(4,4);
    value = cache.get(1);
    cout<<value;
    value = cache.get(3);
    cout<<value;
    value = cache.get(4);
    cout<<value;

    return 0;
}