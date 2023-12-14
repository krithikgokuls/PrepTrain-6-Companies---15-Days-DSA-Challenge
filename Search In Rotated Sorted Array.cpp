/*
    Time complexity : O(log(N))
    Space complextiy : O(1)

    where N is the size of the input array
*/

int search(int* arr, int n, int key)
{
    
    // Initialize start and end
    int st = 0, end = n - 1;

    // Performing binary search
    while (st <= end)
    {
        
        // Get the middle element
        int mid = st + (end - st) / 2;

        // The middle element is the one we are searching for
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] >= arr[st])
        {
            
            // Element lies towards left of mid
            if (arr[st] <= key && key <= arr[mid])
            {
                end = mid - 1;
            }
            
            // Element lies towards right of mid    
            else
            {
                st = mid + 1;
            }
        }
        
        else
        {
            
            // Element lies towards right of mid
            if (arr[end] >= key && key >= arr[mid])
            {
                st = mid + 1;
            }
            
            // Element lies towards left of mid
            else
            {
                end = mid - 1;
            }
        }
    }
    
    // Element not found
    return -1;
}
