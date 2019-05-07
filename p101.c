#include <stdbool.h>


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


bool func(struct TreeNode* left, struct TreeNode* right){
    if(left&&right){
        if(left->val!=right->val)return 0;
    }
    else if(!left&&!right)return 1;
    else return 0;

    return func(left->left,right->right)&&
           func(left->right,right->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root){
        return func(root->left,root->right);
    }
    else return 1;
}

