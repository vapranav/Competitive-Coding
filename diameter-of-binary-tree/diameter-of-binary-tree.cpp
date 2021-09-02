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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int partialAnswer = maxDepth(root->left, 0) + maxDepth(root->right, 0);
        return max(max(right, left), partialAnswer);
    }
    
    int maxDepth(TreeNode* root, int depth) {
        if(root == NULL)
            return depth;
        else 
            return max(maxDepth(root->right, depth+1), maxDepth(root->left,depth+1)); 
    }
};