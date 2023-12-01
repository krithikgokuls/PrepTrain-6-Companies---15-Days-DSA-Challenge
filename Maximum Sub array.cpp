/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the total number of elements of the array.
*/


vector<int> maximumsumSubarray(vector<int> &arr , int n)
{

	// Declare a variable 'maxSum' and initialize it as minimum integer
        int maxSum = INT_MIN;
    
        // Declare a variable 'localSum' and initialize it as 0
        int localSum = 0;
	
	// Declare and initialize three variables as 'start', 'end' and 'newStart' and initialize them as 0, 0, 0 respectively.
	int start = 0;
	int end = 0;
	int newStart = 0;
	
	// Run a loop i = 0 to 'N' traversing all the elements
	for( int i = 0; i < n; i++)
	{
		// Add the current element to the localSum
		localSum = localSum + arr[i];
		
		// If the 'localSum' is greater than the maxSum update all variables
		if ( localSum > maxSum )
		{
			maxSum = localSum;
			start = newStart;
			end = i;
		}
		else if( localSum == maxSum )
		{
			if( end-start < i - newStart )
			{
				start = newStart;
				end = i;
			}
		}
		if (localSum < 0)
            {
                localSum = 0;
                newStart = i + 1;
            }
	}
	
	
	vector<int> ans;

	for(int i = start; i <= end; i++)
	{
		ans.push_back(arr[i]);
	}
	
	return ans;
}
