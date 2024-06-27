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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy= new ListNode(-1);
        dummy->next=head;
        ListNode* leftprev=dummy;
        ListNode*curr=head;
        for(int i=0;i<left-1;i++)
        {
            leftprev=leftprev->next;
            curr=curr->next;
        }

        ListNode* temp=curr;
        ListNode* front;
        ListNode*newprev=NULL;
        for(int i=0;i<=right-left;i++)
        {
            front=curr->next;
            curr->next=newprev;
            newprev=curr;
            curr=front;
        }
        leftprev->next=newprev;
        temp->next=front;
        return dummy->next;



    }
};