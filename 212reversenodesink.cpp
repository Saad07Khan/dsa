class Solution
{
public:
    ListNode *findKth(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *front;

        while (temp != NULL)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        // at the end both temp and front will reach null and prev will be at head
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *kthNode = findKth(temp, k);
            if (kthNode == NULL)
            {
                if (prev) prev->next = temp;
                 break;
            }
            ListNode* nextnode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if (temp == head)
            {
                head = kthNode;
            }
            else
            {
                prev->next = kthNode;
            }
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};