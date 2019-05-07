#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}tN;

void inOrder(struct TreeNode** pPrepreNode, struct TreeNode** pPreNode, struct TreeNode* root, struct TreeNode** pSwap1, struct TreeNode** pSwap2, struct TreeNode** pRoot){
    if(!root)return;
    if(*pSwap2)return;
    inOrder(pPrepreNode,pPreNode,root->left,pSwap1,pSwap2,pRoot);
    if(*pSwap2)return;
    if(*pPrepreNode&&*pPreNode){//double none-NULL pointer
        if(((*pPreNode)->val<(*pPrepreNode)->val)&&((*pPreNode)->val>root->val)){
            *pSwap1 = root;
            *pSwap2 = *pPrepreNode; 
            return;     
        }
        if(((*pPreNode)->val>root->val&&(*pPrepreNode)->val<root->val)||((*pPreNode)->val<(*pPrepreNode)->val&&(*pPrepreNode)->val<root->val)){
            if(*pSwap1){
                *pSwap2 = *pPreNode;
                return;
            }
            else *pSwap1 = *pPreNode;
        }
    }
    if(*pPreNode&&!(*pPrepreNode)){
        if(root->val<(*pPreNode)->val)
            *pSwap1 = *pPreNode;
    }
    *pPrepreNode = *pPreNode;
    *pPreNode = root;
    *pRoot = root;
    inOrder(pPrepreNode,pPreNode,root->right,pSwap1,pSwap2,pRoot);
}

void recoverTree(struct TreeNode* root){
    struct TreeNode* prePreNode=NULL, *preNode=NULL;
    struct TreeNode* swap1 = NULL,* swap2 = NULL;
    struct TreeNode* rroot = root;
    inOrder(&prePreNode,&preNode,root,&swap1,&swap2,&rroot);
    if(!swap1)swap1 = root==rroot?root->left:root;
    if(!swap2)swap2 = rroot;
    int temp = swap1->val;
    swap1->val = swap2->val;
    swap2->val = temp;
}



int main(void){
    tN* root;
    tN* l,* rr;
    tN* ll;
    root = (tN*)malloc(sizeof(tN));
    l = (tN*)malloc(sizeof(tN));
    rr = (tN*)malloc(sizeof(tN));
    ll = (tN*)malloc(sizeof(tN));
    root->left = l;
    l->right = rr;
    l->left = ll;
    root->val = 5;
    l->val  = 0;
    rr->val = -5;
    ll->val = 2;
    recoverTree(root);

    return 0;
}