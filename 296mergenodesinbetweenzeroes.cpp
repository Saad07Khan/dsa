class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        // approach 1 tc o(n) sc O(1)
        ListNode *temp = head->next;
        long long sum = 0;
        while (temp->val != 0)
        {
            sum += temp->val;

            temp = temp->next;
        }

        ListNode *newHead = new ListNode(sum);
        ListNode *temp1 = newHead;
        long long newSum = 0;
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->val == 0)
            {
                temp1->next = new ListNode(newSum);
                temp1 = temp1->next;
                newSum = 0;
            }
            else
            {
                newSum += temp->val;
            }
            temp = temp->next;
        }

        return newHead;

        // approach 2 tc o(n) sc o(n)
        vector<int> sm;
        long long sum = 0;
        ListNode *temp = head->next;
        while (temp != NULL)
        {
            if (temp->val != 0)
            {
                sum += temp->val;
            }
            else
            {
                sm.push_back(sum);
                sum = 0;
            }
            temp = temp->next;
        }

        ListNode *newHead = new ListNode(sm[0]);
        ListNode *temp1 = newHead;
        for (int i = 1; i < sm.size(); i++)
        {
            temp1->next = new ListNode(sm[i]);
            temp1 = temp1->next;
        }

        return newHead;
    }
};

// optimal
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {

        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        ListNode *temp = head;
        long long sum = 0;
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->val == 0)
            {
                curr->next = new ListNode(sum);
                curr = curr->next;
                sum = 0;
            }
            else
            {
                sum += temp->val;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};