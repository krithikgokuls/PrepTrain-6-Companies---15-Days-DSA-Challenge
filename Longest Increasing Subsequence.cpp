/*
    Time Complexity : O(N * logN)
    Space Complexity : O(N)
    Where N is the size of the array
*/
#include <algorithm>
int longestIncreasingSubsequence(int arr[], int n)
{
    int dp[n]; // dp[i] represents i+1'th length LIS ending at minimum integer dp[i]
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        /*
            Since dp array stores elements in the sorted order therefore
            we can use binary search to find the correct position for
            arr[i] to be placed.
            And elements are present in the dp array from 0 to ans-1 position
            So we will be doing the binary search in this range.
        */
        int position = lower_bound(dp, dp + ans, arr[i]) - dp;
        dp[position] = arr[i];

        if (position == ans)
        {
            ans++;
        }
    }

    return ans;
}
