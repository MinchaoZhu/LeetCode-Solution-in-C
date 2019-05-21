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


void flattenFunc(struct TreeNode* root, struct TreeNode** pLast){
    if(root){
        (*pLast)->left = root;
        (*pLast) = root;
        flattenFunc(root->left,pLast);
        flattenFunc(root->right,pLast);
        root->right=NULL;        
    }
}

void rotate(struct TreeNode* root){
    while(root){
        root->right=root->left;
        root->left=NULL;
        root = root->right;
    }
}

void flatten(struct TreeNode* root){
    if(root){
        struct TreeNode* last = root;
        flattenFunc(root->left,&last);
        flattenFunc(root->right,&last);
        root->right=NULL;
    }
    rotate(root);
}