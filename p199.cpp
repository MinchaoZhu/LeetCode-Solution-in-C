class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int next = -1;
        dfs(root, result, -1, next);
        return result;
    }
    
private:
    void dfs(TreeNode* root, vector<int>& result, int currentDepth, int& next) {
        if(root){
            if(currentDepth >= next) {
                result.emplace_back(root->val);
                ++next;
            }
            dfs(root->right, result, currentDepth + 1, next);
            dfs(root->left, result, currentDepth + 1, next);
        }
    }
};