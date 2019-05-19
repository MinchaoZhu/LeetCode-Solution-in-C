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

struct TreeNode* subConvert(int* nums, int start, int size){
    struct TreeNode* root=NULL;
    if(size){
        int mid = start + (size-1)/2;
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = *(nums+mid);
        root->left = subConvert(nums,start,mid-start);
        root->right = subConvert(nums,mid+1,size-1-mid+start);
    }
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return subConvert(nums,0,numsSize);
}

