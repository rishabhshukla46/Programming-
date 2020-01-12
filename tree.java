import java.util.ArrayList;

public class tree{
    public static void main(String[] args){
        final int[] arr = {10, 20, 30, -1, -1, 40, -1, -1, 50, 60, 80, -1, -1, -1, 70, 90, -1, 100, -1, -1, -1 };
        final Node root = create(arr);
        //display(root);
        //System.out.println("Height of this tree is "+ height(root));
        //System.out.println("Size of this tree is "+ size(root));
        //System.out.println(find(root, 60));
        //ArrayList<Node> ans = Roottonode(root, 60);
        //for(Node n : ans){
        //    System.out.println(n.data);
        //}



    }
//==============================create a tree========================================
    //declare a node
    public static class Node{
        int data = 0;
        Node left = null;
        Node right = null;

        Node(final int data, final Node left, final Node right){
            this.data = data;
            this.left = left;
            this.right = right;
        }
        Node(){

        }
    }
    //create a tree
    static int idx = 0;
    public static Node create(int[] arr){
        if(arr[idx] == arr.length || arr[idx] == -1){
            idx++;
            return null;
        }
        final Node nnode = new Node(arr[idx], null, null);
        idx++;
        nnode.left = create(arr);
        nnode.right = create(arr);

        return nnode;
    }
    //display a tree
    public static void display(Node node){
        if(node == null)
            return;
        
        String str = "";

        str += node.left == null ? "." : node.left.data;
        str += "<--" + node.data + "-->";
        str += node.right == null ? "." : node.right.data;
        System.out.println(str);
        display(node.left);
        display(node.right);
    }
   
//===============================basic tree attributes===============================

    public static int height(Node node){
        if(node == null)
            return 0;

        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public static int size(Node node){
        if(node == null)
            return 0;
        
        return size(node.left) + size(node.right) + 1;
    }

    public static boolean find(Node node, int data){
        if(node == null)
            return false;
        if(node.data == data)
            return true;
        boolean res = false;
        res = res || find(node.left, data);
        res = res || find(node.right, data);
        return res;
    }

//==============================Paths in tree=========================================

    public static ArrayList<Node> Roottonode(Node node, int data){
        if(node == null)
            return null;
        
        if(node.data == data){
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }

        ArrayList<Node> left = Roottonode(node.left, data);
        if(left != null){
            left.add(node);
            return left;
        }
        ArrayList<Node> right = Roottonode(node.right, data);
        if(right != null){
            right.add(node);
            return right;
        }

        return null;
    }
}

