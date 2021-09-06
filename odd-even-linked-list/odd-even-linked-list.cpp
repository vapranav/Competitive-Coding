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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* secondHead = head->next;
        while(second->next != NULL) {
            first->next = second->next;
            first = first->next;
            if(first->next != NULL) {
                second->next = first->next;
                second = second->next;
            } else {
                second->next = NULL;
                break;
            }
        }
        
        first->next = secondHead;
        return head;
    }
};