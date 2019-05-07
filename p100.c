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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p&&!q)return 1;
    else if(p&&q){
        if(p->val!=q->val)return 0;
    }
    else return 0;
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}

