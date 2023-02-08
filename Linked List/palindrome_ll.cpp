class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* q,*r;
        q = r = NULL;

        while(fast && fast->next)
        {
            q = slow;
            slow=slow->next;
            fast=fast->next->next;
            q->next = r;
            r = q;
        }

        if(fast)slow=slow->next;

        while(slow && q)
        {
            if(slow->val != q->val)return false;
            slow=slow->next;
            q=q->next;
        }

        return true;
    }
};