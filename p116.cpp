

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        connectFun(root);
        tailSet(root);
        return root;
    }

private:
    void connectFun(Node* root){
        if(root){
            connectLeftRight(root);
            connectFun(root->left);
            connectFun(root->right);
        }
    }

    void connectLeftRight(Node* root){
        if(root->left){
           Node* lNode = root->left, *rNode = root->right;
           while(lNode&&rNode){
               lNode->next = rNode;
               lNode=lNode->right;
               rNode=rNode->left;
           }
        }
    }

    void tailSet(Node* root){
        if(root){
            root->next=NULL;
            tailSet(root->right);
        }
    }
};