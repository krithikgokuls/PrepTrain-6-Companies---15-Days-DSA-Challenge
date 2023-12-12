/*
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where 'N' is the length of the given permutation.
*/

vector<int> nextPermutation(vector<int> &permutation, int n)
{

    // Start iterating from the end of the given permutation.
    for (int i = n - 2; i >= 0; i--)
    {

        if (permutation[i] < permutation[i + 1])
        {
            // Decreasing element found.

            // To store the index of just greater element.
            int id = n - 1;

            // Iterating to find the just greater element.
            for (int j = i + 1; j < n; j++)
            {
                if (permutation[j] < permutation[i])
                {
                    // Element found.
                    id = j - 1;
                    break;
                }
            }

            // Swap the ith and element at index 'id'.
            swap(permutation[i], permutation[id]);

            // Reverse rest of the elements.
            for (int j = 0; j < (n - i) / 2; j++)
            {
                swap(permutation[i + 1 + j], permutation[n - 1 - j]);
            }

            return permutation;
        }
    }

    // Next greater permuation doesn't exists. So, return the smallest one.
    for (int i = 0; i < n; i++)
    {
        permutation[i] = i + 1;
    }

    return permutation;
}
