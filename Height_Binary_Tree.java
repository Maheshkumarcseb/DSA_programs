package DSA_programs;

import java.util.LinkedList;
import java.util.Queue;

// Nodee class as given
class Nodee {
    int data;
    Nodee left, right;

    Nodee(int item) {
        data = item;
        left = right = null;
    }
}

class Height_Binary_Tree {
    // Function to find the height of a binary tree
    int height(Nodee Nodee) {
        if (Nodee == null) {
            return -1; // height in terms of edges
        }

        int leftHeight = height(Nodee.left);
        int rightHeight = height(Nodee.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    // Utility function to build tree from level-order input (with 'N' as null)
    public Nodee buildTree(String[] values) {
        if (values.length == 0 || values[0].equals("N")) return null;

        Nodee root = new Nodee(Integer.parseInt(values[0]));
        Queue<Nodee> queue = new LinkedList<>();
        queue.add(root);

        int i = 1;
        while (!queue.isEmpty() && i < values.length) {
            Nodee current = queue.poll();

            // Left child
            if (i < values.length && !values[i].equals("N")) {
                current.left = new Nodee(Integer.parseInt(values[i]));
                queue.add(current.left);
            }
            i++;

            // Right child
            if (i < values.length && !values[i].equals("N")) {
                current.right = new Nodee(Integer.parseInt(values[i]));
                queue.add(current.right);
            }
            i++;
        }

        return root;
    }

    public static void main(String[] args) {
        Height_Binary_Tree obj = new Height_Binary_Tree();

        // Example 1
        String[] input1 = {"12", "8", "18", "5", "11"};
        Nodee root1 = obj.buildTree(input1);
        System.out.println("Height of Tree 1: " + obj.height(root1)); // Output: 2

        // Example 2
        String[] input2 = {"1", "2", "3", "4", "N", "N", "5", "N", "N", "6", "7"};
        Nodee root2 = obj.buildTree(input2);
        System.out.println("Height of Tree 2: " + obj.height(root2)); // Output: 3
    }
}
