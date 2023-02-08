class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow,*fast;
        slow=fast=head;

        while(fast->next)
        {
            if(n > 0)n--;
            else slow=slow->next;
            fast=fast->next;
        }

        if(n==1)head=head->next;
        else slow->next = slow->next->next;
        return head;
    }
};