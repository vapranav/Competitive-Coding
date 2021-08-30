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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = depth(root, 0);
        return res;
    }
    int depth(TreeNode* root, int dep) {
        if(root->left == NULL && root->right == NULL)
            return dep+1;
        if(root->right == NULL)
            return depth(root->left, dep+1);
        else if(root->left == NULL)
            return depth(root->right, dep+1);
        return min(depth(root->right, dep+1), depth(root->left, dep+1));
    }
};