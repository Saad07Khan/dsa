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

    int gcd(int a, int b) 
{ 
    // Find Minimum of a and b 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
    // Return gcd of a and b 
    return result; 
} 
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* prev=head;
        ListNode* temp=head->next;
        while(temp!=NULL)
        {
            int n=gcd(prev->val,temp->val);
            ListNode* newN= new ListNode(n);
            prev->next=newN;
            newN->next=temp;
            prev=temp;
            temp=temp->next;
        }

        return head;
        
    }
};