/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    Where N is the size of the input array
*/

#include <unordered_map>

long long pairsWithGivenSum(int arr[], int n, int sum)
{
    unordered_map<int, int> mp;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int complement = sum - arr[i];

        if (mp.find(complement) != mp.end())
        {
            ans += mp[complement];
        }

        //Increase the count of arr[i] in the hashmap/dictionary by 1
        mp[arr[i]]++;
    }

    return ans;
}
