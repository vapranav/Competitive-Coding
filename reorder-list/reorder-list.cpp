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
    void reorderList(ListNode* head) {
        int n = 0, m;
        ListNode* tmp = head;
        while(tmp != NULL) {
            n++;
            tmp = tmp->next;
        }
        if(n == 1) 
            return;
        m = n/2;
        ListNode* revStart = head;
        while(m-1) {
            revStart = revStart->next;
            m--;
        }
        //cout<<revStart->val;
        ListNode* reversedHead = reverseList(revStart->next);
        revStart->next = reversedHead;
        ListNode* p1 = head;
        ListNode* p2 = reversedHead;

        while(p1!=revStart){
            revStart->next=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p1=p2->next;
            p2=revStart->next;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;
        while(next!=NULL) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }
};