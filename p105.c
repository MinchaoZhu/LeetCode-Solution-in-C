#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* gen(int* pre, int pStart, int* in, int iStart,int size){
    struct TreeNode* root = NULL;
    if(!size)return root;
    int lSize=0, rSize;
    for(;lSize<size;++lSize){
        if(*(in+iStart+lSize)==*(pre+pStart))break;
    }
    rSize = size-1-lSize;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = *(pre+pStart);
    root->left = gen(pre,pStart+1,in,iStart,lSize);
    root->right = gen(pre,pStart+lSize+1,in,iStart+1+lSize,rSize);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return gen(preorder,0,inorder,0,inorderSize);
}

int main(void){
    int p[5] = {3,9,20,15,7};
    int i[5] = {9,3,15,20,7};
    buildTree(p,5,i,5);


}