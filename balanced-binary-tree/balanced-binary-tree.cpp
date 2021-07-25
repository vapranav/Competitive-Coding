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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) 
            return true;
        int left = find(root->left);
        int right = find(root->right);
        
        if(abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        else
            return false;
    }
    
    int find(TreeNode* root) {
        if(root == NULL)
            return 0;
        else 
            return max(1+find(root->left), 1+find(root->right));
    }
};