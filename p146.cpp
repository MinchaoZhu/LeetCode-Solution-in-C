#include <unordered_map>
#include <iostream>
#include <list>

using namespace std;

//https://leetcode.com/problems/lru-cache/discuss/669333/C%2B%2B-using-std%3A%3Alist-and-unordered_map

// struct MyListNode{
//     int key;
//     int value;
//     MyListNode* next;
//     MyListNode* prev;
    
//     MyListNode(int _key, int _value){
//         key = _key;
//         value = _value;
//         next = nullptr;
//         prev = nullptr;
//     }
    
//     MyListNode(int _key, int _value, MyListNode* _prev, MyListNode* _next){
//         key = _key;
//         value = _value;
//         next = _next;
//         prev = _prev;
//     }
    
// };

// class LRUCache {
// private:
//     MyListNode* head;
//     MyListNode* tail;
//     int counter;
//     int capacity;
//     std::unordered_map<int, MyListNode*> m;
    
// public:
//     LRUCache(int _capacity) {
//         counter = 0;
//         capacity = _capacity;
//         head = new MyListNode(-1, -1);
//         tail = new MyListNode(-1, -1);
//         head->next = tail;
//         tail->prev = head;
//         MyListNode* current = head;
//         for(int i = 2; i < _capacity; ++i){
//             MyListNode* tmp = new MyListNode(-1,-1, current, current->next);
//             current->next = tmp;
//             current = tmp;
//         }
//         tail->prev = current;
//     }
    
//     int get(int key) {
//         if(capacity == 0){
//             return -1;
//         }
//         if(capacity == 1){
//             return head->key==key?head->value:-1;
//         }
//         if(m.find(key)!=m.end()){
//             MyListNode* tmp = m[key];
//             promote(tmp);
//             return tmp->value;
//         }
//         else return -1;
//     }
    
//     void put(int key, int value){
//         if(capacity == 0){
//             return;
//         }
//         if(capacity == 1){
//             head->key = key;
//             head->value = value;
//             return;
//         }
        
//         if(m.find(key)!=m.end()){
//             promote(m[key]);
//             m[key]->value = value;
//         }
//         else{
//             if(counter++ >= capacity){
//                 m.erase(tail->key);
//             }
//             m[key] = tail;
//             tail->key = key;
//             tail->value = value;
//             promote(tail);
//         }
//     }
    
//     void promote(MyListNode* tmp){
//         if(tmp == tail){
//             tail = tmp->prev;
//             tail->next = nullptr;
//             head->prev = tmp;
//             tmp -> prev = nullptr;
//             tmp -> next = head;
//             head = tmp;
//         }
//         else if(tmp != head){
//             MyListNode* tmpNext = tmp->next;
//             MyListNode* tmpPrev = tmp->prev;
//             tmpNext -> prev = tmpPrev;
//             tmpPrev -> next = tmpNext;
//             head -> prev = tmp;
//             tmp -> next = head;
//             tmp -> prev = nullptr;
//             head = tmp;
//         }
//     }
    
// };





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