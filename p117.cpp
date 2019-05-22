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
        Node* lNode, *rNode;
        int lDepth = maxDepth(root->left), rDepth = maxDepth(root->right);
        for(int i=1;i<=lDepth;++i){
            lNode = boderOfLevel(root->left,i,0);
            rNode = boderOfLevel(root->right,i,1);
            if(lNode&&rNode)lNode->next = rNode;
        }
    }

    Node* boderOfLevel(Node* root, int level, bool left){
        if(level==1||!root) return root;
        Node* temp=NULL;
        if(left){
            temp = boderOfLevel(root->left,level-1,1);
            if(!temp) temp = boderOfLevel(root->right,level-1,1);
        }
        else{
            temp = boderOfLevel(root->right,level-1,0);
            if(!temp) temp = boderOfLevel(root->left,level-1,0);
        }
        return temp;
    }

    int maxDepth(Node* root){
        if(!root)return 0;
        else{
            int l,r;
            l = maxDepth(root->left);
            r = maxDepth(root->right);
            return 1+(l>r?l:r);
        }
    }
};