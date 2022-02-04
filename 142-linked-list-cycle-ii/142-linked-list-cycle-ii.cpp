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
    ListNode *detectCycle(ListNode *head) {
        if(!head || head->next == NULL)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* collisionPoint = NULL;
        while(fast && slow) {
            if(fast->next == NULL || slow->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                collisionPoint = fast;
                break;
            }
        }
        //cout<<collisionPoint->val;
        if(collisionPoint == NULL) 
            return NULL;
        else {
            while(1) {
                if(head == collisionPoint) 
                    return collisionPoint;
                head = head->next;
                collisionPoint = collisionPoint->next;
            }
        }
        return NULL;
    }
};