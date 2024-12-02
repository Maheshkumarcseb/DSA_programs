package DSA_programs.TREE;
import java.util.LinkedList;
import java.util.Queue;

// Definition of treenode
class treenode {
    int val;
    treenode left;
    treenode right;
    
    treenode(int val) {
        this.val = val;
    }
}

class InvertBinaryTree {
    // Method to invert the binary tree
    public treenode invertTree(treenode root) {
        if (root == null) 
            return null;
        
        final Queue<treenode> queue = new LinkedList<>();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            final treenode node = queue.poll();
            
            // Swap the left and right children
            final treenode temp = node.left;
            node.left = node.right;
            node.right = temp;
            
            // Add children to the queue if they are not null
            if (node.left != null) 
                queue.add(node.left);
            if (node.right != null) 
                queue.add(node.right);
        }
        return root;
    }

    // Helper method to print the tree in level order for verification
    public void printTree(treenode root) {
        if (root == null) {
            System.out.println("Tree is empty");
            return;
        }
        
        Queue<treenode> queue = new LinkedList<>();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            treenode current = queue.poll();
            System.out.print(current.val + " ");
            
            if (current.left != null) 
                queue.add(current.left);
            if (current.right != null) 
                queue.add(current.right);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        InvertBinaryTree InvertBinaryTreeobj = new InvertBinaryTree();
        
        // Creating a sample tree: 
        //       4
        //      / \
        //     2   7
        //    / \ / \
        //   1  3 6  9
        treenode root = new treenode(4);
        root.left = new treenode(2);
        root.right = new treenode(7);
        root.left.left = new treenode(1);
        root.left.right = new treenode(3);
        root.right.left = new treenode(6);
        root.right.right = new treenode(9);

        System.out.println("Original tree (level order):");
        InvertBinaryTreeobj.printTree(root);

        // Inverting the tree
        treenode invertedRoot = InvertBinaryTreeobj.invertTree(root);

        System.out.println("Inverted tree (level order):");
        InvertBinaryTreeobj.printTree(invertedRoot);
    }
}
