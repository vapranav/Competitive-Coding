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
    int goodNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return findGoodNodes(root, root->val);
    }
    
    int findGoodNodes(TreeNode* root, int Max) {
        
        if(root == NULL)
            return 0;
        int maxi = max(root->val, Max);
        if(root->val>=Max) 
            return 1 + findGoodNodes(root->left, maxi) + findGoodNodes(root->right, maxi);
        else 
            return 0 + findGoodNodes(root->left, maxi) + findGoodNodes(root->right, maxi);
        
    }
};