/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
            long result = INT_MIN;
            solve(root, result);
            return result;
    }
    
private:
    inline int solve(TreeNode* root, long& result) {
        if(root) {
            long left = solve(root->left, result);
            long right = solve(root->right, result);
            long maxValWithRoot = max((long)root->val, max(left, right) + root->val);
            long ret = maxValWithRoot;
            maxValWithRoot = max(maxValWithRoot, (long)root->val + left + right);
            long maxValWithoutRoot = max(left, right);
            result = max(result, max(maxValWithRoot, maxValWithoutRoot));
            return ret;
        }
        else
            return INT_MIN;
    }
    

    
};