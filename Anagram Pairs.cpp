/*
    Time complexity : O(N + M)
    Space complexity : O(1)

    where N and M are the lengths of the two input strings.
*/

#include <vector>

bool isAnagram(string str1, string str2)
{
    // Vector to store the frequency of characters.
    vector<int> freq(26, 0);

    // Storing the frequency of the characters of the first string.
    for (char c : str1)
    {
        ++freq[c - 'a'];
    }

    // Removing the frequency of the characters of the second string.
    for (char c : str2)
    {
        --freq[c - 'a'];
    }

    // Comparing the elements of the frequency vector with zero.
    for (int i : freq)
    {
        if (i != 0)
        {
            return false;
        }
    }

    return true;
}
