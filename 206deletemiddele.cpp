//find middle, store a prev that keeps track of 1 ll behind mid then delete mid
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

      if(head==NULL||head->next==NULL)return NULL;
        ListNode*fast= head;
        ListNode*slow = head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        ListNode*temp=prev->next;
        prev->next=prev->next->next;     
        delete(temp);
        return head;

        
    }
};