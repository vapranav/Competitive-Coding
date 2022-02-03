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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3Head = NULL;
        ListNode* l3Tail = NULL;
        int carry = 0;
        int sum;
        while(l1 || l2 || carry) {
            if(l1 && l2) {
                sum = l1->val + l2->val + carry;
            } else if(l1) {
                sum = l1->val + carry;
            } else if(l2) {
                sum = l2->val + carry;
            } else {
                sum = carry;
            }
            carry = sum/10;
            int digit = sum%10;
            if(l3Head == NULL) {
                ListNode* newSum = new ListNode(digit);
                l3Head = newSum;
                l3Tail = newSum;
            } else {
                ListNode* newSum = new ListNode(digit);
                l3Tail->next = newSum;
                l3Tail = l3Tail->next;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        l3Tail->next = NULL;
        return l3Head;
    }
};