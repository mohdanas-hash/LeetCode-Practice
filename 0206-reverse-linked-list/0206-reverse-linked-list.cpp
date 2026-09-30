class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        // ListNode* nex=curr->next;
        while(curr!=NULL){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            head=prev;
        }return head;
    }
};