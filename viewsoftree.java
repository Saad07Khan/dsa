import java.util.*;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) 
    { 
        val = x; 
    }
}

class Solution {
    public List<Integer> topView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }

        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        Map<Integer, Integer> mp = new TreeMap<>();
        q.offer(new Pair<>(root, 0));

        while (!q.isEmpty()) {
            Pair<TreeNode, Integer> pair = q.poll();
            TreeNode node = pair.getKey();
            int line = pair.getValue();

            if (!mp.containsKey(line)) {
                mp.put(line, node.val);
            }

            if (node.left != null) {
                q.offer(new Pair<>(node.left, line - 1));
            }
            if (node.right != null) {
                q.offer(new Pair<>(node.right, line + 1));
            }
        }

        for (int val : mp.values()) {
            ans.add(val);
        }
        return ans;
    }

    public void recursion(TreeNode node, List<Integer> ans, int level) {
        if (node == null) {
            return;
        }

        if (ans.size() == level) {
            ans.add(node.val);
        }

        recursion(node.right, ans, level + 1);
        recursion(node.left, ans, level + 1);
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        int level = 0;
        recursion(root, ans, level);
        return ans;
    }
}

public class Main {
    public static TreeNode build(String[] s, int index) {
        if (index >= s.length || s[index].equals("null")) {
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(s[index]));
        root.left = build(s, 2 * index + 1);
        root.right = build(s, 2 * index + 2);
        return root;
    }

    public static void rightview(TreeNode root) {
        Solution solution = new Solution();
        List<Integer> result = solution.rightSideView(root);
        System.out.print("Right side view of the binary tree: ");
        for (int i = 0; i < result.size(); ++i) {
            System.out.print(result.get(i) + " ");
        }
        System.out.println();
    }

    public static void bottomview(TreeNode root) {
        Solution solution = new Solution();
        List<Integer> result = solution.bottomView(root);
        System.out.print("Bottom view of the binary tree: ");
        for (int i = 0; i < result.size(); ++i) {
            System.out.print(result.get(i) + " ");
        }
        System.out.println();
    }

    public static void topview(TreeNode root) {
        Solution solution = new Solution();
        List<Integer> result = solution.topView(root);
        System.out.print("Top view of the binary tree: ");
        for (int i = 0; i < result.size(); ++i) {
            System.out.print(result.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Main ob = new Main();
        System.out.println("Enter the elements of the binary tree (space-separated, 'null' for empty nodes):");
        String s[]=sc.nextLine().split(" ");
        TreeNode root = build(s, 0);
        ob.rightview(root);
        ob.bottomview(root);
        ob.topview(root);
    }
}

    public static TreeNode build(String[] s, int index) {
        if (index >= s.length || s[index].equals("null")) {
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(s[index]));
        root.left = build(s, 2 * index + 1);
        root.right = build(s, 2 * index + 2);
        return root;
    }
    

    TreeNode root = new TreeNode(Integer.parseInt(s[]))
    Class TreeNode
    {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int val)
        {
            data=val;
        }
    }
    String[] s = sc.nextLine().split("");
    Tree Node root=build(s,0);

    public static TreeNode build(String[] s, int index)
    {
        
     }
     sc.nextLine().split("");

     if(index>s.length||s[index].equals("null"))
     {
        return null;
     }

     TreeNode root = new TreeNode(Integer.parseInt(s[index]));
     

