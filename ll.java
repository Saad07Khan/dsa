class ll
{
    static class Node
    {
        int data;
        Node next;

        public Node(int data1)
        {
            data=data1;
            next=null;  
        }

        // public Node(int data, Node next1)
        // {
        //     data=data1;
        //     next=next1;
        // }
    }



    void print(Node head)
    {
        Node temp= head;
        while(temp!=NULL)
        {
            System.out.println(temp.data);
            temp=temp.next;
        }
    }
}







