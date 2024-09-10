package DSA_programs;

import java.util.HashSet;
import java.util.Set;

public class duplicates {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> hashset = new HashSet<>();
        for (int n : nums) {
            if (hashset.contains(n)) {
                return true;
            }
            hashset.add(n);
        }
        return false;
    }

    public static void main(String[] args) {
        duplicates solution = new duplicates();

        // Test case 1: Array with duplicates
        int[] nums1 = {1, 2, 3, 4, 5, 2};
        System.out.println("Array has duplicates: " + solution.hasDuplicate(nums1));

        // Test case 2: Array without duplicates
        int[] nums2 = {1, 2, 3, 4, 5};
        System.out.println("Array has duplicates: " + solution.hasDuplicate(nums2));

        // Test case 3: Empty array
        int[] nums3 = {};
        System.out.println("Array has duplicates: " + solution.hasDuplicate(nums3));

        // Test case 4: Array with single element
        int[] nums4 = {5};
        System.out.println("Array has duplicates: " + solution.hasDuplicate(nums4));
    }
}

