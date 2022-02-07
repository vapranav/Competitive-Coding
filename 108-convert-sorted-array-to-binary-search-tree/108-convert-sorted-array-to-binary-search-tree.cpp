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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return NULL;
        if(size == 1) {
            TreeNode* node = new TreeNode(nums[0]);
            return node;
        }
        
        int middle = size/2;
        TreeNode* node = new TreeNode(nums[middle]);
        vector<int> left {nums.begin(), nums.begin()+middle};
        vector<int> right {nums.begin()+middle+1, nums.end()};
        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);
        return node;
    }
};