import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Solution {
    public void leftBoundary(Node root, List<Integer> res) {
        Node curr = root.left;
        while (curr != null) {
            if (!isLeaf(curr))
                res.add(curr.data);
            if (curr.left != null)
                curr = curr.left;
            else
                curr = curr.right;
        }
    }

    public void rightBoundary(Node root, List<Integer> res) {
        List<Integer> temp = new ArrayList<>();

        Node curr = root.right;
        while (curr != null) {
            if (!isLeaf(curr))
                temp.add(curr.data);
            if (curr.right != null)
                curr = curr.right;
            else
                curr = curr.left;
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            res.add(temp.get(i));
        }
    }

    public void leafTraversal(Node root, List<Integer> res) {
        if (isLeaf(root)) {
            res.add(root.data);
            return;
        }

        if (root.left != null)
            leafTraversal(root.left, res);
        if (root.right != null)
            leafTraversal(root.right, res);
    }

    public boolean isLeaf(Node root) {
        return root.left == null && root.right == null;
    }

    public List<Integer> boundary(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;
        if (!isLeaf(root))
            res.add(root.data);
        leftBoundary(root, res);
        leafTraversal(root, res);
        rightBoundary(root, res);
        return res;
    }
}

public class Main {
    public static Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        } else {
            Node temp;
            if (data <= root.data) {
                temp = insert(root.left, data);
                root.left = temp;
            } else {
                temp = insert(root.right, data);
                root.right = temp;
            }
            return root;
        }
    }

    public static void printBoundary(Node root) {
        Solution solution = new Solution();
        List<Integer> result = solution.boundary(root);
        System.out.println("Boundary of the binary tree: ");
        for (int i = 0; i < result.size(); ++i) {
            System.out.print(result.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Node root = null;
        int input = sc.nextInt();
        while (input >= 0) {
            root = insert(root, input);
            input = sc.nextInt();
        }
        printBoundary(root);
    }
}
