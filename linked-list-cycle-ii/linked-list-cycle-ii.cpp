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
        unordered_set<ListNode*> s;
        s.insert(head);
        ListNode* ans = NULL;
        while(head != NULL) {
            if(s.find(head->next) != s.end()) {
                
                ans = head->next;
                break;
            }
            else {
                s.insert(head->next);
            }
                //return head->next;
            head = head->next;
        }
        if(head == NULL)
            return NULL;
        else return ans;
    }
};