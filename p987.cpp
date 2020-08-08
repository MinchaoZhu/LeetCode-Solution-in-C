class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int leftBorder = 0, rightBorder = 0;
        border(root, leftBorder, rightBorder, 0); // determine how "wide" is the tree
        vector<vector<int>> result(rightBorder-leftBorder+1);
        solve(result, root, -leftBorder);
        return result;
    }
        
private:
    inline void solve(vector<vector<int>>& result, TreeNode* root, int index) {
        if(root) {
            queue<pair<TreeNode*, int>> q;
            int currentLevelNum = 1;
            int nextLevelNum = 0;
            q.push({root, index});            
            while(!q.empty()) {
                vector<pair<TreeNode*, int>> tmp; // tmp array to store nodes in current level
                for(int i = 0; i < currentLevelNum; ++i) { // level traversal
                    auto p = q.front();
                    q.pop();
                    tmp.emplace_back(p);
                    if(p.first->left) {
                        ++nextLevelNum;
                        q.push({p.first->left, p.second-1});
                    }
                    if(p.first->right) {
                        ++nextLevelNum;
                        q.push({p.first->right, p.second + 1});
                    }                    
                }

                auto cmp = [](const pair<TreeNode*, int>& left, const pair<TreeNode*, int>& right) {
                    return left.first->val < right.first->val;    
                }; // In same level , make sure the node with smaller value will be in left
                sort(tmp.begin(), tmp.end(), cmp);
                for(auto pp : tmp) {
                    result[pp.second].emplace_back(pp.first->val);    // push value in current level
                }
                currentLevelNum = nextLevelNum;
                nextLevelNum = 0;
            }
        }
    }
    
    inline void border(TreeNode* root, int& leftBorder, int& rightBorder, int current) {
        if(root) {
            leftBorder = min(leftBorder, current);
            rightBorder = max(rightBorder, current);
            border(root->left, leftBorder, rightBorder, current - 1);
            border(root->right, leftBorder, rightBorder, current + 1);            
        }
    }
};