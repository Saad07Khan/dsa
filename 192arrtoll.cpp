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
}

class Node{
    public:
    int data;
    Node*next;

    public:
    Node(int data1, Node* next1)
    {
        data=data1;
        next=next1;
    }


}
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

