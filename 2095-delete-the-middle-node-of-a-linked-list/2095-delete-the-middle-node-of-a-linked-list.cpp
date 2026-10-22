class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if  (head->next == nullptr ) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while ( fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};