class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++)fast=fast->next; //if fast reaches null means we need to del head
        if(fast==NULL)return head->next;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*temp=slow->next;
        slow->next=slow->next->next;
        delete(temp);
        return head;
 
    }
};