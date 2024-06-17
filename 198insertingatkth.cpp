
Node* insertKth(Node* head, int val, int k)
{
    if(head==NULL)
    {
        if(k==1)
        {
            Node*temp= new Node(val); //this type of function since new node should point to null ptr

            return temp;
        }
    }
    if(k==1)
    {
        Node*temp = new Node(val,head);
        return temp;
    }
   int cnt=0; 
    Node*temp = head;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==k-1) //temp should be before the value to be inserted
        {
            Node* x= new Node(val,temp->next); 
            temp->next=x;
            break;

        }
        temp=temp->next;
    }
    return head;
}