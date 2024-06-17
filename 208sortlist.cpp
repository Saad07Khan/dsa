//find the middle of linked list, divide it and then merge it together recursively(merge sort on LL)
class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val>l2->val)std::swap(l1,l2);
        ListNode* res= l1;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode* temp=NULL;
            while(l1!=NULL && l1->val<=l2->val)
            {
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            std::swap(l1,l2);
        }
        return res;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode*l1=sortList(head);
        ListNode*l2=sortList(slow);
        
        return merge(l1,l2);
    }

};