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

int minDepth(struct TreeNode* root){
    if(root){
        int l,r;
        l = minDepth(root->left);
        r = minDepth(root->right);
        if(l&&!r)return 1+l;
        else if(!l&&r)return 1+r;
        else return 1+(l<r?l:r);
    }
    else return 0;
}

