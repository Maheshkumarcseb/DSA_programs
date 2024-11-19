package DSA_programs.TREE;
import java.util.*;

// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class LongestZigzagPath{
    private int maxZigZag = 0; // Global variable to track the longest zigzag path

    public int longestZigZag(TreeNode root) {
        if (root == null) return 0;
        dfs(root, true, 0);  // Start DFS assuming a left direction
        dfs(root, false, 0); // Start DFS assuming a right direction
        return maxZigZag;    // Return the global maximum
    }

    private void dfs(TreeNode node, boolean isLeftDirection, int length) {
        if (node == null) return;

        // Update the global maximum if the current length is greater
        maxZigZag = Math.max(maxZigZag, length);

        // Recurse in zigzag fashion
        if (isLeftDirection) {
            dfs(node.left, false, length + 1); // Move left and alternate direction
            dfs(node.right, true, 1);          // Restart path on right
        } else {
            dfs(node.right, true, length + 1); // Move right and alternate direction
            dfs(node.left, false, 1);          // Restart path on left
        }
    }

    public static void main(String[] args) {
        // Create a sample binary tree:
        //          1
        //         / \
        //        2   3
        //         \    \
        //          4    5
        //         / \
        //        6   7
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(5);
        root.left.right.left = new TreeNode(6);
        root.left.right.right = new TreeNode(7);

        LongestZigzagPath LongestZigzagPathobj = new LongestZigzagPath();
        int result = LongestZigzagPathobj.longestZigZag(root);

        // Print the result
        System.out.println("Longest ZigZag path length: " + result);
    }
}
