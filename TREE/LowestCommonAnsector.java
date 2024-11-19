package DSA_programs.TREE;




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

class LowestCommonAnsector {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Base cases: If root is null, or root matches either p or q, return root
        if (root == null || root == p || root == q)
            return root;

        // Recurse for left and right subtrees
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // If both left and right are non-null, root is the LCA
        if (left != null && right != null)
            return root;

        // Otherwise, return the non-null node
        return left != null ? left : right;
    }

    public static void main(String[] args) {
        // Create a sample binary tree:
        //          3
        //         / \
        //        5   1
        //       / \ / \
        //      6  2 0  8
        //        / \
        //       7   4
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(5);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(6);
        root.left.right = new TreeNode(2);
        root.right.left = new TreeNode(0);
        root.right.right = new TreeNode(8);
        root.left.right.left = new TreeNode(7);
        root.left.right.right = new TreeNode(4);

        // Define nodes for testing
        TreeNode p = root.left;  // Node 5
        TreeNode q = root.left.right.right;  // Node 4

        LowestCommonAnsector LowestCommonAnsectorobj = new LowestCommonAnsector();
        TreeNode lca = LowestCommonAnsectorobj.lowestCommonAncestor(root, p, q);

        // Print the result
        System.out.println("Lowest Common Ancestor of " + p.val + " and " + q.val + " is: " + lca.val);
    }
}
