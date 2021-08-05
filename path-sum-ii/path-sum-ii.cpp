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
    
    void findPaths(TreeNode* root, vector<vector<int>>& res, vector<int>& tmp, int targetSum, int curSum) {
        
        if(root == NULL)
            return;
       
        tmp.push_back(root->val);
        curSum+=root->val;
        
        if(root->right == NULL and root->left == NULL and curSum == targetSum) {
            res.push_back(tmp);
            return;
        }
        
        //if(curSum>targetSum)
            //return;

        cout<<curSum<<endl;
        if(root->right!=NULL) {
            findPaths(root->right, res, tmp, targetSum, curSum);
            tmp.pop_back();
        }
        if(root->left!=NULL) {
            findPaths(root->left, res, tmp, targetSum, curSum);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        findPaths(root, res, tmp, targetSum, 0);
        return res;
    }
};