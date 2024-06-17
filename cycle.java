import java.util.*;

class cycle
{
    static class Node
    {
        int data;
        Node next;

        public Node(int data1, Node next1)
        {
            data=data1;
            next1=next;
        }

        public Node(int data1)
        {
            data=data1;
            next=null;
        }
        
    }


    public static Node convertArr2DLL(int[] arr)
    {
        Node head= new Node(arr[0]);
        Node ptr= head;
        for(int i=0;i<arr.length;i++)
        {
            Node temp= new Node(arr[i]);
            ptr.next=temp;
            ptr=temp;
        }

        return head;
    }

    public static boolean detectLoop(Node head)
    {
        Node slow=head;
        Node fast=head;
        while(fast!=null && fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
            if(slow==fast)
            {
                return true;
            }


        }
        return false;

    }


    public static void main(String[] args)
    {
        Scanner sc= new Scanner(System.in);
        int n= sc.nextInt();
        int arr[]= new int[n];
        for(int i=0;i<n;i++)
        {
            int m= sc.nextInt();
            arr[i]=m;
        }
        Node head = convertArr2DLL(arr);
        if(detectLoop(head)==true)
        {
            System.out.println("loop exists");
        }
        else
        {
            System.out.println("loop no exists");
        }
    }
}