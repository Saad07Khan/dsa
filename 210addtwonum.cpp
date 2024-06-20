class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead= new ListNode(-1);
        ListNode* curr=dummyHead;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL)
        {
            int sum=carry;
            if(temp1)sum+=temp1->val; //when 1 list bigger than other
            if(temp2)sum+=temp2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            curr->next=newNode;
            curr=curr->next;
            if(temp1)temp1=temp1->next; //when 1 list bigger than other
            if(temp2)temp2=temp2->next;
        }
        if(carry)
        {
            ListNode* n= new ListNode(carry);
            curr->next=n;

        }

        return dummyHead->next;
    }
};