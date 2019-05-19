#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = maxDepth(root);
        vector<vector<int>> result(d);
        func(root,result,1);
        return result;
    }

private:
    int maxDepth(struct TreeNode* root){
        if(!root)return 0;
        else{
            int l,r;
            l = maxDepth(root->left);
            r = maxDepth(root->right);
            return 1+(l>r?l:r);
        }
    }
    void func(TreeNode* root, vector<vector<int>>& result, int level){
        if(root){
            result[result.size()-level].emplace_back(root->val);
            func(root->left,result,level+1);
            func(root->right,result,level+1);
        }
    }
};