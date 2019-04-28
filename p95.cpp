#include <vector>
#include <iostream>
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return vector<TreeNode*>{};
        return generate(1,n);
    }

private:
    vector<TreeNode*> generate(int begin, int end){
        vector<TreeNode*> result;
        if(begin>end){
            TreeNode* root = NULL;
            result.emplace_back(root);
            return result;
        }

        for(int i = begin;i<end+1;++i){
            vector<TreeNode*> lTree = generate(begin,i-1);
            vector<TreeNode*> rTree = generate(i+1,end);
            for(int j=0;j<lTree.size();++j){
                for(int k=0;k<rTree.size();++k){
                    TreeNode * root = new TreeNode(i);
                    root->left = lTree[j];
                    root->right = rTree[k];
                    result.emplace_back(root);
                }
            }
        }
        return result;
    }
};


