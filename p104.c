#include <stdio.h>


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



int maxDepth(struct TreeNode* root){
    if(!root)return 0;
    else{
        int l,r;
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        return 1+(l>r?l:r);
    }
}

