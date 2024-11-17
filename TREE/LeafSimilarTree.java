package DSA_programs.TREE;

class MyTreeNode {
    int val;
    MyTreeNode left, right;

    MyTreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

class LeafSimilarTree {
    // Helper function to perform in-order traversal and collect leaf nodes
    public static void inOrder(MyTreeNode root, StringBuilder s) {
        if (root == null) return;

        // Check if the current node is a leaf node
        if (root.left == null && root.right == null) {
            s.append(root.val).append("_");
            return;
        }

        // Traverse left and right subtrees
        inOrder(root.left, s);
        inOrder(root.right, s);
    }

    // Function to check if two trees are leaf-similar
    public boolean leafSimilar(MyTreeNode root1, MyTreeNode root2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        inOrder(root1, s1);
        inOrder(root2, s2);

        // Compare the leaf sequences
        return s1.toString().equals(s2.toString());
    }

    public static void main(String[] args) {
        // Create two sample trees:
        // Tree 1:       3
        //              / \
        //             5   1
        //            / \   \
        //           6   2   9
        MyTreeNode root1 = new MyTreeNode(3);
        root1.left = new MyTreeNode(5);
        root1.right = new MyTreeNode(1);
        root1.left.left = new MyTreeNode(6);
        root1.left.right = new MyTreeNode(2);
        root1.right.right = new MyTreeNode(9);

        // Tree 2:       7
        //              / \
        //             2   1
        //            /     \
        //           6       9
        MyTreeNode root2 = new MyTreeNode(7);
        root2.left = new MyTreeNode(2);
        root2.right = new MyTreeNode(1);
        root2.left.left = new MyTreeNode(6);
        root2.right.right = new MyTreeNode(9);

        LeafSimilarTree leafSimilarTreeObj = new LeafSimilarTree();
        boolean result = leafSimilarTreeObj.leafSimilar(root1, root2);

        System.out.println("Are the trees leaf-similar? " + result);
    }
}
