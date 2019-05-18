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

struct TreeNode* gen(int* in,int iStart, int* post, int pStart, int size){
    struct TreeNode* root = NULL;
    if(!size)return root;
    int lSize=0, rSize;
    for(;lSize<size;++lSize){
        if(*(in+lSize+iStart)==*(post+pStart+size-1))break;
    }
    rSize = size-1-lSize;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = *(post+pStart+size-1);
    root->left = gen(in,iStart,post,pStart,lSize);
    root->right = gen(in,iStart+1+lSize,post,pStart+lSize,rSize);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return gen(inorder,0,postorder,0,inorderSize);
}


int main(void){
    int p[5] = {3,9,20,15,7};
    int i[5] = {9,3,15,20,7};
    buildTree(p,5,i,5);


}