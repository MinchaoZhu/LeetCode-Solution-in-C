#include <stdbool.h>
#include <math.h>
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

typedef struct data{
    bool isBT;
    int depth;
}data;

data subFunc(struct TreeNode* root){
    data left, right, this;
    if(root){
        left = subFunc(root->left);
        right = subFunc(root->right);
        if(left.isBT&&right.isBT&&abs(left.depth-right.depth)<=1){
            this.isBT = 1;
            this.depth = 1+(left.depth>right.depth?left.depth:right.depth);
        }
        else{
            this.isBT = 0;
            this.depth = 1;
        }
    }
    else{
        this.depth = 0;
        this.isBT = 1;
    }
    return this;
}

bool isBalanced(struct TreeNode* root){
    data this = subFunc(root);
    return this.isBT;
}


int main(void){
    struct TreeNode* root;
    root = malloc(sizeof(struct TreeNode));
    root->val =1;
    root->left = 0;
    root->right = 0;
    isBalanced(root);
    return 1;
}