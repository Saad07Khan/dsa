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

     ListNode* reverseList(ListNode* head) {
        ListNode *temp=head;
        ListNode *prev=NULL;
        ListNode *front;

        while(temp!=NULL)
        {
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        //at the end both temp and front will reach null and prev will be at head 
        return prev;
        
        
    }
    bool isPalindrome(ListNode* head) {

        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid= reverseList(slow->next);
        ListNode*first=head;
        ListNode*last=mid;
        while(last!=NULL)
        {
            if(first->val!=last->val)
            {
                return false;
            }
            first=first->next;
            last=last->next;

        }
        
        return true;
    }
};