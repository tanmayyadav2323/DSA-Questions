class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)return head;

        ListNode* evenHead,*even,*oddHead,*odd;

        evenHead=even=head;
        oddHead=odd=head->next;

        while(odd && odd->next)
        {
            even->next = odd->next;
            even = even->next;
            odd->next=even->next;
            odd=odd->next;
        }

        even->next = oddHead;
        return evenHead;
    }
};