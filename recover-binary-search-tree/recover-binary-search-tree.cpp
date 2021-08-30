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
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        
        while(root!=NULL) {
            if(root->left == NULL) {
                if(prev!=NULL && prev->val > root->val) {
                    if(first == NULL) {
                        first = prev;
                    }
                    second = root;
                }
                prev = root;
                root = root->right;
            } else {
                TreeNode* temp = root->left;
                while(temp->right != NULL && temp->right != root) {
                    temp = temp->right;
                }
                
                if(temp->right == NULL) {
                    temp->right = root;
                    root = root->left;
                } else {
                    temp->right = NULL;
                    if(prev!=NULL && prev->val > root->val) {
                        if(first == NULL) {
                            first = prev;
                        }
                        second = root;
                    }
                    prev = root;
                    root = root->right;
                }  
            }
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};