/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || head->next == NULL)
            return head;
        ListNode* smallerHead = NULL;
        ListNode* smallerTail = NULL;
        ListNode* greaterHead = NULL;
        ListNode* greaterTail = NULL;
        while(head!=NULL) {
            if(head->val < x) {
                if(smallerHead == NULL) {
                    smallerHead = head;
                    smallerTail = head;
                } else {
                    smallerTail->next = head;
                    smallerTail = smallerTail->next;
                }
            } else {
                if(greaterHead == NULL) {
                    greaterHead = head;
                    greaterTail = head;
                } else {
                    greaterTail->next = head;
                    greaterTail = greaterTail->next;
                }
            }
            head = head->next;
        }
        if(smallerHead == NULL)
            return greaterHead;
        smallerTail->next = greaterHead;
        if(greaterTail!=NULL)
            greaterTail->next = NULL;
        return smallerHead;
    }
};