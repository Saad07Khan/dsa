import java.util.*;
class priority {
    static class Node {
        int data;
        int priority;
        Node next, prev;
        public Node(int data, int priority) {
            this.data = data;
            this.priority = priority;
        }
    }
    private static Node head = null;
    private static void push(int data, int priority) {
        if (head == null) {
            Node newNode = new Node(data, priority);
            head = newNode;
            return; 
            }
        Node node = new Node(data, priority);
        Node temp = head, parent = null;
        while (temp != null && temp.priority >= priority) {
            parent = temp;
            temp = temp.next;
        }
        if (parent == null) {
           
            node.next = head;
            head.prev = node;
            head = node;
        } 
        else if (temp == null) {
            parent.next = node;
            node.prev = parent;
        }
else {
            parent.next = node;
            node.prev = parent;
            node.next = temp;
            temp.prev = node;
        }  
        }
    private static int peek() {
        if (head != null) {
            return head.data;
        }
        return -1;
    }
    private static int pop() {
        if (head != null) {
            int curr = head.data;
            head = head.next;
          if (head != null) {
                head.prev = null;
            }  return curr;
        }
        return -1;  
 }
public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            int data=sc.nextInt();
            int pri=sc.nextInt();
            push(data, pri);
        }
        System.out.println(peek());
        System.out.println(pop());
        System.out.println(pop());
        System.out.println(peek());
    }
}


class doublell
{
    static class Node
    {
        int data;
        Node next;
        Node prev;



        public Node(int data1, Node next1, Node prev1)
        {
            data=data1;
            next=next1;
            prev=prev1;
        }

        public Node(int data1)
        {
            data=data1;
            next=null;
            prev=null;
        }
    }


    public static Node convertArr2DLL(int arr[])
    {
        int n=arr.length;
        Node head= newNode(arr[0]);
        Node prev=head;
        for(int i=1;i<n;i++)
        {
            Node temp= newNode(arr[i],null,head);
            prev=temp;

        }

        return head;
    }
}