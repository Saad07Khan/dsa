//delete tail
Node *deleteLast(Node *head){
    if(head==NULL || head->next==NULL) return NULL;
    Node*temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;

    return head;

}

//delete head
Node *deletehead(Node *head)
{
    if(head==NULL)return head;
    Node*temp = head;
    head=head->next;
    delete temp;
    return head;
}