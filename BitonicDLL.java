import java.util.*;

class bitonicdll {
    static class Node {
        int data;
        Node next;
        Node prev;

        public Node(int data1, Node next1, Node back1) {
            data = data1;
            next = next1;
            prev = back1;
        }

        public Node(int data1) {
            data = data1;
            next = null;
            prev = null;
        }
    }

    static Node sort(Node head) {
        if (head == null || head.next == null)
            return head;
        Node front = head;
        Node last = head;
        Node res = new Node(Integer.MIN_VALUE, null, null);
        Node resend = res;
        Node next;
        while (last.next != null)
            last = last.next;
        while (front != last) {
            if (last.data <= front.data) {
                resend.next = last;
                next = last.prev;
                last.prev.next = null;
                last.prev = resend;
                last = next;
                resend = resend.next;
            } else {
                resend.next = front;
                next = front.next;
                front.next = null;
                front.prev = resend;
                front = next;
                resend = resend.next;
            }
        }
        resend.next = front;
        front.prev = resend;
        return res.next;
    }

    private static Node convertArr2DLL(int[] arr) {
        if (arr.length == 0) {
            return null;
        }

     
        Node head = new Node(arr[0]);
     
        Node prev = head;

        for (int i = 1; i < arr.length; i++) {
         
            Node temp = new Node(arr[i], null, prev);
         
            prev.next = temp;
         
            prev = temp;
        }

        return head;
    }
    private static void printlist(Node head) {
        if (head == null)
            System.out.print("Doubly Linked list is empty");
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            arr[i] = m;
        }
        Node head = convertArr2DLL(arr);
        head = sort(head);
        System.out.println("After sorting:");
        printlist(head);
    }
}


