#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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
}TreeNode;
bool valid(struct TreeNode* root, long min, long max){
    if(!root)return 1;
    if(!(root->val>min&&root->val<max))return 0;
    else return valid(root->left,min,root->val)&&valid(root->right,root->val,max);
}

bool isValidBST(struct TreeNode* root){
    if(root)
        return valid(root->left,-2147483649,root->val)&&valid(root->right,root->val,2147483648);
    return 1;
}

int main(void){
    struct TreeNode * root, *l,*r;
    root = malloc(sizeof(TreeNode));
    l = malloc(sizeof(TreeNode));
    r = malloc(sizeof(TreeNode));
    root->left = l;
    root->right = r;
    root->val = 2;
    l->val = 1;
    r->val = 3;

    int t;
    t = isValidBST(root);
    printf("%d\n",t);

    return 0;
}
