#include <vector>
#include <queue>
#include <map>

using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* newNode = new Node, *result, *originNode = node;
        result = newNode;
        newNode->val = node->val;
        queue<Node*> queueNode;
        map<Node*,Node*> mapNode;
        mapNode.insert(pair<Node*,Node*>(node,newNode));
        queueNode.push(node);
        while(!queueNode.empty()){
            node = queueNode.front();
            Node * nodeInNewGraph = mapNode.find(node)->second;
            for(auto nodeTemp : node->neighbors){
                if(mapNode.find(nodeTemp)==mapNode.end()){
                    queueNode.push(nodeTemp);
                    newNode = new Node;
                    newNode->val = nodeTemp->val;
                    mapNode.insert(pair<Node*,Node*>(nodeTemp,newNode));
                }
                nodeInNewGraph->neighbors.emplace_back(mapNode.find(nodeTemp)->second);
            }
            queueNode.pop();
        }
        return result;
    }
};



int main(void){
    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node1->neighbors = {node2,node3};
    node2->neighbors = {node1,node3};
    node3->neighbors = {node1,node2};

    Node* newNode;

    Solution sss;
    newNode = sss.cloneGraph(node1);



}