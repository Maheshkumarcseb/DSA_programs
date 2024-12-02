package DSA_programs.TREE;
import java.util.LinkedList;
import java.util.Queue;

class Treenode {
    int val;
    Treenode left;
    Treenode right;
    
    Treenode(int val) {
        this.val = val;
    }
}

class SameTree {
    public boolean isSameTree(Treenode root1, Treenode root2) {
        Queue<Treenode> queue = new LinkedList<>();
        queue.add(root1);
        queue.add(root2);
        
        while (!queue.isEmpty()) {
            Treenode first = queue.poll();
            Treenode second = queue.poll();
            
            if (first == null && second == null) 
                continue;
            if (first == null || second == null || first.val != second.val) 
                return false;
            
            queue.add(first.left);
            queue.add(second.left);
            queue.add(first.right);
            queue.add(second.right);
        }
        return true;
    }

    public static void main(String[] args) {
        SameTree solution = new SameTree();
        
        // Create first tree: 1 -> 2, 3
        Treenode root1 = new Treenode(1);
        root1.left = new Treenode(2);
        root1.right = new Treenode(3);
        
        // Create second tree: 1 -> 2, 3
        Treenode root2 = new Treenode(1);
        root2.left = new Treenode(2);
        root2.right = new Treenode(3);
        
        // Test the function
        boolean result = solution.isSameTree(root1, root2);
        System.out.println("Are the trees the same? " + result);  // Expected output: true
        
        // Create third tree: 1 -> 2, null
        Treenode root3 = new Treenode(1);
        root3.left = new Treenode(2);
        
        // Create fourth tree: 1 -> null, 2
        Treenode root4 = new Treenode(1);
        root4.right = new Treenode(2);
        
        // Test the function with different trees
        result = solution.isSameTree(root3, root4);
        System.out.println("Are the trees the same? " + result);  // Expected output: false
    }
}
