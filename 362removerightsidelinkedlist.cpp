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

    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* curr;
        while(temp != NULL)
        {
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
  
        ListNode* newHead = reverseList(head);

        
        ListNode* prev = newHead;  
        ListNode* temp = newHead->next; 
        
        while(temp != NULL)
        {
            
            if(temp->val < prev->val)
            {
              
                prev->next = temp->next;
            }
            else
            {
                
                prev = temp;
            }
           
            temp = temp->next;
        }

        return reverseList(newHead);
    }
};
