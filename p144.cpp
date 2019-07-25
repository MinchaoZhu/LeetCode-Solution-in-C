class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preTra(result,root);
        return result;
    }

private:
    void preTra(vector<int>& result, TreeNode* root){
        if(root){
            result.emplace_back(root->val);
            preTra(result,root->left);
            preTra(result,root->right);
        }
    }
};