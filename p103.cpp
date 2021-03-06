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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        recursion(result, root,1);
        reverse(result);
        return result;
    }

private:
    void recursion(vector<vector<int>>& result, TreeNode* root, int level){
        if(root){
            if(level>result.size()){
                vector<int> temp;
                temp.emplace_back(root->val);
                result.emplace_back(temp);
            }
            else{
                result[level-1].emplace_back(root->val);
            }
            recursion(result,root->left,level+1);
            recursion(result,root->right,level+1);
        }
        return;
    }

    void reverse(vector<vector<int>>& result ){
        for(int i = 1;i<result.size();i+=2){
            for(int j = 0;j<result[i].size()/2;++j){
                int temp = result[i][j];
                result[i][j] = result[i][result[i].size()-1-j];
                result[i][result[i].size()-1-j] = temp;
            }
        }
    }

};