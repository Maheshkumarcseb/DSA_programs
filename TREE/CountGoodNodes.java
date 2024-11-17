package DSA_programs.TREE;

class MyTreeNode {
    int val;
    MyTreeNode left, right;

    MyTreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

class CountGoodNodes {
    // Main function to count good nodes
    public int goodNodes(MyTreeNode root) {
        return helper(root, Integer.MIN_VALUE);
    }

    // Helper function to traverse the tree
    private int helper(MyTreeNode root, int curMax) {
        if (root == null)
            return 0;

        int rootAnswer = 0;
        // Check if the current node is a good node
        if (root.val >= curMax) {
            rootAnswer = 1;
            curMax = root.val; // Update the maximum value seen so far
        }

        // Recursively count good nodes in the left and right subtrees
        int leftCount = helper(root.left, curMax);
        int rightCount = helper(root.right, curMax);

        // Return the total count of good nodes
        return leftCount + rightCount + rootAnswer;
    }

    public static void main(String[] args) {
        // Create a sample tree:
        //        3
        //       / \
        //      1   4
        //     /   / \
        //    3   1   5
        MyTreeNode root = new MyTreeNode(3);
        root.left = new MyTreeNode(1);
        root.right = new MyTreeNode(4);
        root.left.left = new MyTreeNode(3);
        root.right.left = new MyTreeNode(1);
        root.right.right = new MyTreeNode(5);

        CountGoodNodes countGoodNodesObj = new CountGoodNodes();
        int result = countGoodNodesObj.goodNodes(root);
                                                        
        System.out.println("Number of good nodes: " + result);
    }
}
