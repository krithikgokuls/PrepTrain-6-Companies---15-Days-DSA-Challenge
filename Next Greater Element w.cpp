/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the array.
*/

#include <stack>

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    // Create a vetor to store next Greater elements
    vector<int> ans(n);

    // Stack, to keep track of next greater element
    stack<int> s;

    // Traverse in reverse fashion in the array
    for (int i = n - 1; i >= 0; i--)
    {
        //If current element is greater than or equal to stack's top
        //element, we can pop it since now it will never get picked
        //as the next greater element
        while (!s.empty() && arr[i] >= s.top())
        {
            s.pop();
        }

        //If stack is not empty, stack's top element is
        //the next greater element, else there is none
        if (!s.empty())
        {
            ans[i] = s.top();
        }
        else
        {
            ans[i] = -1;
        }

        // Push current element onto stack
        s.push(arr[i]);
    }

    // return final answer vector
    return ans;
}
