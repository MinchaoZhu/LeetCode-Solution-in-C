

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

void DFS(struct TreeNode* root, int* pSum, int num){
    if(root->left||root->right){
        num = 10*num + root->val;
        if(root->left)
            DFS(root->left,pSum,num);
        if(root->right)
        DFS(root->right,pSum,num);
    }
    else{
        num = 10*num + root->val;
        *pSum += num;
        return;
    }
}

int sumNumbers(struct TreeNode* root){
    int sum = 0, num = 0;
    DFS(root,&sum,num);
    return sum;
}

