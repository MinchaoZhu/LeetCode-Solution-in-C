#include <vector>
#include <map>
using namespace std;



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> nodeMap;
        Node* newHead = create(nodeMap,head);
        return newHead;
    }

private:
    Node* create(map<Node*,Node*>& nodeMap, Node*& head){
        if(head==NULL) return NULL;
        if(nodeMap.find(head)!=nodeMap.end()) 
            return nodeMap.find(head)->second;
        Node* newNode = new Node(head->val,NULL,NULL);
        nodeMap.insert(pair<Node*,Node*>(head,newNode));
        newNode->next = create(nodeMap,head->next);
        newNode->random = create(nodeMap,head->random);
        return newNode;
    }
};


int main(void){
    Node* head = new Node;
    Node* node1 = new Node;
    head->val = 0;
    head->next = node1;
    head->random = node1;
    node1->val = 1;
    node1->next = NULL;
    node1->random = node1;
    Solution s;
    head = s.copyRandomList(head); 



}