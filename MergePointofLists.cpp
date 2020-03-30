int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

//initialize variables
int c1 = 0, c2 = 0, diff;
SinglyLinkedListNode* temp1 = head1; 
SinglyLinkedListNode* temp2 = head2;

//get count of link 1
while(temp1!=NULL) {
    c1++;
    temp1 = temp1->next;
}

//get count of link 2
while(temp2!=NULL) {
    c2++;
    temp2 = temp2->next;
}

diff = abs(c1-c2);

//bring heads to same level
if(c1>c2) {
    for(int i = 0; i<diff; i++) {
        head1 = head1->next;
    }
}

if(c2>c1) {
    for(int i = 0; i<diff; i++) {
        head2 = head2->next;
    }
}

//find intersection
while(head1!=NULL && head2!=NULL) {
    if(head1 == head2) {
        return head1->data;
    }
    head1 = head1->next;
    head2 = head2->next;
}
return -1;
}
