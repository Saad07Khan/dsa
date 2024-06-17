//keep going to next as next will point to next element

#include <iostream>
#include <cstring>
#include <cctype>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
Node* constructLL(vector<int>& arr) {
    
    Node*head = new Node(arr[0]);  //head initialized as first element
    Node*mover = head;            // head always points to first element
    for(int i=1;i<arr.size();i++)
    {
        Node*temp= new Node(arr[i]); // new temp node created with arr[i] values whose next is null
        mover->next=temp;           // next is initialized to temp
        mover=temp;                // mover becomes temp
    }

    return head;                  // return head
}

int main()
{
    vector<int>arr = {12,5,8,7};
    Node* head = constructLL(arr);
    Node* temp=head; // storing head in temp as u cannot let head change while traversing it will be lost
    while(temp)
    {   
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}