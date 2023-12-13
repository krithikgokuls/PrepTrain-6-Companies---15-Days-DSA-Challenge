/*
    Time Complexity: O(min(log N, log M))
    Space Complexity: O(1)

    Where 'N' & 'M' are the sizes of the arrays.
*/

import java.util.Arrays;

public class Solution 
{

    public static double median(int[] a, int[] b) 
    {
        if(a.length > b.length) 
        {
            return medianHelper(b, a);
        }

        return medianHelper(a, b);
    }

    // Function to find median.
    public static double medianHelper(int[] a, int[] b) 
    {
        int n = a.length, m = b.length;
        int low = 0, high = n;

        // Binary search.
        while(low <= high) 
        {
            int mid = (low + high) / 2;
            int part = (n + m + 1) / 2 - mid;

            // If part is greater than m
            if(part > m) 
            {
                low = mid + 1;
                continue;
            }

            int leftMax = 0, rightMin = 1000000001;
            
            if(mid > 0) 
            {
                leftMax = Math.max(leftMax, a[mid-1]);
            }

            if(part > 0) 
            {
                leftMax = Math.max(leftMax, b[part-1]);
            }

            if(mid < n) 
            {
                rightMin = Math.min(rightMin, a[mid]);
            }

            if(part < m) 
            {
                rightMin = Math.min(rightMin, b[part]);
            }

            // If leftMax is less than or greater than rightMin
            if(leftMax <= rightMin) 
            {
                if(((n + m) & 1) == 1) 
                {
                    return leftMax;
                }
                
                return (leftMax + rightMin) / 2.0;
            }

            // If a[mid] is less than leftMax
            if(a[mid] < leftMax) 
            {
                low = mid + 1;
            }
            else 
            {
                high = mid - 1;
            }
        }

        return -1;
    }

}
