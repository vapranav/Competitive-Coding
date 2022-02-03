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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* temp1 = headA; ListNode* temp2 = headB;
        while(temp1) {
            len1++;
            temp1 = temp1->next;
        }
        while(temp2) {
            len2++;
            temp2 = temp2->next;
        }
        ListNode* bigger = len1 > len2 ? headA : headB;
        ListNode* smaller = len1 > len2 ? headB : headA;
        int diff = len1 > len2 ? len1-len2 : len2-len1;
        while(diff) {
            bigger = bigger->next;
            diff--;
        }
        while(bigger && smaller) {
            if(bigger == smaller)
                return bigger;
            else {
                bigger = bigger->next;
                smaller = smaller->next;
            }
        }
        return NULL;
    }
};