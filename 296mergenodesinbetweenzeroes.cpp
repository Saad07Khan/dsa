class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // ListNode* dummyNode= new ListNode(-1);
        // dummyNode->next=head;
        // ListNode* cur=head;
        // ListNode*temp=head->next;
        // int sum=0;
        // while(temp!=NULL)
        // {
        //     if(temp->val==0)
        //     {
        //         ListNode* sm= new ListNode(sum);
                
        //     }
        //     else
        //     {
        //          sum+=temp->val;
        //     }
           

        // }
        vector<int>sm;
        long long sum=0;
        ListNode*temp = head->next;
        while(temp!=NULL)
        {
            if(temp->val!=0)
            {
                sum+=temp->val;
            }
            else
            {
                sm.push_back(sum);
                sum=0;
            }
            temp = temp->next;
        }

        ListNode* newHead= new ListNode(sm[0]);
        ListNode* temp1=newHead;
        for(int i=1;i<sm.size();i++)
        {
            temp1->next= new ListNode(sm[i]);
            temp1=temp1->next;
        }

        return newHead;
    }
};