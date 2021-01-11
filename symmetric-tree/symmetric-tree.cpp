/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return checkSymmetry(root->left, root->right);
    }
    
    bool checkSymmetry(TreeNode * leftSub, TreeNode* rightSub) {
        if(leftSub == NULL && rightSub == NULL)
            return true;
        if(leftSub == NULL || rightSub == NULL)
            return false;
        if(leftSub->val == rightSub->val) 
            return checkSymmetry(leftSub->left, rightSub->right) && checkSymmetry(leftSub->right, rightSub->left);
        else 
            return false;
    }
};
