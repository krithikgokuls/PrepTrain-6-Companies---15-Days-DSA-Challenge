/*  
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the length of the given array.
*/

import java.util.HashSet;

public class Solution {
    public static int lengthOfLongestConsecutiveSequence(int[] arr, int N) {
        // To store length of longest consecutive sequence.
        int mx = 0;

        // To store the length of current consecutive Sequence.
        int count = 0;

        // To store all the unique elements of array.
        HashSet<Integer> set = new HashSet<>();

        for (Integer element : arr) {
            set.add(element);
        }

        for (Integer element : arr) {
            int previousConsecutiveElement = element - 1;

            if (!set.contains(previousConsecutiveElement)) {

                // Element is the first value of consecutive sequence.
                int j = element;
                
                while (set.contains(j)) {
                    // The next consecutive element by will be j + 1.
                    j++;
                }

                // Update maximum length of consecutive sequence.
                mx = Math.max(mx, j - element);
            }

        }

        return mx;
    }
}
