class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)return head;
        
        int len = 0;
        ListNode* slow = head;

        while(slow)
        {
            len++;
            slow=slow->next;
        }

        len = k%len;

        ListNode* fast = head;
        slow = head;

        while(fast->next)
        {
            if(len>0)len--;
            else slow=slow->next;
            fast=fast->next;
        }

        fast->next = head;
        head=slow->next;
        slow->next = NULL;

        return head;
    }
};