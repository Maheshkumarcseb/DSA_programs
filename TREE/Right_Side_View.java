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

class Right_Side_View {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        rightView(root, result, 0);
        return result;
    }

    public void rightView(TreeNode curr, List<Integer> result, int currDepth) {
        if (curr == null)
            return;
        if (currDepth == result.size())
            result.add(curr.val);
        rightView(curr.right, result, currDepth + 1);
        rightView(curr.left, result, currDepth + 1);
    }

    public static void main(String[] args) {
        // Create a sample tree:
        //        1
        //       / \
        //      2   3
        //       \    \
        //        5    4
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(5);
        root.right.right = new TreeNode(4);

        Right_Side_View RightSideViewobj = new Right_Side_View();
        List<Integer> result = RightSideViewobj.rightSideView(root);
        
        // Print the result
        System.out.println("Right side view of the tree: " + result);
    }
}
