class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int result = root->val;
        findClosest(root->left, target, result);
        findClosest(root->right, target, result);
        return result;
    }
    
    
private:
    void findClosest(TreeNode* root, const double& target, int& result) {
        if(root) {
            int value = root->val;
            if(abs(target-(double)value) < abs(target-(double)result))
                result = value;
            if(value < target) {
                findClosest(root->right, target, result);
            }
            else if(value > target) {
                findClosest(root->left, target, result);
            }
        }
        
    }
    
    
};