class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        node=node->next;

        while(node)
        {
            prev->val = node->val;
            if(node->next)prev=node;
            node=node->next;
        }

        prev->next = NULL;
    }
};