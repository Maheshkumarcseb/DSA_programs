package DSA_programs.TREE;

import java.util.LinkedList;
import java.util.Queue;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class MaximumLevelSum {
    public int maxLevelSum(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int maxSum = root.val;
        int ans = 1;
        int level = 1;

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode removed = queue.remove();
                levelSum += removed.val;
                if (removed.left != null) queue.add(removed.left);
                if (removed.right != null) queue.add(removed.right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                ans = level;
            }
            level++;
        }

        return ans;
    }

    public static void main(String[] args) {
        // Build a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(7);
        root.right = new TreeNode(0);
        root.left.left = new TreeNode(7);
        root.left.right = new TreeNode(-8);

        // Call the function
        MaximumLevelSum MaximumLevelSumObj = new MaximumLevelSum();
        int result = MaximumLevelSumObj.maxLevelSum(root);

        // Print the result
        System.out.println("The level with the maximum sum is: " + result);
    }
}
