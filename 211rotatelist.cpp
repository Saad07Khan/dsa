/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* findNth(ListNode* temp, int n)
    {
        int k=0;
        while(temp!=NULL)
        {
             k++;
            if(k==n) return temp;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL||k==0)return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL)// as we have to reach till tail not beyond it
        {
            len+=1;
            tail=tail->next;
        }      
        if(k%len==0)return head;
        k=k%len;
         tail->next=head;   
        ListNode* newN= findNth(head,len-k);
        head= newN->next;
        newN->next=NULL;
        return head;
        
    }
};