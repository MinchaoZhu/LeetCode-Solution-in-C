/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> result;
        posTra(result,root);
        return result;
    }

private:
    void posTra(vector<int>& result, TreeNode* root){
        if(root){
            posTra(result,root->left);
            posTra(result,root->right);
            result.emplace_back(root->val);
        }
    }
};