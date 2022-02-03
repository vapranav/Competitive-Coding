/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        while(next->next!= NULL) {
            int temp = node->val;
            node->val = next->val;
            next->val = temp;
            node = next;
            next = next->next;
        } 
        int temp = node->val;
        node->val = next->val;
        next->val = temp;
        node->next = NULL;
    }
};