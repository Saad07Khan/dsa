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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*temp = head->next;
        vector<int>ans(2,-1);
        if(temp->next==NULL)
        {
            return ans;
        }
        int cnt=1;
        ListNode*prev=head;
        ListNode*front;
        vector<int>critical;
        while(temp->next!=NULL)
        {
            cnt++;
            front=temp->next;
            if(temp->val<prev->val&&temp->val<front->val)
            {
                critical.push_back(cnt);
            }
            if(temp->val>prev->val&&temp->val>front->val)
            {
                critical.push_back(cnt);
            }
            prev=temp;
            temp=temp->next;
        }
        if(critical.size()<2)
        {
            return ans;
        }

        int n=critical.size();
        int lowest= critical[0];
        int largest=critical[n-1];
        int secondlargest=critical[n-2];

        int minDistance= INT_MAX;
        int maxDistance = largest-lowest;
        for(int i=1;i<n;i++)
        {
            minDistance = min(minDistance,critical[i]-critical[i-1]);
        }
        ans[0]=minDistance;
        ans[1]=maxDistance;
        return ans;
    }
};