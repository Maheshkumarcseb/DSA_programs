package DSA_programs.TREE;

class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int data) {
        this.data = data;
        left = right = null;
    }
}

class MaximumDepth {
    // Function to calculate the maximum depth of the binary tree
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);

        return 1 + Math.max(leftDepth, rightDepth);
    }

    public static void main(String[] args) {
        // Creating a sample binary tree:
        //         1
        //        / \
        //       2   3
        //      / \
        //     4   5

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        MaximumDepth MaximumDepthobj = new MaximumDepth();
        int depth = MaximumDepthobj.maxDepth(root);
        System.out.println("Maximum Depth of the Tree: " + depth);
    }
}
