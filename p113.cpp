#include <vector>
#include <stack>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        findPath(result, root, temp,sum);
        return result;
    }
private:
    void findPath(vector<vector<int>>& result, TreeNode* root, vector<int>& temp, int sum){
        if(root){
            temp.emplace_back(root->val);
            if(root->left||root->right){
                if(root->left) findPath(result,root->left,temp,sum-root->val);
                if(root->right) findPath(result,root->right,temp,sum-root->val);
            }
            else{   
                if(sum==root->val)result.emplace_back(temp);
            }
            temp.pop_back();
        }
    }
};