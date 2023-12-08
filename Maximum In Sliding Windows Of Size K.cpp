/*
    Time Complexity = O(N)
    Space Complexity = O(N)

    Where N is the number of elements in the given array/list.
*/

#include <deque>

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{

    //    Create a Double Ended Queue of capacity K.
    deque<int> window(k);

    int n = nums.size();

    vector<int> result;

    //    For the first window.
    for (int i = 0; i < k; i++)
    {

        //    For every element, the previous smaller elements are of no use so remove them from q.
        while ((!window.empty()) && nums[i] >= nums[window.back()])
        {
            //    Remove from rear
            window.pop_back();
        }

        //    Add new element at rear of queue.
        window.push_back(i);
    }

    //    For rest of the elements from nums[k] to nums[n-1]
    for (int i = k; i < n; i++)
    {

        //    The element at the front of the queue is the largest element of previous window, so add it to the result.
        result.push_back(nums[window.front()]);

        //    Remove the elements which are out of this window
        while ((!window.empty()) && window.front() <= i - k)
        {
            //    Remove from front of queue
            window.pop_front();
        }

        //    Remove all elements smaller than the currently being added element.
        while ((!window.empty()) && nums[i] >= nums[window.back()])
        {
            window.pop_back();
        }

        //    Add current element at the rear of queue.
        window.push_back(i);
    }

    //    Add the maximum element of the last window.
    result.push_back(nums[window.front()]);

    return result;
}
