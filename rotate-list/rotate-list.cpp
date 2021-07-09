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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode* entry = head;
        int len;
        while(entry!=NULL) {
            entry = entry->next;
            len++;
        }
        
        if(k>=len)
            k = k%len;
        
        ListNode* first = head;
        ListNode* second = head;
        while(k>0) {
            first = first->next;
            k--;
        }
        while(first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        
        first->next = head;
        head = second->next;
        second->next = NULL;
        
        return head;
    }
};